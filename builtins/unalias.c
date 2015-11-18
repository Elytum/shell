#include <builtins.h>
#include <string.h>
#include <unistd.h>

void			builtin_unalias(t_env *env)
{
	const char	error[] = "unalias: no such hash table element: ";
	int			i;

	i = 1;
	while (i < env->argc)
	{
		if (ht_get(env->alias, env->argv[i]))
			ht_remove(env->alias, env->argv[i]);
		else
		{
			write(1, error, sizeof(error) - 1);
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, "\n", 1);
		}
		++i;
	}
}