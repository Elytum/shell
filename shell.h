#ifndef SHELL_H
# define SHELL_H

#define ERROR 0
#define NO_ERROR 1
#define TRUE 0
#define FALSE 1

#define NORMAL_EXIT 0
#define ERROR_EXIT -1

#define SHELL_NAME "GladoSH"

# include <htable.h>
# include <config.h>

# include <limits.h>
# include <stdlib.h>

typedef struct		s_alias
{
	char			*string;
	size_t			size;
}					t_alias;

typedef struct		s_interprete
{
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

	size_t			(*should_len_tab[MAX_BASIC_INTERPRETATION])(struct s_env *env, size_t *pos);
	void			(*extract_content_tab[MAX_BASIC_INTERPRETATION])(struct s_env *env, size_t *pos, char **ptr);

	hashtable_t		*local_variables;
	hashtable_t		*alias;
	hashtable_t		*builtins;
	hashtable_t		*binaries;

	void			(*do_interprete_tab[256])(struct s_env *env);
	char			interprete_double_quote_tab[256];
	char			interprete_value_stop[256];
	char			standard_delimiters[256];
	char			spaces[256];
}					t_interprete;

typedef struct		s_env
{
	char			*intro;
	
	char			line[_POSIX2_LINE_MAX];

	char			*argv[_POSIX_ARG_MAX];
	int				argc;
	
	char			pwd[_POSIX_PATH_MAX];
	char			home[_POSIX_PATH_MAX];
	size_t			pwd_len;
	size_t			home_len;

	char			error;
	char			multiline;

// INTERPRETE DUPLICATION

	// char			extra_memory[_POSIX2_LINE_MAX];
	// size_t		extra_memory_size;

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

	size_t			(*should_len_tab[MAX_BASIC_INTERPRETATION])(struct s_env *env, size_t *pos);
	void			(*extract_content_tab[MAX_BASIC_INTERPRETATION])(struct s_env *env, size_t *pos, char **ptr);

	hashtable_t		*local_variables;
	hashtable_t		*alias;
	hashtable_t		*builtins;
	hashtable_t		*binaries;

	void			(*do_interprete_tab[256])(struct s_env *env);
	char			interprete_double_quote_tab[256];
	char			interprete_value_stop[256];
	char			standard_delimiters[256];
	char			spaces[256];
}					t_env;

# include <execution.h>

#endif
