#include "lem_in.h"

void	init_data(t_data *data)
{
	init_prepare(data);
	init_line_process(data, init_ants);
	init_ants_check(data);
	init_line_process(data, init_rooms);
	init_rooms_check(data);
	init_line_process(data, init_links);
	init_simple_check(data);
	if (data->flags & GRAPHICS)
		vis_prepare(data);
}
