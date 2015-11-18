#include <interprete.h>
#include <stdio.h>

void		debug_env(t_env *env)
{
	size_t	position;

	printf("Buffer:     {");
	position = 0;
	while (position <= env->len)
	{
		if (position == 0)
			printf("'%c'", env->buffer[position]);
		else if (position != env->len)
			printf(", '%c'", env->buffer[position]);
		else
			printf(", '%c'}.\n", env->buffer[position]);
		++position;
	}

	printf("interprete: {");
	position = 0;
	while (position <= env->len)
	{
		if (position == 0)
			printf(" %i", env->interprete[position]);
		else if (position != env->len)
			printf(",   %i", env->interprete[position]);
		else
			printf(",   %i}.\n", env->interprete[position]);
		++position;
	}
	if (env->last_char == INTERPRETED)
		printf("Line is closed\n");
	else if (env->last_char == SIMPLE_QUOTED)
		printf("Line is not closed due to a simple quote.\n");
	else if (env->last_char == DOUBLE_QUOTED)
		printf("Line is not closed due to a double quote.\n");
	else if (env->last_char == BACK_QUOTED)
		printf("Line is not closed due to a back quote.\n");
	else if (env->last_char == BACKSLASHED)
		printf("Line is not closed due to a backslash.\n");
}

void		put_env(t_env *env)
{
	size_t	id;

	printf("Argc: %i\n", env->argc);
	printf("Argv:\n");
	id = 0;
	while (env->argv[id])
	{
		printf("\t%lu: [%s]\n", id, env->argv[id]);
		++id;
	}
}