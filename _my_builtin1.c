#include "shell.h"

/**
 * exit_shell - this function exits the shell
 * @information: Struct containing all the builtins
 * Return: exits with a given exit status
 */
int exit_shell(info_t *information)
{
	int checkexit;

	if (information->argv[1])
	{
		checkexit = string_to_int(information->argv[1]);
		if (checkexit == -1)
		{
			information->status = 2;
			_pperror(information, "Enter correct number: ");
			_eputs(information->argv[1]);
			p_char('\n');
			return (1);
		}
		information->err_num = string_to_int(information->argv[1]);
		return (-2);
	}
	information->err_num = -1;
	return (-2);
}

