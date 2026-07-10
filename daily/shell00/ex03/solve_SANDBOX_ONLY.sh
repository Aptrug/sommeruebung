#!/bin/sh
# solve_SANDBOX_ONLY.sh for ex03 (id_rsa_pub)
#
# *** DO NOT SUBMIT ANYTHING THIS SCRIPT GENERATES ***
#
# This exists only so a test.sh could have something structurally valid to
# check against (e.g. "does id_rsa_pub look like a real public key"). It is
# NOT a substitute for the real exercise, which requires:
#   1. generating YOUR OWN keypair with ssh-keygen (interactively is fine -
#      there's no reason to script this part for real)
#   2. uploading YOUR OWN public key to the 1337/42 intranet
#   3. confirming you can push to the school's git server with it
#
# A throwaway key generated here has no relationship to your intranet
# account and will not let you push anything anywhere.
set -eu

if ! command -v ssh-keygen > /dev/null 2>&1; then
	echo "ssh-keygen not found - cannot even generate the sandbox throwaway key."
	echo "This step must be done for real, outside any script, on your own machine."
	exit 1
fi

# ssh-keygen -t ed25519 -N "" -f ./sandbox_throwaway_key -C "SANDBOX ONLY - do not use" -q
ssh-keygen -N "" -f ./sandbox_throwaway_key -C "SANDBOX ONLY - do not use" -q
cp sandbox_throwaway_key.pub id_rsa_pub

echo "Generated a THROWAWAY sandbox key for structural testing only."
echo "This is NOT your real key. Generate your real one with:"
echo "    ssh-keygen -t ed25519 -C \"your_email@example.com\""
echo "and upload the matching .pub file's contents to the intranet yourself."
