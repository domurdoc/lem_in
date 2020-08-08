#include "lem_in.h"

static bool	get_line(char **line, t_data *data)
{
	int	ret;

	if (*line)
		return (true);
	if ((ret = ft_gnl(STDIN_FILENO, line)) < 0)
		exit_(GNL_ERROR, data);
	else if (ret)
	{
		if (lst_ht_push_back(data->input, *line))
		{
			free(*line);
			exit_(MEMORY_ERROR, data);
		}
	}
	return (ret);
}

void		init_line_process(t_data *data, bool (*func)(t_data*))
{
	static char	*line = NULL;

	while (get_line(&line, data))
	{
		words_del(&data->words);
		if (!func(data))
			break ;
		line = NULL;
	}
}
