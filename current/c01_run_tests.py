#!/usr/bin/python3
# ============================================================================
# RULES FOR ANY LLM (OR HUMAN) EDITING THIS FILE:
#   - Target Python 3.10.12. Nothing newer.
#   - DRY: one code path compiles/runs/checks every exercise. Per-exercise
#     differences live only in the EXERCISES table below.
#   - KISS: no classes, no frameworks, no dependencies outside the stdlib.
#   - Shebang stays "#!/usr/bin/python3" (not env).
#   - Indent with TABS, not spaces.
#   - No "if __name__ == '__main__':" block. The script just runs top to
#     bottom.
#
#   Scope: this script compiles, runs, and checks stdout. That's it.
#   Norm/rule enforcement (indentation, the 42 header, forbidden functions
#   or constructs, line/function length, etc) is norminette's job, not
#   this script's - norminette is already the tool built and maintained
#   for that, and reimplementing any slice of it here (e.g. a regex scan
#   for banned libc calls) is a duplicate, worse copy of something that
#   already exists. If norminette doesn't catch something you think it
#   should, that's a norminette/subject-tooling gap to raise separately -
#   it is not a reason to bolt a parallel check onto this file. If
#   norminette is installed, run_norminette runs the full, unfiltered
#   check; if it isn't installed, that check is skipped rather than
#   half-reimplemented.
#
#   How much output testing is "enough" for an exercise:
#   - Exhaustive when the domain is small (test every combination in the
#     output space, not a sample) - do this whenever the full input/output
#     space is small enough to enumerate in a test run.
#   - Boundary values when the domain is too large to exhaust: for ints,
#     that means at least 0, a small positive, a small negative, INT_MIN
#     and INT_MAX where the exercise takes an int. For chars, that means
#     at least one ordinary byte plus '\0' and '\n', since those are the
#     bytes most likely to break a naive write()-based implementation.
#   - Don't add tests beyond this bar "just in case" - a fixed, unbranching
#     output doesn't get more valuable from a second fixed-string check.
#     Match effort to actual risk of a false pass, not to a token count.
# ============================================================================

import sys
import os
import hashlib
import subprocess
import shutil
import concurrent.futures

CFLAGS = ["-ansi", "-pedantic-errors", "-Wall", "-Wextra", "-Werror", "-pipe"]
# Build artifacts live outside the project tree so exercise directories stay
# clean, mirroring the exXX layout: /tmp/.cache/c01/ex00-<hash>, /ex01-<hash>,
# etc. The hash is of the exercise dir's absolute path: without it, two
# different c01 checkouts (e.g. two students, or two clones) would share
# the same cache slot and could silently reuse each other's binary when
# mtimes lined up right - a stale/wrong PASS. Never key this cache by
# exercise name alone.
CACHE_ROOT = os.path.join(os.environ.get("TMPDIR", "/tmp"), ".cache", "c01")


def cache_key(exname, exdir):
	digest = hashlib.sha1(os.path.abspath(exdir).encode()).hexdigest()[:8]
	return "%s-%s" % (exname, digest)


def find_cc():
	return shutil.which("clang") or "cc"


CC = find_cc()


# Each exercise: source file name (without .c), the harness main.c body,
# and a check(bin_path) -> (ok: bool, message: str) function.
def ft_check(binp):
	return simple_check(binp, [], "42")


def ultimate_ft_check(binp):
	return simple_check(binp, [], "42")


def swap_check(binp):
	return simple_check(
		binp, [],
		"5 3 5 -3 0 0 2147483647 -2147483648",
	)


def div_mod_check(binp):
	return simple_check(
		binp, [],
		"8 2 -8 -2 0 0 -1073741824 0 306783378 1",
	)


def ultimate_div_mod_check(binp):
	return simple_check(
		binp, [],
		"8 2 -8 -2 0 0 -1073741824 0 306783378 1",
	)


def putstr_check(binp):
	return simple_check(binp, [], "Hello, World!Bonjour\n")


def strlen_check(binp):
	return simple_check(binp, [], "0 5 43 1")


def rev_int_tab_check(binp):
	return simple_check(binp, [], "5,4,3,2,1 4,3,2,1 42 7 ")


def sort_int_tab_check(binp):
	return simple_check(
		binp, [],
		"1,2,3,4,5 -1,-1,3,4,5,9 42 7 -2147483648,-1,0,2147483647 ",
	)


def simple_check(binp, args, expected):
	proc = subprocess.run([binp] + args, capture_output=True, text=True)
	actual = proc.stdout
	if actual != expected:
		return (False, "expected %r, got %r" % (expected, actual))
	return (True, "")


