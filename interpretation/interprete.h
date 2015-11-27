#ifndef INTERPRETE_H
# define INTERPRETE_H

// #include <shell.h>
#include <htable.h>
#include <config.h>
#include <stdlib.h>
#include <limits.h>

#define ERROR 0
#define NO_ERROR 1
#define TRUE 0
#define FALSE 1

typedef struct		s_interprete
{

// FORGOT
	char			*argv[_POSIX_ARG_MAX];
	int				argc;
	char			error;
	char			line[_POSIX2_LINE_MAX];
	char			home[_POSIX_PATH_MAX];
	char			pwd[_POSIX_PATH_MAX];
	size_t			pwd_len;
	size_t			home_len;

// \FORGOT

	size_t			len;
	size_t			pos;
	size_t			start;

	char			buffer[_POSIX2_LINE_MAX];
	char			interprete[_POSIX2_LINE_MAX];

	char			*argv_tmp[_POSIX_ARG_MAX];

	char			*argv_pool[_POSIX_ARG_MAX];
	size_t			argv_pool_size;


	char			last_token;
	char			last_char;

	size_t			(*should_len_tab[MAX_BASIC_INTERPRETATION])(struct s_interprete *env, size_t *pos);
	void			(*extract_content_tab[MAX_BASIC_INTERPRETATION])(struct s_interprete *env, size_t *pos, char **ptr);

	hashtable_t		*local_variables;
	hashtable_t		*alias;
	hashtable_t		*builtins;
	hashtable_t		*binaries;

	void			(*do_interprete_tab[UCHAR_MAX])(struct s_interprete *env);
	char			interprete_double_quote_tab[UCHAR_MAX];
	char			interprete_value_stop[UCHAR_MAX];
	char			standard_delimiters[UCHAR_MAX];
	char			spaces[UCHAR_MAX];
}					t_interprete;

char				start_interprete(t_interprete *env);
char				launch_interprete(t_interprete *env);

void				debug_env(t_interprete *env);
void				put_interprete(t_interprete *env);

void				set_argc(t_interprete *env);
int					set_argv(t_interprete *env);
int					set_arguments(t_interprete *env);

void				do_interprete(t_interprete *env);
void				interprete_simple_quote(t_interprete *env);
void				interprete_double_quote(t_interprete *env);
void				interprete_double_quote_normal(t_interprete *env);
void				interprete_double_quote_stop(t_interprete *env);
void				interprete_back_quote(t_interprete *env);
void				interprete_value(t_interprete *env);
void				interprete_backslash(t_interprete *env);
void				interprete_tilde(t_interprete *env);
void				interprete_spacing(t_interprete *env);
void				interprete_normal(t_interprete *env);
void				interprete_null(t_interprete *env);
void				interprete_comma(t_interprete *env);
void				interprete_and(t_interprete *env);
void				interprete_or(t_interprete *env);
void				interprete_background(t_interprete *env);
void				interprete_pipe(t_interprete *env);

void				do_process(t_interprete *env);
void				process_back_quotes(t_interprete *env);

void				do_simplify(t_interprete *env);

size_t				len_normal(t_interprete *env, size_t *pos);
size_t				len_simple_quote(t_interprete *env, size_t *pos);
size_t				len_double_quote(t_interprete *env, size_t *pos);
size_t				len_back_quote(t_interprete *env, size_t *pos);
size_t				len_backslash(t_interprete *env, size_t *pos);
size_t				len_value(t_interprete *env, size_t *pos);

void				extract_normal(t_interprete *env, size_t *pos, char **ptr);
void				extract_simple_quote(t_interprete *env, size_t *pos, char **ptr);
void				extract_double_quote(t_interprete *env, size_t *pos, char **ptr);
void				extract_back_quote(t_interprete *env, size_t *pos, char **ptr);
void				extract_backslash(t_interprete *env, size_t *pos, char **ptr);
void				extract_value(t_interprete *env, size_t *pos, char **ptr);

void				init_do_interprete_tab(t_interprete *env);
void				init_interprete_value_stop(t_interprete *env);
void				init_standard_delimiters(t_interprete *env);
void				init_spaces(t_interprete *env);
void				init_should_len_tab(t_interprete *env);
void				init_extract_content_tab(t_interprete *env);
void				init_interprete_double_quote_tab(t_interprete *env);
t_interprete		*init_interpretation(void);

void				*debug_malloc(size_t size);
#endif
