#include <interprete.h>
#include <string.h>

#include <stdio.h>

void		interprete_value(t_env *env)
{
	size_t	newpos;

	newpos = env->pos;
	if (env->interprete[newpos + 1] == ' ' || env->interprete[newpos + 1] == '\t')
	{
		env->interprete[++newpos] = INTERPRETED;
		return ;
	}
	env->interprete[newpos++] = START_LOCAL_VARIABLE;
	while (env->interprete_value_stop[(int)env->buffer[newpos]])
		newpos++;
	if ((env->pos == 0 || env->interprete[env->pos - 1] == SPACING) &&
		env->standard_delimiters[(int)env->buffer[newpos]])
		memset(env->interprete + env->pos + 1, ALONE_LOCAL_VARIABLE, newpos - env->pos);
	else
		memset(env->interprete + env->pos + 1, LOCAL_VARIABLE, newpos - env->pos);
	env->pos = newpos;
}

size_t		len_value(t_env *env, size_t *pos)
{
	char	c;
	char	*tmp;
	size_t	end;

	end = *pos + 1;
	while (end < env->len && env->interprete[end] == LOCAL_VARIABLE)
		++end;
	if (end == *pos + 1)
		return (0);
	c = env->buffer[end];
	env->buffer[end] = '\0';
	tmp = ht_get(env->local_variables, env->buffer + *pos + 1);
	env->buffer[end] = c;
	*pos = end;
	if (!tmp)
		return (0);
	return (strlen(tmp));
}

void		extract_value(t_env *env, size_t *pos, char **ptr)
{
	char	c;
	char	*tmp;
	size_t	end;

	end = *pos + 1;
	while (end < env->len && env->interprete[end] == LOCAL_VARIABLE)
		++end;
	if (end == *pos + 1)
		return ;
	c = env->buffer[end];
	env->buffer[end] = '\0';
	tmp = ht_get(env->local_variables, env->buffer + *pos + 1);
	env->buffer[end] = c;
	*pos = end;
	if (!tmp)
		return ;
	end = strlen(tmp);
	memcpy(*ptr, tmp, end);
	*ptr += end;
}