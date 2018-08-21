# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpatter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/24 17:28:22 by tpatter           #+#    #+#              #
#    Updated: 2018/08/21 10:38:47 by tpatter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
SRCDIR		=	srcs/
SRC			=	main.c\
				ft_readmap.c\
				ft_buildvectlist.c\
				ft_keyread.c\
				ft_render.c\
				ft_drawtoimg.c\
				ft_drawcirc.c\
				ft_buildperslist.c\
				ft_updatepers.c\
				ft_drawlinecol.c\
				ft_buildlinks.c\
				ft_mouse.c\
				ft_renderhook.c\
				ft_zscale.c\
				ft_rotate.c
SRCPATH		:=	$(addprefix $(SRCDIR), $(SRC))
OBJDIR		=	obj/
OBJ			=	$(SRC:%.c=%.o)
OBJPATH		:=	$(addprefix $(OBJDIR), $(OBJ))

HEADER		=	includes/
CFLAGS		=	-Wall -Werror -Wextra
MLXFLAGS	=	-lmlx -framework OpenGL -framework AppKit -lm
LINUXFLAGS	=	-Wl,--no-as-needed -I /usr/local/include -g  -lX11 -lXext -L. /usr/local/lib/libmlx_Linux.a -lm
CC			=	gcc
LIBDIR		=	libft/
LIB			=	$(LIBDIR)libft.a
LIBHEAD		=	$(LIBDIR)includes/
LIBLINK		=	-L $(LIBDIR) -l ft
INCLUDES	=	-I $(HEADER) -I $(LIBHEAD)

all: $(NAME)

$(NAME): $(OBJPATH) $(LIB)
	$(CC) -o $(NAME) $(MLXFLAGS) $(SRCPATH) $(LIBLINK) $(INCLUDES) $(CFLAGS) 

linux: $(LIB)
	$(CC) -o $(NAME) -Wl,--no-as-needed -I /usr/local/include -g  -lX11 -lXext $(SRCPATH)  -L. /usr/local/lib/libmlx_Linux.a -lm $(INCLUDES) $(LIBLINK)

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(LIB):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJPATH)
	make -C $(LIBDIR) clean

fclean:	clean
	rm -rf $(NAME)
	make -C $(LIBDIR) fclean

re: fclean all
