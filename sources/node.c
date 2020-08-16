/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 13:04:44 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/16 15:24:19 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_node	*node_new(t_room *r, uint32_t n_links)
{
	t_node	*new;

	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	new->r = r;
	if (!(new->links = ar_new(n_links, free)))
	{
		free(new);
		return (NULL);
	}
	new->links->cmp = cmp_links;
	if (!(new->links_saved = ar_new(2, NULL)))
	{
		free(new->links);
		free(new);
		return (NULL);
	}
	if (!(new->itself = link_new(new, -1)))
	{
		free(new->links);
		free(new->links_saved);
		free(new);
		return (NULL);
	}
	return (new);
}

void	node_del(t_node *n)
{
	if (!n)
		return ;
	ar_del(&n->links);
	ar_del(&n->links_saved);
	free(n->itself);
	free(n);
}
