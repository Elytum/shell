#include <sys/stat.h>

char			executable_file(const char *path)
{
	struct stat		sb;

	return (stat(path, &sb) == 0 && sb.st_mode & S_IXUSR);
}

char			executable_link(const char *path)
{
	struct stat		sb;

	return (lstat(path, &sb) == 0 && sb.st_mode & S_IXUSR);
}