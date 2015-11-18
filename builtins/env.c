#include <builtins.h>
#include <string.h>

void			builtin_env(t_env *env)
{
	(void)env;
	// char		buffer[ENV_TABLE_SIZE * (ENV_TABLE_CONTENT_SIZE + 1) + 1];
	// size_t		pos;
	// size_t		element;
	// size_t		len;

	// pos = 0;
	// element = 0;
	// while (element < ENV_TABLE_SIZE && env->env_table[element][0])
	// {
	// 	len = strlen(env->env_table[element]);
	// 	memcpy(buffer + pos, env->env_table[element], len);
	// 	pos += len;
	// 	buffer[pos++] = '\n';
	// 	++element;
	// }
	// write(1, buffer, pos);
}