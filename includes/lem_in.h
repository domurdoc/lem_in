/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domurdoc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 15:09:04 by domurdoc          #+#    #+#             */
/*   Updated: 2020/08/10 02:40:19 by domurdoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <stdbool.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"
# include "lem_in_types.h"

# define IMG_H			768
# define IMG_W			1024
# define IMG_VB			40
# define IMG_HB			40

# define LINE_COLOR		0xFFFFFF
# define SROOM_COLOR	0x0000FF
# define EROOM_COLOR	0xFF0000
# define BACKGROUND		0x0
# define MENU_COLOR		0x70 << 16 | 0x70 << 8 | 0x70

# define ROOM_SIZE		30
# define STEPS			10

# define VERBOSE		0x1
# define PATHS_NUM		0x2
# define SHOW_PATHS		0x4
# define IGNORE_LINKS	0x8
# define GRAPHICS		0x10
# define RANDOMIZE		0x20

# define MLX_ERROR		-4
# define IOERROR		-3
# define GNL_ERROR		-2
# define MEMORY_ERROR	-1

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
t_room		*find_room(t_array *ar, char *name);


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
** OUTPUT
*/

void		output_data(t_data *data);
void		output_prepare(t_data *data);
void		output_input(t_data *data);
bool		output_line(t_data *data);
void		output_short(t_data *data);

/*
** OUTPUT EXTRA
*/

void		show_paths(t_data *data);
void		show_total_0(void);
void		show_total_1(t_data *data);
void		show_total(t_data *data);

/*
** OUTPUT UTILITY
*/

void		nbr_recursion(int32_t n, char **str);
void		ant_name(int32_t n, char *str);
void		buff_fill(const char *src, t_data *data);
void		buff_flush(t_data *data);

/*
** MESSAGES
*/

void		msg(int status, t_data *data);
void		msg_success(t_data *data);
void		msg_help(void);
void		msg_usage(void);
void		msg_error(int status, t_data *data);
void		msg_error_number(t_data *data);
void		msg_error_start_room(t_data *data);
void		msg_error_end_room(t_data *data);
void		msg_error_room_name(t_data *data);
void		msg_error_input_udefined(t_data *data);
void		msg_error_no_name1(t_data *data);
void		msg_error_no_name2(t_data *data);
void		msg_error_link_itself(t_data *data);
void		msg_error_link_exists(t_data *data);
void		msg_error_rooms_block(t_data *data);
void		msg_error_duplicate_room(t_data *data);
void		msg_error_duplicate_coord(t_data *data);
void		msg_error_graph(t_data *data);
void		msg_error_last_line(t_data *data);

/*
** VIS
*/

void		vis_data(t_data *data);
void		vis_prepare(t_data *data);
void		line_to_image(t_point p1, t_point p2, int8_t **img);
int			keyboard_control(int key, t_data *data);
void		clear_img(int8_t **img, int w, int h);
void		put_img_tunnels(t_data *data);
void		put_img_ant(t_ant *ant, t_data *data);
void		put_img_rooms(t_data *data);
void		draw_template(t_data *data);
void		draw_tunnels(t_data *data);
int			vis_move(t_data *data);

void		show_info(t_data *data);
void		show_menu(t_data *data);
void		show_intro_1(t_data *data);
void		show_intro_2(t_data *data);
void		show_rooms(t_data *data);

void		vis_del(t_vis *vis);
void		flush(t_data *data);
void		room_rand(t_data *data);
void		reset_set(t_data *data);

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
** PATH
*/

void		path_del(void *p);
void		*path_convert(void *p0);

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
