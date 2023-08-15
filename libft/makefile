# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nicolasbernard <nicolasbernard@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/11 16:41:58 by nicolasbern       #+#    #+#              #
#    Updated: 2023/08/12 15:12:16 by nicolasbern      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################
#		MAKEFILE		#
#########################

NAME		= 	libft.a
INC_DIR		= 	include/
INC			= 	libft.h


#########################
#	FOLDERS AND NAMES	#
#########################

SRC_DIR		= 	src/
SRC			= 	ft_isdigit.c \
 			   	ft_isspace.c \
 			   	ft_atoi.c \
 			   	ft_strlen.c \
 			   	ft_substr.c \
 			   	ft_strjoin.c \
 			   	ft_split.c \
				ft_strcpy.c\
 			   	ft_calloc.c \
 			   	ft_bzero.c \
 			   	ft_putchar_fd.c \
 			   	ft_putstr_fd.c \
				ft_lstnew.c \
 				ft_lstsize.c \
 			   	ft_lstadd_back.c \
 			   	ft_lstlast.c \
 			   	ft_lstclear.c \
 			   	ft_lstdelone.c \

OBJ_DIR		=	build/
OBJ			=	$(SRC:%.c=$(OBJ_DIR)%.o)


#########################
# 	COMPILER OPTIONS	#
#########################

CC			=	gcc
CC_FLAGS	=	-Wextra -Werror -Wall


#########################
# 		RULES			#
#########################

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo "> libft Done!\n"

$(OBJ): $(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC_DIR)$(INC)
	@mkdir -p $(@D)
	@echo "compiling: $<$(_END)"
	@$(CC) $(CC_FLAGS) -I $(INC_DIR) -c $< -o $@


#########################
# 	CLEAN COMMANDS		#
#########################

clean:
	@echo "remove $(OBJ_DIR)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "remove $(NAME)"
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re