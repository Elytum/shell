#include <builtins.h>
#include <string.h>

// void			do_unsetenv(t_env *env, char *line)
// {
// 	size_t		pos;
// 	char		*tmp;
// 	size_t		len;

// 	pos = 0;
// 	while (pos < ENV_TABLE_SIZE && env->env_table[pos][0])
// 	{
// 		tmp = get_env_name(env->env_table[pos]);
// 		len = strlen(tmp);
// 		if (!strncmp(tmp, line, len) && (line[len] == ' ' || line[len] == '\t'))
// 		{
// 			memcpy(env->env_table[pos], env->env_table[pos + 1], ENV_TABLE_CONTENT_SIZE);
// 			while (pos < ENV_TABLE_SIZE && env->env_table[pos + 1][0])
// 			{
// 				memcpy(env->env_table[pos], env->env_table[pos + 1], ENV_TABLE_CONTENT_SIZE);
// 				++pos;
// 			}
// 			env->env_table[pos][0] = '\0';
// 			return ;
// 		}
// 		++pos;
// 	}
// }

void			builtin_unsetenv(t_env *env)
{
	(void)env;
	// const char	error[] = "unsetenv: Too few arguments.\n";
	// char		*ptr;
	// char		*name;

	// ptr = env->line + sizeof("unsetenv") - 1;
	// name = NULL;
	// while (*ptr == ' ' || *ptr == '\t')
	// 	++ptr;
	// if (!*ptr)
	// 	write(1, error, sizeof(error) - 1);
	// else
	// {
	// 	while (*ptr)
	// 	{
	// 		do_unsetenv(env, ptr);
	// 		while (*ptr && !(*ptr == ' ' || *ptr == '\t' || *ptr == '\n'))
	// 			++ptr;
	// 		while (*ptr == ' ' || *ptr == '\t' || *ptr == '\n')
	// 			++ptr;
	// 	}
	// }
}