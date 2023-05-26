#include "shell.h"

/**
 * find_path - finds the full path for a given command
 * @info: the info struct
 * @pathstr: the PATH string
 * @command: the command to find
 * Return: full path of command otherwise NULL
 */
char *find_path(info_t *info, char *pathstr, char *command)
{
	int i = 0, curr_position = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(command) > 2) && starts_with(command, "./"))
	{
		if (is_cmd(info, command))
			return (command);
	}
	while (1)
	{
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_position, i);
			if (!*path)
				_strcat(path, command);
			else
			{
				_strcat(path, "/");
				_strcat(path, command);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[i])
				break;
			curr_position = i;
		}
		i++;
	}
	return (NULL);
}
