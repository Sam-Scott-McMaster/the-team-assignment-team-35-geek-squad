dev: uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c uniconv.h
	gcc -o uniconv uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c

# test: uniconv.c message.c read_input.c extract_input.c uniconv.h
# 	gcc -o uniconv --coverage uniconv.c message.c read_input.c extract_input.c
