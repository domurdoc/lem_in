#include "lem_in.h"

int	main()
{
	t_data data;

//	init_flags(ac, av, &data);
	init_data(&data);
	ft_printf("reading done\n");
	process_data(&data);
	data_del(&data);
	ft_printf("done\n");
	return (0);
}
