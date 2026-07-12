EXDIRS	= 00_alpha_mirror 01_camel_to_snake 02_do_op 03_ft_atoi 04_ft_strcmp \
	  05_ft_strcspn 06_ft_strdup 07_ft_strpbrk 08_ft_strrev 09_ft_strspn \
	  10_is_power_of_2 11_max 12_print_bits 13_reverse_bits 14_swap_bits \
	  15_inter 16_union 17_wdmatch

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
