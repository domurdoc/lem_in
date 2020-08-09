#include "lem_in.h"

#define CRD(i)	((t_chk_crd*)data->heap->data[(i)])

void	msg_error_rooms_block(t_data *data)
{
	ft_dprintf(STDERR_FILENO, "rooms block not finished\n");
	if (ROOM(N_ROOMS - 1) == START || !START)
		ft_dprintf(STDERR_FILENO, "- %{5}start%{0} room not defined\n");
	if (ROOM(N_ROOMS - 1) == END || !END)
		ft_dprintf(STDERR_FILENO, "- %{5}end%{0} room not defined\n");
	msg_error_last_line(data);
}

void	msg_error_duplicate_room(t_data *data)
{
	int64_t	i;
	char	*name;

	i = data->k + 2;
	name = ROOM(data->k)->name;
	while (i < N_ROOMS && ft_strequ(ROOM(i)->name, name))
		i++;
	ft_dprintf(STDERR_FILENO, "%d rooms with name %{5}\"%s\"%{0}\n",
		i - data->k, name);
}

void	msg_error_duplicate_coord(t_data *data)
{
	int64_t		i;
	uint64_t	coord;

	i = data->k + 2;
	coord = CRD(data->k)->crd;
	while (i < N_ROOMS && CRD(i)->crd == coord)
		i++;
	ft_dprintf(STDERR_FILENO, "%d rooms with coordinates %{5}(%d, %d)%{0}:\n",
			i - data->k, coord >> 32, coord & 0xFFFF);
	while (data->k < i)
		ft_dprintf(STDERR_FILENO, "- %{2}\"%s\"%{0}\n", CRD(i)->r->name);
}

void	msg_error_graph(t_data *data)
{
	ft_dprintf(STDERR_FILENO,
		"no path between %{5}\"%s\"%{0} and %{5}\"%s\"%{0}\n",
			START->name, END->name);
}
