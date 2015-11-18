#include <interprete.h>

void		interprete_pipe(t_env *env)
{
	if (env->buffer[env->pos + 1] == '|')
	{
		env->interprete[env->pos++] = REMOVE;
		interprete_or(env);
	}
	else
	{
		env->last_token = PIPE;
		env->buffer[env->pos] = PIPE;
		env->interprete[env->pos++] = DELIMITER;
	}
}
