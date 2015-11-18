#include <interprete.h>

void		interprete_or(t_env *env)
{
	env->last_token = OR;
	env->buffer[env->pos] = OR;
	env->interprete[env->pos++] = DELIMITER;
}
