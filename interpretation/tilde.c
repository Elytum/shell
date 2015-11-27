#include <interprete.h>
#include <string.h>

#include <stdio.h>

void		interprete_tilde(t_interprete *env)
{
	if ((env->pos == 0 || env->interprete[env->pos - 1] == SPACING) &&
		env->spaces[(unsigned char)env->buffer[env->pos + 1]])
		env->interprete[env->pos] = TILDE;
	else
		env->interprete[env->pos] = INTERPRETED;
	++env->pos;
}
