#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void ft_putchar(char c) {
	write(1, &c, 1);
}

void ft_putstr(char *str) {
	while (*str) {
		ft_putchar(*str);
		str++;
	}
}

// light the (pos)ieme bit.
void light_bit(int *options, int pos) {
	int mask = 1;
	mask = mask << pos;
	*options = *options | mask;
}

// Modify options int with every option passed.
void get_options(char *str, int *options) {
	
	char *alphabet = "abcdefghijklmnopqrstuvwxyz\0";
	int i;

	while (*str) {
		i = 0;
		while (alphabet[i] && *str != alphabet[i]) {		
			i++;
		}
		// There is something else than a letter in this option string
		if (!alphabet[i]) {
			ft_putstr("Wrong option passed");
			exit(-1);
		}
		light_bit(options, i);
		str++;
	}
}

void print_bits(int n) {
	long mask;
	int i;

	mask = 2147483648;
	i = 0;
	while (i < 32) {
		if (n & mask) {
			ft_putchar('1');
		}	
		else {
			ft_putchar('0');
		}
		if (i && !(i % 8)) {
			ft_putchar(' ');
		}
		mask = mask >> 1;
		i++;
	}
}

int main(int argc, char **argv) {
	int i; 
	int options;
	
	options = 0;
	i = 0;
	while (i < argc) {
		if (argv[i] && argv[i][0] == '-') {
			get_options(++(argv[i]), &options);
		}
		i++;
	}
	print_bits(options);
	return 0;
}
