#include "lem_in.h"

void	init_simple_check(t_data *data)
{
	if (!data->n_ants)
	{
		output_input(data);
		if (data->flags & PATHS_NUM)
			show_total_0();
		exit_(OK, data);
	}
	else if (link_exists(START, END))
	{
		output_input(data);
		output_short(data);
		if (data->flags & PATHS_NUM)
			show_total_1(data);
		if (data->flags & SHOW_PATHS)
			show_paths(data);
		exit_(OK, data);
	}
}
