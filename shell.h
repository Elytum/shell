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
# include <interprete.h>
# include <config.h>

# include <limits.h>
# include <stdlib.h>

#include <stdio.h>

typedef struct		s_alias
{
	char			*string;
	size_t			size;
}					t_alias;

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

	t_interprete	*interpretation;

// INTERPRETE DUPLICATION

	hashtable_t		*local_variables;
	hashtable_t		*alias;
	hashtable_t		*builtins;
	hashtable_t		*binaries;
}					t_env;

# include <execution.h>

#endif
