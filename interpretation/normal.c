#include <interprete.h>

#include <stdio.h>

void		interprete_spacing(t_env *env)
{
	env->interprete[env->pos++] = SPACING;
}

void		interprete_normal(t_env *env)
{
	env->interprete[env->pos++] = INTERPRETED;
}

size_t		len_normal(t_env *env, size_t *pos)
{
	(void)env;
	++*pos;
	return (1);
}

void		extract_normal(t_env *env, size_t *pos, char **ptr)
{
	while (env->interprete[*pos] == INTERPRETED)
	{
		**ptr = env->buffer[*pos];
		++*ptr;
		++*pos;
	}
}