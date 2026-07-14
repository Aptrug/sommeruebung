EXDIRS	= ex00

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
