NAME = so_long
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBS = -Lminilibx-linux -lmlx_Linux -L/usr/X11R6/lib -lXext -lX11
SOURCES_DIR = ./src

SOURCES = $(SOURCES_DIR)/check_goal.c\
		  $(SOURCES_DIR)/check_map.c\
		  $(SOURCES_DIR)/create_img.c\
		  $(SOURCES_DIR)/close_window.c\
		  $(SOURCES_DIR)/draw.c\
		  $(SOURCES_DIR)/error_mapdata.c\
		  $(SOURCES_DIR)/error.c\
		  $(SOURCES_DIR)/mlx_error.c\
		  $(SOURCES_DIR)/event.c\
		  $(SOURCES_DIR)/get_c_num.c\
		  $(SOURCES_DIR)/get_map_data.c\
		  $(SOURCES_DIR)/main.c\
		  $(SOURCES_DIR)/map.c\
		  $(SOURCES_DIR)/player_move.c\
		  $(SOURCES_DIR)/player_steps.c\
		  $(SOURCES_DIR)/window_img.c\
		  $(GNL_DIR)/get_next_line.c\
		  $(GNL_DIR)/get_next_line_utils.c\

PRINTF_DIR		= ./printf
PRINTF			= $(PRINTF_DIR)/libftprintf.a
GNL_DIR			= ./get_next_line
GNL				= $(GNL_DIR)/get_next_line.a

MINILIBX_DIR	= ./minilibx-linux
MINILIBX		= $(MINILIBX_DIR)/libmlx.a
INCLUDE			= -I printf -I minilibx-linux -I /usr/X11R6/inxlude

OBJS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(PRINTF) $(MINILIBX)
	$(CC) $(OBJS) $(PRINTF) $(LIBS) $(INCLUDE) -o $(NAME)

$(PRINTF) :
	make -C $(PRINTF_DIR)

$(MINILIBX) :
	make -C $(MINILIBX_DIR)

clean:
	make -C $(PRINTF_DIR)  clean 
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTF_DIR) fclean
	make -C $(MINILIBX_DIR)  clean 
	rm -f $(NAME)

# #======== ERROR CASE========
# error:
# 	make
# 	./so_long.a	 maps/err_cannotgoal1.ber
# 	./so_long.a	 maps/err_cannotgoal2.ber
# 	./so_long.a	 maps/err_cannotgoal3.ber
# 	./so_long.a  maps/err_wall.ber
# 	./so_long.a  maps/err_twoplayer.ber
# 	./so_long.a  maps/err_coin.ber

re: fclean all
