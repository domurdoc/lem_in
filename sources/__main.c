#include "lem_in.h"

int	main(int ac, char **av)
{
	t_data data;

	init_flags(ac, av, &data);
	init_data(&data);
	process_data(&data);
	output_data(&data);
	data_del(&data);
	return (0);
}
