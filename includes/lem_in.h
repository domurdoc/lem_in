/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:09:04 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/09 01:43:32 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdbool.h>
# include "libft.h"
# include "lem_in_types.h"

# define VERBOSE		0x1
# define PATHS_NUM		0x2
# define SHOW_PATHS		0x4
# define IGNORE_LINKS	0x8
# define GRAPHICS		0x10
# define RANDOMIZE		0x20

# define IOERROR		-5
# define MLX_ERROR		-4
# define MEMORY_ERROR	-3
# define RNUMBER_ERROR	-2
# define LNUMBER_ERROR	-1

# define OK				0

# define NUMBER_ERROR	1
# define SROOM_ERROR	2
# define EROOM_ERORR	3
# define NAME_ERROR		4
# define RBLOCK_ERROR	5
# define DROOM_ERROR	6
# define DCOORD_ERROR	7
# define IUNDEF_ERROR	8
# define LNAME1_ERROR	9
# define LNAME2_ERROR	10
# define LITSELF_ERROR	11
# define LEXISTS_ERROR	12
# define GRAPH_ERROR	13
# define GNL_ERROR		14


# define DEFAULT_R		1024
# define DEFAULT_L		32
# define DEFAULT_P		32

# define START			data->start_room
# define END			data->end_room
# define LINE			((char*)data->input->tail->data)
# define ROOM(i)		((t_room*)data->rooms->data[(i)])
# define N_ROOMS		data->rooms->len

# define PRIMED			(origin->r->primed)
# define SUCC			(origin->succ)

# define RAND_MODE		(data->flags & RANDOMIZE)
# define VIS_MODE		(data->flags & GRAPHICS)
# define IGNORE_MODE	(data->flags & IGNORE_LINKS)

/*
** INIT
*/

void		init_flags(int ac, char **av, t_data *data);
void		init_data(t_data *data);
void		init_prepare(t_data *data);
bool		init_ants(t_data *data);
bool		init_rooms(t_data *data);
bool		init_links(t_data *data);

void		init_ants_check(t_data *data);
void		init_rooms_check(t_data *data);
void		init_coord_check(t_data *data);
void		init_simple_check(t_data *data);

void		init_line_process(t_data *data, bool (*func)(t_data*));

/*
** INIT UTILITY
*/

int32_t		get_num(char *str, t_data *data);
uint64_t	count_ch(char *str, char ch);
uint64_t	count_words(char **words);
bool		comment(t_data *data);


/*
** PROCESS
*/

void		process_data(t_data *data);
void		process_prepare(t_data *data);
void		process_mod_graph(t_data *data);
void		process_rest_graph(t_data *data);
bool		process_bhandari(t_data *data);
bool		process_dijkstra(t_data *data);
void		process_save_set(t_data *data);
void		process_choose_set(t_data *data);

/*
** PROCESS UTILITY
*/

int32_t		min_iter(t_data *data);
void		backtrack(t_data *data, void (*func)(t_node*, t_data*));

/*
** ROOM
*/

void		room_add(t_data *data);
void		room_del(void *r);

/*
** NODE
*/

t_node		*node_new(t_room *r, uint32_t n_links, void (*del)(void*));
void		node_del(t_node *n);

/*
** LINK
*/

t_link		*link_new(t_node *n, int32_t w);
void		link_add(t_room *r1, t_room *r2, int32_t w, t_data *data);
bool		link_exists(t_room *r1, t_room *r2);

/*
** SET
*/

t_set		*set_new(void);
void		set_del(t_set *s);


/*
** UTILITY
*/

int			cmp_names(void *r1, void *r2);
int			cmp_dist(void *n1, void *n2);
int			cmp_crd(void *crd1, void *crd2);
int			cmp_links(void *l1, void *l2);
void		exit_(int status, t_data *data);
void		data_del(t_data *data);
void		words_del(char ***words);

#endif