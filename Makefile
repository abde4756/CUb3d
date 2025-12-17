NAME = cub3
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# MiniLibX configuration: override these when calling make if needed,
# e.g. `make MLX_INC=/usr/local/include MLX_LIB_DIR=/usr/local/lib`.
MLX_INC ?= ./mlx
MLX_LIB_DIR ?= ./mlx
MLX_LIBS ?= -lmlx -lX11 -lXext -lm

# get_next_line include directory (library in repo)
GNL_INC ?= ./get_next_line-20251103T142952Z-1-001/get_next_line
GNL_SRCS ?= $(GNL_INC)/get_next_line.c $(GNL_INC)/get_next_line_utils.c

SRCS = main.c graphic.c raycasting.c parcing.c utils.c textues.c verif_map.c init_ray.c parcing_2.c graphic_2.c utils_fon.c clean_fon.c help.c textur_2.c $(GNL_SRCS)

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) -I$(MLX_INC) -I$(GNL_INC) -L$(MLX_LIB_DIR) -o $(NAME) $(SRCS) $(MLX_LIBS)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
