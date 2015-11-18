#include <interprete.h>
#include <string.h>

#include <stdio.h>

void		do_interprete(t_env *env)
{
	env->pos = env->start;
	while (env->pos <= env->len)
		env->do_interprete_tab[(int)env->buffer[env->pos]](env);
}

void		do_process(t_env *env)
{
	process_back_quotes(env);
}

void		do_simplify(t_env *env)
{
	size_t			buffer_pos;
	const size_t	len = env->len;

	buffer_pos = 0;
	env->pos = env->start;
	while (env->pos <= len)
	{
		if (env->interprete[env->pos] == REMOVE)
		{
			++env->pos;
			--env->len;
		}
		else
		{
			env->buffer[buffer_pos] = env->buffer[env->pos];
			env->interprete[buffer_pos] = env->interprete[env->pos];
			++buffer_pos;
			++env->pos;
		}
	}
	while (env->interprete[env->len - 1] == SPACING)
		--env->len;
}

int			set_arguments(t_env *env)
{
	set_argc(env);
	return (set_argv(env));
}

char		start_interprete(t_env *env)
{
	env->start = 0;
	env->last_char = '\0';
	if (env->len == 0)
		return (STOP);
	memcpy(env->buffer, env->line, env->len + 1);
	memset(env->interprete, '\0', env->len + 1);

	do_interprete(env);
	if (env->last_char)
		return (NOT_CLOSED);
	do_simplify(env);
	do_process(env);
	return (CONTINUE);
}

char		launch_interprete(t_env *env)
{
	set_arguments(env);
	if (env->len < env->start -1)
		return (STOP);
	return (CONTINUE);
}
