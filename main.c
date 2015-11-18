#include <shell.h>
#include <interprete.h>
#include <builtins.h>

#include <string.h>

#include <stdio.h>

t_env		*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)debug_malloc(sizeof(t_env))))
		return (ERROR);
	/* Old was 65536 */
	env->local_variables = ht_create( 8192 );
	env->alias = ht_create( 8192 );
	env->builtins = ht_create( 8192 );
	env->binaries = ht_create( 8192 );
	
	env->intro = strdup(SHELL_NAME"> ");

	init_builtins(env->builtins);

	memcpy(env->pwd, "<PWD VALUE>", sizeof(env->pwd));
	memcpy(env->home, "<HOME VALUE>", sizeof(env->home));

	init_do_interprete_tab(env);
	init_interprete_value_stop(env);
	init_standard_delimiters(env);
	init_spaces(env);
	init_should_len_tab(env);
	init_extract_content_tab(env);

	env->pwd_len = strlen(env->pwd);
	env->home_len = strlen(env->home);
	
	env->argv_pool_size = 0;
	return (env);
}

void		free_argv(t_env *env)
{
	size_t	id;

	id = 0;
	while (id < env->argv_pool_size)
	{
		// printf("Free of [%s]\n", env->argv_pool[id]);
		free(env->argv_pool[id++]);
	}
	env->argv_pool_size = 0;
}

void		add_local_variable(t_env *env, const char *key, const char *value)
{
	ht_set(env->local_variables, strdup(key), strdup(value));
}

void		*debug_malloc(size_t size)
{
	// printf("\t\t<MALLOC>\n\t\tRequested a malloc of %lu\n\n", size);
	return (malloc(size));
}

#include <unistd.h>

int			get_line(const char *intro, char *buffer, size_t size)
{
	write(1, intro, strlen(intro));
	return (read(1, buffer, size));
}

void		subshell(t_env *env, ssize_t *size)
{
	ssize_t	tmp;

	env->multiline = 1;
	if (env->last_char == SIMPLE_QUOTED)
		write(1, "quote> ", 7);
	else if (env->last_char == DOUBLE_QUOTED)
		write(1, "dquote> ", 8);
	else if (env->last_char == BACK_QUOTED)
		write(1, "bquote> ", 8);
	else if (env->last_char == BACKSLASHED)
		write(1, "> ", 2);
	else
	{
		write(1, "UNKNOWN ERROR WTF\n", 18);
		exit (ERROR_EXIT);
	}
	if ((tmp = get_line("", env->line + *size, sizeof(env->line) - *size)) < 0)
	{
		write(1, "Read error\n", 11);
		exit (ERROR_EXIT);
	}
	*size += tmp;
	env->len = *size;
}

int			main(void)
{
	t_env	*env;
	ssize_t	size;

	if ((env = init_env()) == ERROR)
		return (ERROR_EXIT);

	env->start = 0;

	add_local_variable(env, "HOME", "/nfs/zfs-student-3/users/2014/achazal");
	add_local_variable(env, "PWD", "/nfs/zfs-student-3/users/2014/achazal/tutoSh1/escaping");
	add_local_variable(env, "PATH", "/nfs/zfs-student-3/users/2014/achazal/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin");

	while ((size = get_line(env->intro, env->line, sizeof(env->line))) > 0)
	{
		env->multiline = 0;

		/*	TO BE DISCUSSED	*/
		env->line[sizeof(env->line) - 1] = '\0';
		// /*TO BE MAYBE REMOVED*/ env->len = size;
		/*TO BE MAYBE REMOVED*/env->len = size - 1;
		/*	TO BE DISCUSSED	*/

		while (start_interprete(env) == NOT_CLOSED)
			subshell(env, &size);
		if (env->multiline)
			--env->len;
		launch_command(env);
	}
	return (NORMAL_EXIT);
}