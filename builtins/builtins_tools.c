#include <string.h>

char			*get_env_name(const char *line)
{
	static char	buffer[128];
	char		*ptr;

	memcpy(buffer, line, sizeof(buffer));
	buffer[sizeof(buffer) - 1] = '\0';
	ptr = buffer;
	while (*ptr && *ptr != '=')
		++ptr;
	if (*ptr == '=')
		*ptr = '\0';
	return (buffer);
}

int				env_name_match(char *cmp, char *tab)
{
	size_t		len;

	len = strlen(cmp);
	return (!strncmp(cmp, tab, len) && tab[len] == '=');
}