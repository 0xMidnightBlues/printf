#include "main.h"

/**
 * convert - converts numbers and bases into a string
 * @num: input number
 * @base: input base
 * @lowercase: set to truthy value if the hexa should be lowercase
 * Return: result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[64];
	char *ret;

	rep = (lowercase)
		? "0123456789abcdef"
		: "0123456789ABCDEF";
	ret = &buffer[63];
	*ret = '\0';
	do {
		*--ret = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ret);
}
