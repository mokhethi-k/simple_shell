#include "shell.h"

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t cp, len;
	size_t index;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (cp == len)
		cp = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + cp, '\n');
	index = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + index : index + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + cp, index - cp);
	else
		_strncpy(new_p, buf + cp, index - cp + 1);

	s += index - cp;
	cp = index;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}
