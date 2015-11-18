#include <interprete.h>

void		interprete_and(t_env *env)
{
	env->last_token = AND;
	env->buffer[env->pos] = AND;
	env->interprete[env->pos++] = DELIMITER;
}
