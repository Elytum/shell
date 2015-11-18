#include <shell.h>
#include <string.h>
#include <unistd.h>

void			builtin_echo(t_env *env)
{
	int			i;

	i = 1;
	while (i < env->argc)
	{
		if (i > 1)
			write(1, " ", 1);
		write(1, env->argv[i], strlen(env->argv[i]));
		++i;
	}
	write(1, "\n", 1);
}