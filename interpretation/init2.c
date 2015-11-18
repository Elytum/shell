#include <shell.h>
#include <interprete.h>
#include <string.h>

void		init_extract_content_tab(t_env *env)
{
	env->extract_content_tab[INTERPRETED] = &extract_normal;
	env->extract_content_tab[SIMPLE_QUOTED] = &extract_simple_quote;
	env->extract_content_tab[DOUBLE_QUOTED] = &extract_double_quote;
	env->extract_content_tab[BACK_QUOTED] = &extract_back_quote;
	env->extract_content_tab[BACKSLASHED] = &extract_backslash;
	env->extract_content_tab[START_LOCAL_VARIABLE] = &extract_value;
}

void		init_interprete_double_quote_tab(t_env *env)
{
	memset(env->interprete_double_quote_tab, 0, sizeof(env->interprete_double_quote_tab));
	env->interprete_double_quote_tab['$'] = 1;
	env->interprete_double_quote_tab['`'] = 1;
	env->interprete_double_quote_tab['"'] = 1;
	env->interprete_double_quote_tab['\n'] = 1;
}