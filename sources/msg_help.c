/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_help.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:37 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/11 13:04:38 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
