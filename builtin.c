#include "shell.h"

/**
 * _mexit - exits the shell
 * @info: Structure containing potential arguments Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _mexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1])
	{
		exitcheck = _errsatoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			prints_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _errsatoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mcd - changes the  directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mcd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenviron(info, "HOME=");
		if (!dir)
			chdir_ret =
				chdir((dir = _getenviron(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenviron(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenviron(info, "OLDPWD=")), _putchar('\n');
		chdir_ret =
			chdir((dir = _getenviron(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		prints_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenviron(info, "OLDPWD", _getenviron(info, "PWD="));
		_setenviron(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _mhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mhelp(info_t *info)
{
	char **arg_arr;

	arg_arr = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_arr);
	return (0);
}
