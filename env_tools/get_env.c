#include <get_env.h>
#include <string.h>

char	*get_env(t_env *env, const char *key)
{
	if (!strcmp(key, "pwd"))
		return (env->pwd);
	else if (!strcmp(key, "HOME"))
		return (env->home);
	else
		return (NULL);
}