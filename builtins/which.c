#include <shell.h>
#include <string.h>
#include <unistd.h>

/*
** GOTTA ADD ALIAS HANDLING
*/

void			builtin_which(t_env *env)
{
	char		*str;
	const char	builtin[] = ": shell built-in command\n";
	const char	not_found[] = " not found\n";
	int			i;

	i = 1;
	while (i < env->argc)
	{
		if (ht_get(env->builtins, env->argv[i]))
		{
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, builtin, sizeof(builtin) - 1);

		}
		else if ((str = ht_get(env->binaries, env->argv[i])))
		{
			write(1, str, strlen(str));
			write(1, "\n", 1);
		}
		else
		{
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, not_found, sizeof(not_found) - 1);
		}
		++i;
	}
}