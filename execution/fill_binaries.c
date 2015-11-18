#include <htable.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

#include <stdio.h>

static char		*compose_path(const char *directory, size_t len, const char *file)
{
	char			*composed_path;
	const size_t	file_len = strlen(file);

	if (!(composed_path = (char *)malloc(sizeof(char) * (len + file_len + 2))))
		return (NULL);
	memcpy(composed_path, directory, len);
	composed_path[len] = '/';
	memcpy(composed_path + 1 + len, file, file_len);
	composed_path[len + file_len + 1] = '\0';
	return (composed_path);
}

static void		file_fill(hashtable_t *binaries, char *directory,
					size_t len, char file[_POSIX_PATH_MAX])
{
	char		*full_path;

	if (!(full_path = compose_path(directory, len, file)))
		return ;
	if (!(ht_get(binaries, file)))
		ht_set(binaries, strdup(file), strdup(full_path));
	(void)binaries;
	free(full_path);
}

static void		file_link(hashtable_t *binaries, char *directory,
					size_t len, char file[_POSIX_PATH_MAX])
{
	char		*full_path;

	if (!(full_path = compose_path(directory, len, file)))
		return ;
	if (!(ht_get(binaries, file)))
		ht_set(binaries, strdup(file), strdup(full_path));
	(void)binaries;
	free(full_path);
}

static void		directory_fill(hashtable_t *binaries, char *directory, size_t len)
{
	const char		c = directory[len];
	DIR				*dir;
	struct dirent	*ent;

	directory[len] = '\0';
	if ((dir = opendir (directory)) != NULL)
	{
		while ((ent = readdir(dir)) != NULL) {
			if (ent->d_type & DT_REG)
				file_fill(binaries, directory, len, ent->d_name);
			else if (ent->d_type & DT_LNK)
				file_link(binaries, directory, len, ent->d_name);
		}
		closedir(dir);
	}

	directory[len] = c;
}

void			refresh_binaries(hashtable_t *binaries)
{
	char			path[] = "/nfs/zfs-student-3/users/2014/achazal/.brew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/opt/X11/bin:/usr/texbin";
	char			*old_ptr;
	char			*new_ptr;

	ht_clear(binaries);
	(void)binaries;
	old_ptr = (char *)path;
	while (*old_ptr)
	{
		new_ptr = old_ptr;
		while (*new_ptr && *new_ptr != ':')
			++new_ptr;
		directory_fill(binaries, old_ptr, new_ptr - old_ptr);
		if (!*new_ptr)
			return ;
		old_ptr = new_ptr + 1;
	}
}
