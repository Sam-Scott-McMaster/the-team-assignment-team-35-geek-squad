dev: uniconv.c message.c read_input.c calculate_conversion.c uniconv.h
	gcc -o uniconv uniconv.c message.c read_input.c calculate_conversion.c

# test: uniconv.c message.c read_input.c extract_input.c uniconv.h
# 	gcc -o uniconv --coverage uniconv.c message.c read_input.c extract_input.c
