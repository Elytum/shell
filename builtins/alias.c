#include <builtins.h>
#include <string.h>
#include <unistd.h>

static t_alias	*new_alias(const char *str)
{
	t_alias		*alias;
	char		*ptr;

	if (!(alias = (t_alias *)malloc(sizeof(t_alias))))
		return (NULL);
	if (!(alias->string = strdup(str)))
	{
		free(alias);
		return (NULL);
	}
	ptr = alias->string;
	if (!*ptr)
	{
		alias->size = 0;
		return (alias);
	}
	alias->size = 1;
	while (*ptr)
	{
		if (*ptr == ' ' || *ptr == '\t')
		{
			++alias->size;
			*ptr = '\0';
		}
		++ptr;
	}
	return (alias);
}

static void		put_alias(const t_alias * const alias)
{
	const char	*ptr;
	const char	*end;
	size_t		total;

	total = 0;
	ptr = alias->string;
	while (total < alias->size)
	{
		if (total)
			write(1, " ", 1);
		++total;
		end = ptr;
		while (*end)
			++end;
		write(1, ptr, end - ptr);
		ptr = end + 1;
	}
}

void			builtin_alias(t_env *env)
{
	int			i;
	size_t		second;
	t_alias		*alias;

	i = 1;
	while (i < env->argc)
	{
		second = 0;
		while (env->argv[i][second] && env->argv[i][second] != '=')
			++second;
		if (env->argv[i][second] == '=')
		{
			env->argv[i][second] = '\0';
			if ((alias = (t_alias *)new_alias(env->argv[i] + second + 1)))
				ht_set(env->alias, strdup(env->argv[i]), alias);
			env->argv[i][second] = '=';
		}
		else if ((alias = (t_alias *)ht_get(env->alias, env->argv[i])))
		{
			write(1, env->argv[i], strlen(env->argv[i]));
			write(1, "=", 1);
			put_alias(alias);
			write(1, "\n", 1);
		}
		++i;
	}
}