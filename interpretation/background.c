#include <interprete.h>

void		interprete_background(t_env *env)
{
	if (env->buffer[env->pos + 1] == '&')
	{
		env->interprete[env->pos++] = REMOVE;
		interprete_and(env);
	}
	else
	{
		env->last_token = BACKGROUND;
		env->buffer[env->pos] = PIPE;
		env->interprete[env->pos++] = DELIMITER;
	}
}