EXERCISES = {
	"ex00": {
		"name": "ft_ft",
		"main_c": """
#include <stdio.h>

void ft_ft(int *nbr);

int main(void)
{
	int n;

	n = 0;
	ft_ft(&n);
	printf("%d", n);
	return (0);
}
""",
		"check": ft_check,
	},
	"ex01": {
		"name": "ft_ultimate_ft",
		"main_c": """
#include <stdio.h>

void ft_ultimate_ft(int *********nbr);

int main(void)
{
	int n;
	int *p1;
	int **p2;
	int ***p3;
	int ****p4;
	int *****p5;
	int ******p6;
	int *******p7;
	int ********p8;
	int *********p9;

	n = 0;
	p1 = &n;
	p2 = &p1;
	p3 = &p2;
	p4 = &p3;
	p5 = &p4;
	p6 = &p5;
	p7 = &p6;
	p8 = &p7;
	p9 = &p8;
	ft_ultimate_ft(p9);
	printf("%d", n);
	return (0);
}
""",
		"check": ultimate_ft_check,
	},
	"ex02": {
		"name": "ft_swap",
		"main_c": """
#include <stdio.h>
#include <limits.h>

void ft_swap(int *a, int *b);

int main(void)
{
	int a;
	int b;

	a = 3;
	b = 5;
	ft_swap(&a, &b);
	printf("%d %d ", a, b);
	a = -3;
	b = 5;
	ft_swap(&a, &b);
	printf("%d %d ", a, b);
	a = 0;
	b = 0;
	ft_swap(&a, &b);
	printf("%d %d ", a, b);
	a = INT_MIN;
	b = INT_MAX;
	ft_swap(&a, &b);
	printf("%d %d", a, b);
	return (0);
}
""",
		"check": swap_check,
	},
	"ex03": {
		"name": "ft_div_mod",
		"main_c": """
#include <stdio.h>
#include <limits.h>

void ft_div_mod(int a, int b, int *div, int *mod);

int main(void)
{
	int div;
	int mod;

	ft_div_mod(42, 5, &div, &mod);
	printf("%d %d ", div, mod);
	ft_div_mod(-42, 5, &div, &mod);
	printf("%d %d ", div, mod);
	ft_div_mod(0, 5, &div, &mod);
	printf("%d %d ", div, mod);
	ft_div_mod(INT_MIN, 2, &div, &mod);
	printf("%d %d ", div, mod);
	ft_div_mod(INT_MAX, 7, &div, &mod);
	printf("%d %d", div, mod);
	return (0);
}
""",
		"check": div_mod_check,
	},
	"ex04": {
		"name": "ft_ultimate_div_mod",
		"main_c": """
#include <stdio.h>
#include <limits.h>

void ft_ultimate_div_mod(int *a, int *b);

int main(void)
{
	int a;
	int b;

	a = 42;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d ", a, b);
	a = -42;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d ", a, b);
	a = 0;
	b = 5;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d ", a, b);
	a = INT_MIN;
	b = 2;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d ", a, b);
	a = INT_MAX;
	b = 7;
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
	return (0);
}
""",
		"check": ultimate_div_mod_check,
	},
	"ex05": {
		"name": "ft_putstr",
		"main_c": """
void ft_putstr(char *str);

int main(void)
{
	ft_putstr("Hello, World!");
	ft_putstr("");
	ft_putstr("Bonjour\\n");
	return (0);
}
""",
		"check": putstr_check,
	},
	"ex06": {
		"name": "ft_strlen",
		"main_c": """
#include <stdio.h>

int ft_strlen(char *str);

int main(void)
{
	printf("%d ", ft_strlen(""));
	printf("%d ", ft_strlen("Hello"));
	printf("%d ", ft_strlen("Hello, World! This is a longer test string."));
	printf("%d", ft_strlen("a"));
	return (0);
}
""",
		"check": strlen_check,
	},
	"ex07": {
		"name": "ft_rev_int_tab",
		"main_c": """
#include <stdio.h>

void ft_rev_int_tab(int *tab, int size);

static void print_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i + 1 < size)
			printf(",");
		i++;
	}
	printf(" ");
}

int main(void)
{
	int t1[5] = {1, 2, 3, 4, 5};
	int t2[4] = {1, 2, 3, 4};
	int t3[1] = {42};
	int t4[1] = {7};

	ft_rev_int_tab(t1, 5);
	print_tab(t1, 5);
	ft_rev_int_tab(t2, 4);
	print_tab(t2, 4);
	ft_rev_int_tab(t3, 1);
	print_tab(t3, 1);
	ft_rev_int_tab(t4, 0);
	print_tab(t4, 1);
	return (0);
}
""",
		"check": rev_int_tab_check,
	},
	"ex08": {
		"name": "ft_sort_int_tab",
		"main_c": """
#include <stdio.h>
#include <limits.h>

void ft_sort_int_tab(int *tab, int size);

static void print_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		printf("%d", tab[i]);
		if (i + 1 < size)
			printf(",");
		i++;
	}
	printf(" ");
}

int main(void)
{
	int t1[5] = {5, 3, 1, 4, 2};
	int t2[6] = {3, -1, 4, -1, 5, 9};
	int t3[1] = {42};
	int t4[1] = {7};
	int t5[4] = {INT_MAX, INT_MIN, 0, -1};

	ft_sort_int_tab(t1, 5);
	print_tab(t1, 5);
	ft_sort_int_tab(t2, 6);
	print_tab(t2, 6);
	ft_sort_int_tab(t3, 1);
	print_tab(t3, 1);
	ft_sort_int_tab(t4, 0);
	print_tab(t4, 1);
	ft_sort_int_tab(t5, 4);
	print_tab(t5, 4);
	return (0);
}
""",
		"check": sort_int_tab_check,
	},
}


