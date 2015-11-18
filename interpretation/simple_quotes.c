#include <interprete.h>

void		interprete_simple_quote(t_env *env)
{
	env->interprete[env->pos++] = REMOVE;
	while (env->pos <= env->len)
	{
		if (env->buffer[env->pos] == '\'')
		{
			env->interprete[env->pos++] = REMOVE;
			return ;
		}
		else
			env->interprete[env->pos++] = INTERPRETED;
	}
	env->last_char = SIMPLE_QUOTED;
}

size_t		len_simple_quote(t_env *env, size_t *pos)
{
	size_t	size;

	size = 1;
	++*pos;
	while (*pos < env->len && env->interprete[*pos] == SIMPLE_QUOTED)
	{
		++size;
		++*pos;
	}
	return (size);
}

void		extract_simple_quote(t_env *env, size_t *pos, char **ptr)
{
	while (env->interprete[*pos] == SIMPLE_QUOTED)
	{
		**ptr = env->buffer[*pos];
		++*ptr;
		++*pos;
	}
}