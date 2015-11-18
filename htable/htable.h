#ifndef HTABLE_H
# define HTABLE_H
# include <stdlib.h>

typedef struct			entry_s {
	char				*key;
	void				*value;
	struct entry_s		*next;
}						entry_t;

typedef struct			hashtable_s {
	int					size;
	struct entry_s		**table;	
}						hashtable_t;

hashtable_t		*ht_create( int size );
int				ht_hash( hashtable_t *hashtable, char *key );
entry_t			*ht_newpair( char *key, void *value );
void			ht_set( hashtable_t *hashtable, char *key, void *value );
void			*ht_get( hashtable_t *hashtable, char *key );
void			ht_remove( hashtable_t *hashtable, char *key );
void			ht_free(hashtable_t *hashtable);
void			ht_clear(hashtable_t *hashtable);

#endif
