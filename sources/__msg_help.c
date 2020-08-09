#include "lem_in.h"

void	msg_help(void)
{
	int		fd;
	char	*line;

	fd = open("./resources/help", O_RDONLY);
	while (ft_gnl(fd, &line) > 0)
	{
		ft_dprintf(STDERR_FILENO, "%s\n", line);
		free(line);
	}
	close(fd);
	exit(0);
}
