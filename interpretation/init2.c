#include <shell.h>
#include <interprete.h>
#include <string.h>

void		init_extract_content_tab(t_interprete *env)
{
	env->extract_content_tab[INTERPRETED] = &extract_normal;
	env->extract_content_tab[SIMPLE_QUOTED] = &extract_simple_quote;
	env->extract_content_tab[DOUBLE_QUOTED] = &extract_double_quote;
	env->extract_content_tab[BACK_QUOTED] = &extract_back_quote;
	env->extract_content_tab[BACKSLASHED] = &extract_backslash;
	env->extract_content_tab[START_LOCAL_VARIABLE] = &extract_value;
}

void		init_interprete_double_quote_tab(t_interprete *env)
{
	memset(env->interprete_double_quote_tab, 0, sizeof(env->interprete_double_quote_tab));
	env->interprete_double_quote_tab['$'] = 1;
	env->interprete_double_quote_tab['`'] = 1;
	env->interprete_double_quote_tab['"'] = 1;
	env->interprete_double_quote_tab['\n'] = 1;
}

void		init_standard_delimiters(t_interprete *env)
{
	memset(env->standard_delimiters, 0, sizeof(env->standard_delimiters));
	env->standard_delimiters[' '] = 1;
	env->standard_delimiters['\t'] = 1;
	env->standard_delimiters['\0'] = 1;
	env->standard_delimiters[';'] = 1;
	env->standard_delimiters['|'] = 1;
	env->standard_delimiters['&'] = 1;
}

void		init_spaces(t_interprete *env)
{
	memset(env->spaces, 0, sizeof(env->spaces));
	env->spaces[' '] = 1;
	env->spaces['\t'] = 1;
	env->spaces['\0'] = 1;
}

void		init_should_len_tab(t_interprete *env)
{
	env->should_len_tab[INTERPRETED] = &len_normal;
	env->should_len_tab[SIMPLE_QUOTED] = &len_simple_quote;
	env->should_len_tab[DOUBLE_QUOTED] = &len_double_quote;
	env->should_len_tab[BACK_QUOTED] = &len_back_quote;
	env->should_len_tab[BACKSLASHED] = &len_backslash;
	env->should_len_tab[START_LOCAL_VARIABLE] = &len_value;
}
