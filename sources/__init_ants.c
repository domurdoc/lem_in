#include "lem_in.h"

bool	init_ants(t_data *data)
{
	if (data->n_ants >= 0)
		return (false);
	data->n_ants = get_num(LINE, data);
	return (true);
}
