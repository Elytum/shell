#include <shell.h>
#include <interprete.h>
#include <string.h>
#include <unistd.h>

#include <stdio.h>

static char		launch_builtin(t_env *env)
{
	void			(*builtin)(struct s_env *env);

	if (!(builtin = ht_get(env->builtins, env->argv[0])))
		return (0);
	builtin(env);
	if (launch_interprete(env->interpretation) != CONTINUE)
		return (-1);
	return (1);
}

static char		handling_binary(t_env *env, pid_t child, const char *path)
{
	const char		execve_error[] = SHELL_NAME": execve error\n";
	int				stat_loc;
	
	if (child == 0)
	{
		if (path && execve(path, env->argv, NULL) == -1) //GOTTA ADD ENV
			write(1, execve_error, sizeof(execve_error) - 1);
		exit(0);
	}
	else
	{
		if (launch_interprete(env->interpretation) != CONTINUE)
		{
			waitpid(child, &stat_loc, 0);
			return (-1);
		}
		waitpid(child, &stat_loc, 0);
	}
	return (1);
}

static char		launch_binary(t_env *env)
{
	const char		fork_error[] = SHELL_NAME": fork error\n";
	char			*path;
	pid_t			child;

	if (executable_file(env->argv[0]))
		path = env->argv[0];
	else if (!(path = ht_get(env->binaries, env->argv[0])) ||
			!executable_file(path))
		return (0);
	child = fork();
	if (child == -1)
	{
		write(1, fork_error, sizeof(fork_error) - 1);
		return (-1);
	}
	return (handling_binary(env, child, path));
}

static char		unknown_function(t_env *env)
{
	const char		error[] = SHELL_NAME": command not found: ";

	write(1, error, sizeof(error) - 1);
	write(1, env->argv[0], strlen(env->argv[0]));
	write(1, "\n", 1);
	if (launch_interprete(env->interpretation) != CONTINUE)
		return (-1);
	return (0);
}

void			*memrcpy(void *dst, const void *src, size_t len)
{
	char		*dst_ptr;
	char		*src_ptr;

	dst_ptr = (char *)dst + len;
	src_ptr = (char *)src + len;
	while (dst_ptr > (char *)dst)
	{
		printf("Moving [%x]\n", *src_ptr);
		*dst_ptr-- = *src_ptr--;
	}
	return (dst);
}

static void		handle_alias(t_env *env)
{
	t_alias		*alias = ht_get(env->alias, env->argv[0]);
	char		error[] = SHELL_NAME": too many arguments to handle alias\n";
	char		*ptr;
	size_t		total;
	char		**argv_ptr;

	if (!alias)
		return ;
	if (env->argc + alias->size > sizeof(env->argv))
	{
		write(1, error, sizeof(error) - 1);
		return ;
	}
	memcpy(env->argv + alias->size, env->argv + 1, env->argc * sizeof(void *));
	ptr = alias->string;
	total = 0;
	argv_ptr = env->argv;
	while (total < alias->size)
	{
		*argv_ptr++ = ptr;
		while (*ptr)
			++ptr;
		++ptr;
		++total;
	}
	env->argc += alias->size - 1;
}

void			launch_command(t_env *env)
{
	char			ret;

	refresh_binaries(env->binaries);
	if (launch_interprete(env->interpretation) != CONTINUE)
		return ;
	while (42)
	{
		memcpy(env->argv, env->interpretation->argv, sizeof(env->argv));
		handle_alias(env);
		if ((ret = launch_builtin(env)))
		{
			if (ret == -1)
				return ;
			continue ;
		}
		else if ((ret = launch_binary(env)))
		{
			if (ret == -1)
				return ;
			continue ;
		}
		if ((ret = unknown_function(env) == -1))
			return ;
	}
}