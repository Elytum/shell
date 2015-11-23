#include <escape.h>

#include <unistd.h>
#include <string.h>

#include <stdio.h>

#define STRING "begin 'first' se\\cond thi\"r\"d four\\ th fi\\f\\t\\h  \t end"

void			handle_backslash(char **str, size_t *len)
{
	if (!(*str)[1])
	{
		*str = NULL;
		return ;
	}
	memcpy(*str, *str + 1, *len - 1);
	(*str)[*len - 1] = '\0';
	*str += 1;
	*len -= 2;
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
	const char	message[] = "Size: ";

	write(1, message, sizeof(message) - 1);
		//	ft_putnbr(escaped.size);
	write(1, "\n", 1);
	if (escaped.size)
		do_put_escaped(escaped.string, escaped.string, escaped.size);
}

void			handle_spaces(char **str, size_t *len)
{
	char		*ptr;

	**str = '\0';
	ptr = ++*str;
	while (*ptr == ' ' || *ptr == '\t')
		++ptr;
	memcpy(*str, ptr, *len - (ptr - *str));
	*len -= ptr - *str + 1;
}

void			handle_simple_quotes(char **str, size_t *len)
{
	char		*ptr;

	ptr = *str + 1;
	while (*ptr && *ptr != '\'')
		++ptr;
	if (!*ptr)
	{
		*str = NULL;
		return ;
	}
	memcpy(*str, *str + 1, ptr - *str - 1);
	memcpy(ptr - 1, ptr + 1, *len - (ptr - *str));
	(*str)[*len - 1] = '\0';
	*str = ptr - 1;
	*len -= 2;
}

void			handle_double_quotes(char **str, size_t *len)
{

	char		*ptr;

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
	memcpy(*str, *str + 1, ptr - *str - 1);
	memcpy(ptr - 1, ptr + 1, *len - (ptr - *str));
	(*str)[*len - 1] = '\0';
	*str = ptr - 1;
	*len -= 2;
}

t_escape		escape_string(char *str)
{
	t_escape	escaped;
	size_t		len;

	escaped.origin = str;
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

void			escaped_reset(t_escape *escaped)
{
	escaped->string = escaped->origin;
}

void			escaped_free(t_escape *escaped)
{
	free(escaped->origin);
	escaped->origin = NULL;
	escaped->string = NULL;
	escaped->size = 0;
}

int				main(void)
{
	char		*str;
	t_escape	escaped;

	escaped = escape_string(strdup(STRING));
	put_escaped(escaped);
	escaped_free(&escaped);
	put_escaped(escaped);
	// while ((str = for_each_escaped(&escaped)))
		// printf("Str: [%s]\n", str);
	return (0);
}