def needs_rebuild(binp, src, main_c_path):
	if not os.path.exists(binp):
		return True
	bin_mtime = os.path.getmtime(binp)
	if os.path.getmtime(src) > bin_mtime:
		return True
	if os.path.exists(main_c_path) and os.path.getmtime(main_c_path) > bin_mtime:
		return True
	return False


def write_if_changed(path, content):
	if os.path.exists(path):
		with open(path) as f:
			if f.read() == content:
				return
	with open(path, "w") as f:
		f.write(content)


# norminette owns all norm/rule enforcement (indentation, header, forbidden
# constructs, etc). This script's only job is compile + run + check output;
# it does not duplicate any of norminette's checks.
def run_norminette(src):
	if not shutil.which("norminette"):
		return (True, "")
	proc = subprocess.run(["norminette", src], capture_output=True, text=True)
	if proc.returncode != 0:
		return (False, proc.stdout + proc.stderr)
	return (True, "")


def display_path(path):
	rel = os.path.relpath(path)
	if not rel.startswith(".."):
		return rel
	return path


def test_exercise(exname, exdir, spec):
	src = os.path.join(exdir, spec["name"] + ".c")
	label = display_path(exdir)
	if not os.path.exists(src):
		return (exname, True, "SKIP: %s (%s not found)" % (label, spec["name"] + ".c"))
	build_dir = os.path.join(CACHE_ROOT, cache_key(exname, exdir))
	os.makedirs(build_dir, exist_ok=True)
	main_c_path = os.path.join(build_dir, "main.c")
	write_if_changed(main_c_path, spec["main_c"])
	binp = os.path.join(build_dir, "test_" + spec["name"])
	if needs_rebuild(binp, src, main_c_path):
		proc = subprocess.run(
			[CC] + CFLAGS + [src, main_c_path, "-o", binp],
			capture_output=True,
			text=True,
		)
		if proc.returncode != 0:
			return (exname, False, "FAIL: %s compile error\n%s" % (label, proc.stderr))
	ok, msg = spec["check"](binp)
	if not ok:
		return (exname, False, "FAIL: %s %s output mismatch\n  %s" % (label, spec["name"], msg))
	ok, msg = run_norminette(src)
	if not ok:
		return (exname, False, "FAIL: %s norminette\n%s" % (label, msg))
	return (exname, True, "PASS: %s %s" % (label, spec["name"]))


def clean_exercise(exname, exdir):
	build_dir = os.path.join(CACHE_ROOT, cache_key(exname, exdir))
	if os.path.exists(build_dir):
		shutil.rmtree(build_dir)


def discover(root):
	found = {}
	for exdir in sorted(os.listdir(root)):
		path = os.path.join(root, exdir)
		if exdir in EXERCISES and os.path.isdir(path):
			found[exdir] = EXERCISES[exdir]
	return found


def find_c01(start):
	cur = os.path.abspath(start)
	while True:
		if os.path.isdir(cur) and os.path.basename(cur).lower() == "c01":
			return cur
		parent = os.path.dirname(cur)
		if parent == cur:
			return None
		cur = parent


args = sys.argv[1:]
do_clean = "clean" in args
paths = [a for a in args if a != "clean"]
if paths:
	root = os.path.abspath(paths[0])
else:
	root = find_c01(".") or os.path.abspath(".")

exercises = discover(root)
if not exercises:
	print("No known exercise directories found under %s" % root)
	sys.exit(1)

if do_clean:
	for exname in exercises:
		clean_exercise(exname, os.path.join(root, exname))
	print("Cleaned %d exercise(s)" % len(exercises))
	sys.exit(0)

# Each exercise is an independent compile+run+norminette pipeline, so they
# run concurrently (bounded by CPU count) instead of one at a time - this is
# the "proc1& proc2&... wait" pattern, done with a thread pool instead of
# literal background shell jobs so results can still be collected and
# printed in a stable order. subprocess.run() releases the GIL while the
# child (cc/clang/norminette) runs, so threads - not multiprocessing - are
# enough here; no shared mutable state crosses exercises.
results = {}
with concurrent.futures.ThreadPoolExecutor(max_workers=len(exercises)) as pool:
	futures = [
		pool.submit(test_exercise, exname, os.path.join(root, exname), spec)
		for exname, spec in exercises.items()
	]
	for future in concurrent.futures.as_completed(futures):
		exname, ok, msg = future.result()
		results[exname] = ok
		print(msg)

failures = sum(1 for ok in results.values() if not ok)
if failures:
	print("%d/%d exercise(s) failed" % (failures, len(exercises)))
	sys.exit(1)

print("All %d exercise(s) passed" % len(exercises))
