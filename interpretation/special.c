#include <interprete.h>

void		interprete_null(t_interprete *env)
{
	if (env->pos == env->len)
		env->interprete[env->pos++] = INTERPRETED;
	else
		env->interprete[env->pos++] = REMOVE;
}
