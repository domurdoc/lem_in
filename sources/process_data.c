#include "lem_in.h"

void	process_data(t_data *data)
{
	process_prepare(data);
	while (process_bhandari(data))
	{
		if (data->best_set->iter == min_iter(data))
			break ;
	}
	if (!data->prev_set)
		exit_(GRAPH_ERROR, data);
}
