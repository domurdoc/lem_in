#include "lem_in.h"

int	main()
{
	t_data data;

	init_data(&data);
	process_data(&data);
	output_data(&data);
	data_del(&data);
	return (0);
}
