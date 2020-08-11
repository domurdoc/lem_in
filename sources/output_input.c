#include "lem_in.h"

void	output_input(t_data *data)
{
	char	*line;

	while ((line = lst_ht_pop(data->input)))
	{
		buff_fill(line, data);
		buff_fill("\n", data);
		free(line);
	}
	buff_fill("\n", data);
	buff_flush(data);
	ft_memdel((void**)&data->input);
}
