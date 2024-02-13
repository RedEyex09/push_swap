NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libs/ft_printf/libftprintf.a ./libs/libft/libft.a \
	#    ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c\

SRCS = 	main.c utils.c utils2.c linked.c linked2.c operations.c\
		push.c switch.c rotate.c

# SRCS_BONUS = 
	
OBJS = ${SRCS:.c=.o}
# OBJS_BONUS = ${SRCS_BONUS:.c=.o}
LIBC = ar rc
RM = rm -f

all: lib_compile ${NAME}

lib_compile:
	@echo "compiling libs"
	@cd ./libs/libft && make
	@cd ./libs/ft_printf && make

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "<< Compiling $(NAME) is  Finished >>"

# bonus :lib_compile ${NAME} ${OBJS_BONUS}
# 	@echo "Compiling $(NAME)..."
# 	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME)
# 	@echo "<< Compiling $(NAME) Bonus Finished >>"

clean:
	@echo "Start removing .. "
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJS)
	@echo "<< Removing File .o is finished >> "

fclean: clean
	@echo "Start Removing $(NAME)"
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME)
	@echo "<< Remove $(NAME) finished >> "

re: fclean all

.PHONY: clean  lib_compile