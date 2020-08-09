#include "lem_in.h"

void	msg_usage(void)
{
	char	*msg;

	msg = "lem-in: undefined combination\ntry 'lem-in -h' for more information";
	ft_dprintf(STDERR_FILENO, "%s\n", msg);
	exit(1);
}
