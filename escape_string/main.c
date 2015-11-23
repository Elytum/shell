#include <escape.h>

#include <unistd.h>
#include <string.h>

#include <stdio.h>

#define STRING "abc\\ \"d \\b f\" ls"

void			handle_backslash(char **str, size_t *len)
{
	printf("Before handle_backslash:\t[%s]\n", *str);
	if (!(*str)[1])
	{
		*str = NULL;
		return ;
	}
	memcpy(*str, *str + 1, *len - 1);
	(*str)[*len - 1] = '\0';
	*str += 1;
	*len -= 2;
	printf("After  handle_backslash:\t[%s]\n", *str);
}

static void		do_put_escaped(char *begin, char *ptr, size_t size)
{
	while (*ptr)
		++ptr;
	if (size == 1)
	{
		*ptr = '\n';
		write(1, begin, ptr - begin + 1);
		*ptr = '\0';
	}
	else
	{
		*ptr = ' ';
		do_put_escaped(begin, ptr + 1, size - 1);
		*ptr = '\0';
	}
}

void			put_escaped(const t_escape escaped)
{
	printf("Size: %zu\n", escaped.size);
	if (escaped.size)
		do_put_escaped(escaped.string, escaped.string, escaped.size);
}

void			handle_spaces(char **str, size_t *len)
{
	char		*ptr;

	printf("Before handle_spaces:\t\t[%s]\n", *str);
	**str = '\0';
	ptr = ++*str;
	while (*ptr == ' ' || *ptr == '\t')
		++ptr;
	memcpy(*str, ptr, *len - (ptr - *str));
	*len -= ptr - *str + 1;
	printf("After  handle_spaces:\t\t[%s]\n", *str);
}

void			handle_simple_quotes(char **str, size_t *len)
{
	char		*ptr;

	printf("Before handle_simple_quotes:\t[%s]\n", *str);
	ptr = *str + 1;
	while (*ptr && *ptr != '\'')
		++ptr;
	if (!*ptr)
	{
		*str = NULL;
		return ;
	}
	memcpy(*str, *str + 1, *len - (ptr - *str) + 1);
	memcpy(ptr - 1, ptr + 1, *len - (ptr - *str));
	*str = ptr - 1;
	(*str)[*len - 2] = '\0';
	*len -= 2;
	printf("After  handle_simple_quotes:\t[%s]\n", *str);
}

void			handle_double_quotes(char **str, size_t *len)
{

	char		*ptr;

	printf("Before handle_simple_quotes:\t[%s]\n", *str);
	ptr = *str + 1;
	while (*ptr && *ptr != '"')
	{
		if (*ptr == '\\')
		{
			handle_backslash(&ptr, len);
			if (!ptr)
			{
				*str = NULL;
				return ;
			}
		}
		else
			++ptr;
	}
	if (!*ptr)
	{
		*str = NULL;
		return ;
	}
	printf("\tBefore memcpy 1: [%s]\n", *str);
	memcpy(*str, *str + 1, *len - (ptr - *str) + 1);
	printf("\tBefore memcpy 2: [%s]\n", *str);
	memcpy(ptr - 1, ptr + 1, *len - (ptr - *str));
	printf("\tAfter memcpies: [%s]\n", *str);
	*str = ptr - 1;
	(*str)[*len - 2] = '\0';
	*len -= 2;
	printf("After  handle_simple_quotes:\t[%s]\n", *str);
}

t_escape		escape_string(char *str)
{
	const char	*origin = str;
	t_escape	escaped;
	size_t		len;

	escaped.string = str;
	if (!*escaped.string)
	{
		escaped.size = 0;
		return (escaped);
	}
	escaped.size = 1;
	len = strlen(str);
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
		{
			handle_spaces(&str, &len);
			++escaped.size;
			printf("Space detected in %li\n", str - origin);
			put_escaped(escaped);
		}
		else if (*str == '\'')
			handle_simple_quotes(&str, &len);
		else if (*str == '\"')
			handle_double_quotes(&str, &len);
		else if (*str == '\\')
			handle_backslash(&str, &len);
		else
		{
			++str;
			--len;
		}
		if (!str)
		{
			free(str);
			escaped.string = NULL;
			escaped.size = 0;
		}
	}
	return (escaped);
}

char			*for_each_escaped(t_escape *escaped)
{
	char		*ptr;

	if (escaped->size == 0)
		return (NULL);
	ptr = escaped->string;
	while (*escaped->string)
		++escaped->string;
	++escaped->string;
	--escaped->size;
	return (ptr);
}

int				main(void)
{
	char		*str;
	t_escape	escaped;

	escaped = escape_string(strdup(STRING));
	put_escaped(escaped);
	return (0);
}
