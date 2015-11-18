#include <builtins.h>
#include <string.h>
#include <unistd.h>

void			builtin_unalias(t_env *env)
{
	const char	error[] = "unalias: no such hash table element: ";
	int			i;
	t_alias		*alias;

	i = 1;
	while (i < env->argc)
	{
		if ((alias = (t_alias *)ht_get(env->alias, env->argv[i])))
		{
			free(alias->string);
			ht_remove(env->alias, env->argv[i]);
		}
		else
		{
			write(1, error, sizeof(error) - 1);
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, "\n", 1);
		}
		++i;
	}
}