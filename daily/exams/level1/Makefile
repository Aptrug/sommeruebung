EXDIRS	= first_word fizzbuzz ft_putstr ft_strcpy ft_strlen ft_swap last_word \
	  repeat_alpha rev_print rot_13 rotone search_and_replace ulstr

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
