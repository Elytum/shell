#include <builtins.h>
#include <string.h>

// static void		do_setenv_insert(t_env *env, char buffer[ENV_TABLE_CONTENT_SIZE])
// {
// 	const char	error[] = {"setenv: Too many environment variables\n"};
// 	size_t		element;

// 	element = 0;
// 	while (element < ENV_TABLE_SIZE && env->env_table[element][0])
// 	{
// 		if (env_name_match(get_env_name(env->env_table[element]), buffer))
// 		{
// 			memcpy(env->env_table[element], buffer, ENV_TABLE_CONTENT_SIZE);
// 			return ;
// 		}
// 		++element;
// 	}
// 	if (element < ENV_TABLE_SIZE)
// 	{
// 		memcpy(env->env_table[element], buffer, ENV_TABLE_CONTENT_SIZE);
// 		env->env_table[element + 1][0] = '\0';
// 	}
// 	else
// 		write(2, error, sizeof(error) - 1);
// }

// void			do_setenv_too_long(void)
// {
// 	const char	error[] = {"setenv: Name/value length combination too long\n"};

// 	write(2, error, sizeof(error) - 1);
// }

// size_t			word_len(const char *sentence)
// {
// 	const char	*ptr;

// 	ptr = sentence;
// 	while (*ptr && !(*ptr == ' ' || *ptr == '\t' || *ptr == '\n'))
// 		++ptr;
// 	return (ptr - sentence);
// }

// static void		do_setenv(t_env *env, const char *name, const char *value)
// {
// 	char		buffer[ENV_TABLE_CONTENT_SIZE];
// 	size_t		size_left;
// 	size_t		len_name;
// 	size_t		len_value;
// 	const char	*ptr;

// 	env->flag = 0;
// 	len_name = word_len(name);
// 	size_left = sizeof(buffer);
// 	if (size_left >= len_name)
// 	{
// 		memcpy(buffer, name, len_name);
// 		size_left -= len_name;
// 		if (size_left > 1)
// 		{
// 			buffer[len_name] = '=';
// 			len_value =  word_len(value);
// 			if (--size_left >= len_value)
// 			{
// 				memcpy(buffer + len_name + 1, value, len_value);
// 				buffer[len_name + 1 + len_value] = '\0';
// 				env->flag = 1;
// 			}
// 		}
// 	}
// 	(env->flag) ? do_setenv_insert(env, buffer) : do_setenv_too_long();
// }

void			builtin_setenv(t_env *env)
{
	(void)env;
	// const char	error[] = "setenv: Too many arguments.\n";
	// char		*ptr;
	// char		*name;
	// char		*extra_ptr;

	// ptr = env->line + sizeof("setenv") - 1;
	// name = NULL;
	// while (*ptr == ' ' || *ptr == '\t')
	// 	++ptr;
	// if (!*ptr)
	// 	builtin_env(env);
	// else
	// {
	// 	name = ptr;
	// 	while (*ptr && !(*ptr == ' ' | *ptr == '\t'))
	// 		++ptr;
	// 	while (*ptr == ' ' || *ptr == '\t')
	// 		++ptr;
	// 	if (!*ptr)
	// 		do_setenv(env, name, "");
	// 	else
	// 	{
	// 		extra_ptr = ptr;
	// 		while (*extra_ptr && !(*extra_ptr == ' ' || *extra_ptr == '\t' || *extra_ptr == '\n'))
	// 			++extra_ptr;
	// 		while (*extra_ptr == ' ' || *extra_ptr == '\t' || *extra_ptr == '\n')
	// 			++extra_ptr;
	// 		if (*extra_ptr)
	// 			write(2, error, sizeof(error) - 1);
	// 		else
	// 			do_setenv(env, name, ptr);
	// 	}
	// }
}