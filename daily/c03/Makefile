EXDIRS	= ex00 ex01 ex02 ex03 ex04 ex05

.ONESHELL:

.PHONY: test clean

test:
	set -e
	for dir in $(EXDIRS); do
		$(MAKE) -C $$dir test
	done

clean:
	set -e
	for dir in $(EXDIRS); do
		$(MAKE) -C $$dir clean
	done
