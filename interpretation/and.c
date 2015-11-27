#include <interprete.h>

void		interprete_and(t_interprete *env)
{
	env->last_token = AND;
	env->buffer[env->pos] = AND;
	env->interprete[env->pos++] = DELIMITER;
}
