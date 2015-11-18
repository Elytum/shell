#include <builtins.h>
#include <string.h>

void			builtin_exit(t_env *env)
{
	int			ret;

	if (env->argc <= 1)
		ret = 0;
	else
		ret = atoi(env->argv[1]);
	free(env);
	exit(ret);
}
