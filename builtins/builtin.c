#include <shell.h>
#include <builtins.h>
#include <unistd.h>
#include <string.h>

#include <stdio.h>

void			builtin_builtin(t_env *env)
{
	const char	error[] = SHELL_NAME": no such builtin: ";
	void		(*builtin)(struct s_env *env);

	if (env->argc == 1)
		return ;
	memcpy(env->argv, env->argv + 1, sizeof(*(env->argv)) * (env->argc - 1));
	--env->argc;
	if ((builtin = ht_get(env->builtins, env->argv[0])))
		builtin(env);
	else
	{
		write(1, error, sizeof(error) - 1);
		write(1, env->argv[0], strlen(env->argv[0]));
		write(1, "\n", 1);
	}
}
