#include "lem_in.h"

void	output_data(t_data *data)
{
	output_prepare(data);
	output_input(data);
	while (output_line(data))
		;
	if (data->flags & SHOW_PATHS)
		show_paths(data);
	if (data->flags & PATHS_NUM)
		show_total(data);
}
