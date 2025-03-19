## **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruiz-d <anruiz-d@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 14:59:56 by anruiz-d          #+#    #+#              #
#    Updated: 2025/02/27 15:00:13 by anruiz-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# --- Project Name --- #

NAME		=	push_swap
LIBFT		=	libft.a

# --- Directories --- #

DIR_SRCS	:=	srcs
DIR_OBJS	:=	objs
DIR_INCL	:=	include

# --- Source files --- #

PUSH_SRC_FIL	=	push_swap.c handle_numbers.c index_assign.c init_and_free.c \
					ksort.c push.c reverse.c rotate.c swap.c utils.c ksort_mini.c \
					parse_arg.c
PUSH_SRC_DIR	=	$(addprefix $(DIR_SRCS)/, $(PUSH_SRC_FIL))

# --- Object files --- #

PUSH_OBJ_FILE = $(PUSH_SRC_DIR:$(DIR_SRCS)/%.c=$(DIR_OBJS)/%.o)

# --- compiler and tools --- #

CC		=	cc 
FLAGS	=	-Wall -Werror -Wextra -g -fsanitize=address
INCLUDE	=	-I $(DIR_INCL)
AR		=	ar
RM		=	rm -rf
MKDIR	=	mkdir -p

###################################################
#		DEFAULT TARGET		  	  #
###################################################

all:	$(NAME)

###################################################
#		Program Target	  #
###################################################

$(NAME):	$(PUSH_OBJ_FILE)
			@make -C libft
			@$(CC) $(FLAGS) $(PUSH_OBJ_FILE) $(INCLUDE) libft/$(LIBFT) -o $(NAME)

###################################################
#		OBJECT FILE RULE		  #
###################################################

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c
	@$(MKDIR) $(DIR_OBJS)
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

###################################################
#		CLEANING RULES			  #
###################################################

clean:
	@$(RM) $(DIR_OBJS)

fclean:	clean
	@make fclean -C libft
	@$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re