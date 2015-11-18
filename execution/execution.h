#ifndef EXECUTION_H
# define EXECUTION_H

#include <shell.h>

void			refresh_binaries(hashtable_t *binaries);
void			launch_command(t_env *env);
char			executable_file(const char *path);
char			executable_link(const char *path);

#endif
