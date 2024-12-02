uniconv: uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c uniconv.h
	gcc -o uniconv uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c -lm 

ctest: uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c uniconv.h
	gcc -o ctest --coverage uniconv.c message.c read_input.c calculate_conversion.c print_output.c error.c -lm 
 