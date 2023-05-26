#include "shell.h"
/**
 **_strchr - locates a character in a string
 *@s: the string to be checked
 *@c: the character to look for
 *Return:Returns pointer to the memory of s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
