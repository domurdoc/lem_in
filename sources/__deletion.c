#include "lem_in.h"

void	words_del(char ***words)
{
	uint64_t	i;

	i = 0;
	if (*words)
	{
		while ((*words)[i])
			free((*words)[i++]);
		free(*words);
		*words = NULL;
	}
}

void	data_del(t_data *data)
{
	ar_del(&data->rooms);
	set_del(data->best_set);
	set_del(data->curr_set);
	if (data->best_set != data->prev_set)
		set_del(data->prev_set);
	words_del(&data->words);
	lst_ht_del(data->input, free);
	ar_del(&data->heap);
	vis_del(data->vis);
}
