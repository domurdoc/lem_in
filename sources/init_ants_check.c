#include "lem_in.h"

void	init_ants_check(t_data *data)
{
	if (data->n_ants < 0)
		exit_(IUNDEF_ERROR, data);
}
