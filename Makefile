# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 13:56:12 by nibernar          #+#    #+#              #
#    Updated: 2023/08/15 17:56:20 by nicolasbern      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		=	push_swap

#########################
#	HEADER FOLDERS		#
#########################

HEADER_PATH	= ./include/
HEADER_FILES = push_swap.h
HEADERS = $(addprefix $(HEADER_PATH), $(HEADER_FILES))

#########################
#	 LIBFT FOLDERS		#
#########################

LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libft.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

#########################
#	FOLDERS AND NAMES	#
#########################

SRCS		=	src/push_swap.c\
				src/utils.c\
				src/utils_lst.c\
				src/ft_index_binary.c\
				src/check_error.c\
				src/sort_min.c\
				src/sort_medium.c\
				src/sort_max.c\
				src/push.c\
				src/swap.c\
				src/rotate.c\
				src/reverse_rotate.c\


OBJS		=	${SRCS:.c=.o}

#########################
# 	COMPILER OPTIONS	#
#########################

CFLAG		=	-Wall -Wextra -Werror
CC			=	cc

#########################
# 		RULES			#
#########################

all : lib ${NAME}

./src/%.o: ./src/%.c ${HEADERS} ${LIBFT_LIB}
	${CC} ${CFLAGS} -I${HEADER_PATH} -g -c $< -o $@
	
${NAME} : ${OBJS}
	echo "Compiling: push_swap..."
	${CC} ${CFLAGS} ${OBJS} ${LIBFT_LIB} -o ${NAME}
	echo "Succes !\n"

#########################
# 	CLEAN COMMANDS		#
#########################

force :

lib: force
	@make -sC $(LIBFT_PATH)

clean :
	@echo "Delete *.o"
	make clean -sC ${LIBFT_PATH}
	${RM} ${OBJS} 
	@echo "Succes !\n"

fclean: clean
	@echo "Delete *.a && executable"
	make fclean -sC ${LIBFT_PATH}
	${RM} ${NAME}
	@echo "Succes !\n"

re : fclean all

.PHONY: all clean fclean re force

