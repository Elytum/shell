#include <interprete.h>

void		interprete_comma(t_env *env)
{
	env->last_token = COMMA;
	env->buffer[env->pos] = COMMA;
	env->interprete[env->pos++] = DELIMITER;
}
