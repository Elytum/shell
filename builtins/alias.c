#include <builtins.h>
#include <string.h>
#include <unistd.h>

void			builtin_alias(t_env *env)
{
	int			i;
	size_t		second;
	char		*ptr;

	i = 1;
	while (i < env->argc)
	{
		second = 0;
		while (env->argv[i][second] && env->argv[i][second] != '=')
			++second;
		if (env->argv[i][second] == '=')
		{
			env->argv[i][second] = '\0';
			ht_set(env->alias, strdup(env->argv[i]), strdup(env->argv[i] + second + 1));
			env->argv[i][second] = '=';
		}
		else if ((ptr = ht_get(env->alias, env->argv[i])))
		{
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, "=", 1);
			write(1, ptr, strlen(ptr));
			write(1, "\n", 1);
		}
		++i;
	}
}