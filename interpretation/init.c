#include <shell.h>
#include <interprete.h>
#include <string.h>
#include <stdio.h>
#include <macro.h>

void		init_do_interprete_tab(t_env *env)
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

void		init_interprete_value_stop(t_env *env)
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

void		init_standard_delimiters(t_env *env)
{
	memset(env->standard_delimiters, 0, sizeof(env->standard_delimiters));
	env->standard_delimiters[' '] = 1;
	env->standard_delimiters['\t'] = 1;
	env->standard_delimiters['\0'] = 1;
	env->standard_delimiters[';'] = 1;
	env->standard_delimiters['|'] = 1;
	env->standard_delimiters['&'] = 1;
}

void		init_spaces(t_env *env)
{
	memset(env->spaces, 0, sizeof(env->spaces));
	env->spaces[' '] = 1;
	env->spaces['\t'] = 1;
	env->spaces['\0'] = 1;
}

void		init_should_len_tab(t_env *env)
{
	env->should_len_tab[INTERPRETED] = &len_normal;
	env->should_len_tab[SIMPLE_QUOTED] = &len_simple_quote;
	env->should_len_tab[DOUBLE_QUOTED] = &len_double_quote;
	env->should_len_tab[BACK_QUOTED] = &len_back_quote;
	env->should_len_tab[BACKSLASHED] = &len_backslash;
	env->should_len_tab[START_LOCAL_VARIABLE] = &len_value;
}