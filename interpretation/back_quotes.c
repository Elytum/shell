#include <interprete.h>

void		interprete_back_quote(t_env *env)
{
	env->interprete[env->pos++] = REMOVE;
	while (env->pos <= env->len)
	{
		if (env->buffer[env->pos] == '`')
		{
			env->interprete[env->pos++] = REMOVE;
			return ;
		}
		else
			env->interprete[env->pos++] = BACK_QUOTED;
	}
	env->last_char = BACK_QUOTED;
}

void		process_back_quotes(t_env *env) // Actually just ignores it
{
	char	kind;

	env->pos = env->start;
	kind = INTERPRETED;
	while (env->pos <= env->len)
	{
		if (env->interprete[env->pos] == BACK_QUOTED)
			env->interprete[env->pos] = kind;
		kind = env->interprete[env->pos];
		++env->pos;
	}
}

size_t		len_back_quote(t_env *env, size_t *pos) // Implement once it can be
{
	(void)env;
	++*pos;
	return (0);
}

void		extract_back_quote(t_env *env, size_t *pos, char **ptr) // Implement once it can be
{
	(void)env;
	**ptr++ = env->buffer[*pos++];
}