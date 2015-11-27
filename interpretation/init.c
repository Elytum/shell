#include <shell.h>
#include <interprete.h>
#include <string.h>
#include <stdio.h>
#include <macro.h>

#include <string.h>

t_interprete		*init_interpretation(void)
{
	t_interprete *env;

	if (!(env = (t_interprete *)malloc(sizeof(t_interprete))))
		return (NULL);
	init_do_interprete_tab(env);
	init_interprete_value_stop(env);
	init_standard_delimiters(env);
	init_spaces(env);
	init_should_len_tab(env);
	init_extract_content_tab(env);
	env->argv_pool_size = 0;
	return (env);
}

void		init_do_interprete_tab(t_interprete *env)
{
	unsigned int i;

	i = 0;
	while (i < TAB_SIZE(env->do_interprete_tab))
		env->do_interprete_tab[i++] = &interprete_normal;
	env->do_interprete_tab['\''] = &interprete_simple_quote;
	env->do_interprete_tab['\"'] = &interprete_double_quote;
	env->do_interprete_tab['\\'] = &interprete_backslash;
	env->do_interprete_tab['`'] = &interprete_back_quote;
	env->do_interprete_tab['$'] = &interprete_value;
	env->do_interprete_tab['~'] = &interprete_tilde;
	env->do_interprete_tab[' ' ] = &interprete_spacing;
	env->do_interprete_tab['\t'] = &interprete_spacing;
	env->do_interprete_tab['\0'] = &interprete_null;
	env->do_interprete_tab[';'] = &interprete_comma;
	env->do_interprete_tab['&'] = &interprete_background;
	env->do_interprete_tab['|'] =  &interprete_pipe;
}

void		init_interprete_value_stop(t_interprete *env)
{
	memset(env->interprete_value_stop, 1, sizeof(env->interprete_value_stop));
	env->interprete_value_stop['\''] = 0;
	env->interprete_value_stop['\"'] = 0;
	env->interprete_value_stop['\\'] = 0;
	env->interprete_value_stop['`'] = 0;
	env->interprete_value_stop['$'] = 0;
	env->interprete_value_stop[' '] = 0;
	env->interprete_value_stop['\t'] = 0;
	env->interprete_value_stop['\0'] = 0;
	env->interprete_value_stop[';'] = 0;
	env->interprete_value_stop['|'] = 0;
	env->interprete_value_stop['&'] = 0;
}
