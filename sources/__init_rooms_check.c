#include "lem_in.h"

static void	check_names(t_data *data)
{
	size_t	i;

	i = 0;
	while (++i < N_ROOMS)
		if (!cmp_names(ROOM(i), ROOM(i - 1)))
		{
			data->k = i - 1;
			exit_(DROOM_ERROR, data);
		}
}

void		init_rooms_check(t_data *data)
{
	if (ROOM(N_ROOMS - 1) == START || ROOM(N_ROOMS - 1) == END
		|| !START || !END)
		exit_(RBLOCK_ERROR, data);
	room_del(ROOM(--N_ROOMS));
	(void)ar_quicksort(data->rooms);
	check_names(data);
	if (RAND_MODE && VIS_MODE)
		init_coord_check(data);
}