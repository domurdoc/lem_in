#include "lem_in.h"

void	exit_(int status, t_data *data)
{
	data_del(data);
	exit(status);
}
