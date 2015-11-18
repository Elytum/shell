#ifndef CONFIG_H
# define CONFIG_H

#define INTERPRETED 0
# define SIMPLE_QUOTED 1
# define DOUBLE_QUOTED 2
# define BACK_QUOTED 3
# define BACKSLASHED 4
# define START_LOCAL_VARIABLE 5

# define MAX_BASIC_INTERPRETATION 6

# define SPACING 6
# define LOCAL_VARIABLE 7
# define ALONE_LOCAL_VARIABLE 8
# define TILDE 9
# define DELIMITER 10
# define REMOVE 11

# define NO_TOKEN 0
# define COMMA 1
# define AND 2
# define OR 3
# define PIPE 4
# define BACKGROUND 5

# define STOP 0
# define CONTINUE 1
# define NOT_CLOSED 2

#endif