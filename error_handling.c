#include "shell.h"

/**
 * string_to_int - converts a string to an integer
 * @string: the string to be converted
 * Return: 0 if number of strings
 */
int string_to_int(char *string)
{
	int i = 0;
	unsigned long int result = 0;

	if (*string == '+')
		string++;
	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			result *= 10;
			result += (string[i] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * _pperror - perror
 * @struct_info: struct parameter
 * @error_strng: string with error
 * Return: 0 if no numbers in string, converted number otherwise
 */
void _pperror(info_t *struct_info, char *error_strng)
{
	_eputs(struct_info->fname);
	_eputs(": ");
	p_decimal(struct_info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(struct_info->argv[0]);
	_eputs(": ");
	_eputs(error_strng);
}

/**
 * p_decimal - prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: total number of characters printed
 */
int p_decimal(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int j, count = 0;
	unsigned int abc, current;

	if (fd == STDERR_FILENO)
		__putchar = p_char;
	if (input < 0)
	{
		abc = -input;
		__putchar('-');
		count++;
	}
	else
		abc = input;
	current = abc;
	for (j = 1000000000; j > 1; j /= 10)
	{
		if (abc / j)
		{
			__putchar('0' + current / j);
			count++;
		}
		current %= j;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
	int i;

	for (i = 0; buf[i] != '\0'; i++)
		if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
		{
			buf[i] = '\0';
			break;
		}
}

