#ifndef INTERPRETE_H
# define INTERPRETE_H

#include <shell.h>

char		start_interprete(t_env *env);
char		launch_interprete(t_env *env);

void		debug_env(t_env *env);
void		put_env(t_env *env);

void		set_argc(t_env *env);
int			set_argv(t_env *env);
int			set_arguments(t_env *env);

void		do_interprete(t_env *env);
void		interprete_simple_quote(t_env *env);
void		interprete_double_quote(t_env *env);
void		interprete_double_quote_normal(t_env *env);
void		interprete_double_quote_stop(t_env *env);
void		interprete_back_quote(t_env *env);
void		interprete_value(t_env *env);
void		interprete_backslash(t_env *env);
void		interprete_tilde(t_env *env);
void		interprete_spacing(t_env *env);
void		interprete_normal(t_env *env);
void		interprete_null(t_env *env);
void		interprete_comma(t_env *env);
void		interprete_and(t_env *env);
void		interprete_or(t_env *env);
void		interprete_background(t_env *env);
void		interprete_pipe(t_env *env);

void		do_process(t_env *env);
void		process_back_quotes(t_env *env);

void		do_simplify(t_env *env);

size_t		len_normal(t_env *env, size_t *pos);
size_t		len_simple_quote(t_env *env, size_t *pos);
size_t		len_double_quote(t_env *env, size_t *pos);
size_t		len_back_quote(t_env *env, size_t *pos);
size_t		len_backslash(t_env *env, size_t *pos);
size_t		len_value(t_env *env, size_t *pos);

void		extract_normal(t_env *env, size_t *pos, char **ptr);
void		extract_simple_quote(t_env *env, size_t *pos, char **ptr);
void		extract_double_quote(t_env *env, size_t *pos, char **ptr);
void		extract_back_quote(t_env *env, size_t *pos, char **ptr);
void		extract_backslash(t_env *env, size_t *pos, char **ptr);
void		extract_value(t_env *env, size_t *pos, char **ptr);

void		add_local_variable(t_env *env, const char *key, const char *value);

void		*debug_malloc(size_t size);

void		init_do_interprete_tab(t_env *env);
void		init_interprete_value_stop(t_env *env);
void		init_standard_delimiters(t_env *env);
void		init_spaces(t_env *env);
void		init_should_len_tab(t_env *env);
void		init_extract_content_tab(t_env *env);
void		init_interprete_double_quote_tab(t_env *env);

#endif
