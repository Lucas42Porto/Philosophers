# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumarque <lumarque@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 19:24:47 by lumarque          #+#    #+#              #
#    Updated: 2024/05/07 19:24:49 by lumarque         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = cc
RM = rm -f
FLAGS = -Wall -Wextra -Werror 

SRC =	./src/philo.c \
		./src/utils.c \
		./src/init_data.c \
		./src/ft_die.c \
		./src/threads.c \


# ------------------------------ Colors ------------------------------

BOLD_PURPLE	=	\033[1;35m
BOLD_CYAN	=	\033[1;36m
BOLD_GREEN	=	\033[1;32m
BOLD_YELLOW	=	\033[1;33m
NO_COLOR	=	\033[0m


# ------------------------------ Message ------------------------------

COMP_START	=	echo "\n $(BOLD_YELLOW)Make: $(NO_COLOR)Starting the compilation...\n"

READY		=	echo "\n $(BOLD_GREEN)Ready$(NO_COLOR) : The program $(BOLD_CYAN) philo $(NO_COLOR) compiled!\n"

CLEANED		=	echo "\n $(BOLD_PURPLE)Clean: $(NO_COLOR)Removed all the \".o\" files \n"

FCLEANED	=	echo "\n $(BOLD_PURPLE)Fclean: $(NO_COLOR)Removed the executables \n"


.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

OBJ = ${SRC:.c=.o}

${NAME}: ${OBJ}
		@$(COMP_START)
		@${CC} ${OBJ} -o ${NAME}
		@$(READY) 

all: ${NAME}

clean:
	@${RM} ${OBJ}
	@$(CLEANED)

fclean: clean
	@${RM} ${NAME}
	@$(FCLEANED)

re: fclean all

.PHONY: all clean fclean re