#include <interprete.h>

void		interprete_backslash(t_interprete *env)
{
	if (env->pos == env->len - 1)
	{
		++env->pos;
		env->last_char = BACKSLASHED;
		return ;
	}
	env->interprete[env->pos++] = REMOVE;
	if (env->buffer[env->pos] == '\r')
		env->interprete[env->pos] = REMOVE;
	else
		env->interprete[env->pos] = INTERPRETED;
	++env->pos;
}

size_t		len_backslash(t_interprete *env, size_t *pos)
{
	(void)env;
	++*pos;
	return (1);
}

void		extract_backslash(t_interprete *env, size_t *pos, char **ptr)
{
	**ptr = env->buffer[*pos];
	++*ptr;
	++*pos;
}
