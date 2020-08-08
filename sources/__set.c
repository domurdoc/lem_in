#include "lem_in.h"

static void	path_del(void *p)
{
	lst_ht_del((t_lst_ht*)p, NULL);
}

t_set		*set_new(void)
{
	t_set	*new;

	if (!(new = malloc(sizeof(t_set))))
		return (NULL);
	if (!(new->paths = ar_new(DEFAULT_P, path_del)))
	{
		free(new);
		return (NULL);
	}
	new->length = 0;
	new->iter = 0;
	new->div = 0;
	new->mod = 0;
	return (new);
}

void		set_del(t_set *s)
{
	if (s)
	{
		ar_del(&s->paths);
		free(s);
	}
}
