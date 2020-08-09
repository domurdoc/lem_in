#include "lem_in.h"

void	msg(int status, t_data *data)
{
	if (status)
		msg_error(status, data);
	else if (data->flags & VERBOSE)
		msg_success(data);
}
