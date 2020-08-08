#include "lem_in.h"

static t_room	*room_new(void)
{
	t_room	*new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	if (!(new->origin = node_new(new, DEFAULT_L, free)))
	{
		free(new);
		return (NULL);
	}
	new->name = NULL;
	new->coord.x = -1;
	new->coord.y = -1;
	new->primed = NULL;
	new->is_path = false;
	return (new);
}

void			room_add(t_data *data)
{
	t_room	*new;

	if (!(new = room_new()))
		exit_(MEMORY_ERROR, data);
	if (ar_add(data->rooms, new))
	{
		room_del(new);
		exit_(MEMORY_ERROR, data);
	}
}

void			room_del(void *r)
{
	free(((t_room*)r)->name);
	node_del(((t_room*)r)->origin);
	node_del(((t_room*)r)->primed);
}
