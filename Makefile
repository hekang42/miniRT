# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hekang <hekang@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/14 00:08:03 by hekang            #+#    #+#              #
#    Updated: 2021/02/25 14:24:59 by hekang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= img_utils.c main.c mlx_utils.c ray_utils.c vec_calc_apply.c vec_calc.c vec_create.c \
		vec_calc_extra.c cal_utils.c cam_utils.c sky_utils.c sphere.c hitlst_utils.c hittable_utils.c \
		draw_hittable.c hitlst_info_utils.c hit_record.c plane.c light.c ambient.c parse.c \
		gnl/get_next_line.c parse_base.c parse_obj.c triangle.c shadow.c square.c cylinder.c

SRCDIR	= ./srcs/
SRCS 	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(SRCS:.c=.o)

INCDIR	= ./includes/
LIBDIR	= ./libft/
LIBNAME = libft.a
# MLXDIR	= ./mlx/
MLXNAME = libmlx.dylib

NAME	= minirt

GCC 	= GCC
GCCFLAG = -Wall -Werror -Wextra -g -fsanitize=address
RM 		= rm -f

%.o:		%.c
			$(GCC) $(GCCFLAG) -I$(INCDIR) -c $< -o $@

$(NAME):	$(LIBNAME)  $(OBJS) 
			$(GCC) $(GCCFLAG) -I$(INCDIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBNAME) $(MLXNAME)

$(LIBNAME):
			@$(MAKE) -C $(LIBDIR) bonus
			@cp $(addprefix $(LIBDIR), $(LIBNAME)) $(LIBNAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME) $(LIBNAME)
			@$(MAKE) -C $(LIBDIR) fclean

re:			fclean all

.PHONY:		all clean fclean re
