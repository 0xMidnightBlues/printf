#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing the following flags
 * @plus: flag for the '+'
 * @space: flag for the ' '
 * @hash: flag for the '#'
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printFunc - depending on the format, gets
 * the right function
 * @c: format specifier
 * @f: pointer to the right print function
 */
typedef struct printFunc
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} printFunc_t;

/* print_nums */
int print_int(va_list l, flags_t *f);
void print_number(int n);
int print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* print_bases */
int print_hex(va_list l, flags_t *f);
int print_hex_big(va_list l, flags_t *f);
int print_binary(va_list l, flags_t *f);
int print_octal(va_list l, flags_t *f);

/* converter */
char *convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* get_print */
int (*get_print(char s))(va_list, flags_t *);

/* get_flag */
int get_flag(char s, flags_t *f);

/* print_alpha */
int print_string(va_list l, flags_t *f);
int print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _putstr(char *str);

/* print_custom */
int print_rot13(va_list l, flags_t *f);
int print_rev(va_list l, flags_t *f);
int print_bigS(va_list l, flags_t *f);

/* print_addr */
int print_addr(va_list l, flags_t *f);

/* print_percent */
int print_percent(va_list l, flags_t *f);

#endif
