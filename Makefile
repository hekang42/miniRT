# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/03/14 18:41:59 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= img_utils.c main.c mlx_utils.c ray_utils.c vec_calc_apply.c vec_calc.c vec_create.c \
		vec_calc_extra.c cal_utils.c cam_utils.c sphere.c hitlst_utils.c hittable_utils.c \
		draw_hittable.c hit_record.c plane.c light.c ambient.c parse.c \
		gnl/get_next_line.c parse_base.c parse_obj.c triangle.c shadow.c square.c cylinder.c \
		cylinder_bonus.c parse_obj_bonus.c cal_color.c bmp_save.c \
		free_array.c free_base.c free_obj.c free_obj_2.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a
MLXDIR	= ./mlx/
MLXNAME = libmlx.dylib

NAME	= miniRT

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra
#  -g -fsanitize=address
RM 		= rm -f

%.o:		%.c
		$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME) $(MLXNAME) $(OBJS)
		$(GCC) $(GCCFLAG) -I$(INCDIR) -L$(MLXDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
		@$(MAKE) -C $(LIBDIR) bonus
		@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

$(MLXNAME):
		@$(MAKE) -C $(MLXDIR)
		@cp $(addprefix $(MLXDIR), $(MLXNAME)) $(MLXNAME)

all:		$(NAME)

clean:
		$(RM) $(OBJS) *.bmp

fclean:		clean
		$(RM) $(NAME) $(LIBNAME) $(MLXNAME)
		@$(MAKE) -C $(LIBDIR) fclean
		@$(MAKE) -C $(MLXDIR) clean

re:			fclean all

.PHONY:		all clean fclean re
