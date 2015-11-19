#include <escape.h>

#include <unistd.h>
#include <string.h>

#include <stdio.h>

// #define STRING "abc \t \t\t 'd e f'"
#define STRING "abc     'd e f'"

void			handle_spaces(char **str, size_t *len)
{
	char		*ptr;

	ptr = ++*str;
	while (*ptr == ' ' || *ptr == '\t')
		++ptr;
	memcpy(*str, ptr, *len - (ptr - *str));
	*len -= ptr - *str;
	*str = ptr;
}

void			handle_simple_quotes(char **str, size_t *len)
{
	char		*ptr;

	ptr = *str;
	while (*ptr && *ptr != '\'')
		++ptr;
	if (!*ptr)
	{
		*str = NULL;
		return ;
	}

	printf("Before: [%s], len: %lu", *str, *len - (ptr - *str) - 3);
	memcpy(*str, *str + 1, *len - (ptr - *str) - 3);
	printf(" After: [%s]", *str);
	printf(" new len: %lu", *len - 3);
	(*str)[*len - 3] = '\0';
	printf(" After: [%s]\n", *str);

	*str = ptr + 4;
	*len -= 2;
}

// void			handle_double_quotes(char **str, size_t *len)
// {
// 	char		*ptr;

// 	ptr = ++*str;
// 	while (*ptr && *ptr != '"')
// 		++ptr;
// 	*str = *ptr;
// }

t_escape		escape_string(char *str)
{
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
		printf("\t\tString: [%s]\n", str);
		if (*str == ' ' || *str == '\t')
		{
			handle_spaces(&str, &len);
			++escaped.size;
		}
		// else if (*str == '\'')
		// 	handle_simple_quotes(&str, &len);
		// else if (*str == '\"')
		// 	handle_double_quotes(&str, &len);
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

	// str = strdup(STRING);
	// escaped = escape_string(str);
	
	// if (!(escaped.string = (char *)malloc(sizeof(char) * 4096)))
	// 	return (-1);
	// memcpy(escaped.string, TEST, sizeof(TEST));
	// escaped.size = 2;
	escaped = escape_string(strdup(STRING));
	put_escaped(escaped);

	// while ((str = for_each_escaped(&escaped)))
		// printf("str = [%s]\n", str);
		// str = for_each_escaped(&escaped);
		// 	printf("str = [%s]\n", str);
		// put_escaped(escaped);
	return (0);
}
