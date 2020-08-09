CC = gcc
FLAGS = -Wall -Wextra -Werror -g3 -O3

# PROGRAM name

NAME = lem-in

# PROGRAM src & obj

SRC_DIR = sources
OBJ_DIR = objects

#__init_flags.c

SRC_NAMES = __deletion.c \
	__exit.c \
	__init_ants.c \
	__init_ants_check.c \
	__init_coord_check.c \
	__init_data.c \
	__init_line_process.c \
	__init_links.c \
	__init_prepare.c \
	__init_rooms.c \
	__init_rooms_check.c \
	__init_simple_check.c \
	__init_utility.c \
	__link.c \
	__main.c \
	__node.c \
	__output_data.c \
	__output_input.c \
	__output_line.c \
	__output_prepare.c \
	__output_utility.c \
	__path.c \
	__process_bhandari.c \
	__process_data.c \
	__process_dijkstra.c \
	__process_mod_graph.c \
	__process_prepare.c \
	__process_rest_graph.c \
	__process_set.c \
	__process_utility.c \
	__room.c \
	__set.c \
	__utility.c

OBJ_NAMES = $(SRC_NAMES:.c=.o)

OBJ = $(addprefix $(OBJ_DIR)/, $(OBJ_NAMES))

# PROGRAM headers

INCL_NAMES = lem_in.h lem_in_types.h
INCL_DIR = includes

INCL = $(addprefix $(INCL_DIR)/, $(INCL_NAMES))

# LIBFT

LIB_NAME = libft.a
LIB_DIR = libft
LIB_INCL_DIR = $(addprefix $(LIB_DIR)/, $(INCL_DIR))
LIBFT = $(addprefix $(LIB_DIR)/, $(LIB_NAME))

# RULES

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) -o $@ $(OBJ) $(LIBFT)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCL)
	$(CC) -I$(INCL_DIR) -I$(LIB_INCL_DIR) -o $@ -c $< $(FLAGS)

$(LIBFT): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:	
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
