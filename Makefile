NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBS = ./libs/ft_printf/libftprintf.a ./libs/libft/libft.a \

SRCS = 	main.c utils.c utils2.c linked.c linked2.c operations.c\
		push.c switch.c rotate.c reverse_rotate.c indexers.c coster.c\
		sorter.c 

SRCS_BONUS = ./bonus/checker_bonus.c ./bonus/utils_bonus.c ./bonus/utils2_bonus.c ./bonus/linked_bonus.c ./bonus/linked2_bonus.c\
			./bonus/checker_utils_bonus.c ./bonus/push_bonus.c ./bonus/switch_bonus.c ./bonus/rotate_bonus.c ./bonus/reverse_rotate_bonus.c\
			 ./libs/get_next_line/get_next_line.c ./libs/get_next_line/get_next_line_utils.c\
	
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}
LIBC = ar rc
RM = rm -f

all: lib_compile ${NAME}

lib_compile:
	@echo "compiling libs"
	@cd ./libs/libft && make
	@cd ./libs/ft_printf && make

%.o: %.c push_swap.h
	@echo "compiling Files"
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME}: ${OBJS}
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "<< Compiling $(NAME) is  Finished >>"


bonus: lib_compile ${NAME_BONUS}

${OBJS_BONUS}: %.o: %.c ./bonus/push_swap_bonus.h
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

${NAME_BONUS}: ${OBJS_BONUS}
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBS) -o $(NAME_BONUS)
	@echo "<< Compiling $(NAME_BONUS) Bonus Finished >>"


clean:
	@echo "Start removing .. "
	@cd ./libs/libft && make clean
	@cd ./libs/ft_printf && make clean
	@rm -rf $(OBJS) $(OBJS_BONUS)
	@echo "<< Removing File .o is finished >> "

fclean: clean
	@echo "Start Removing $(NAME) $(NAME_BONUS)"
	@cd ./libs/libft && make fclean
	@cd ./libs/ft_printf && make fclean
	@rm -rf $(NAME) $(NAME_BONUS)
	@echo "<< Remove $(NAME)  $(NAME_BONUS) finished >> "

re: fclean all

.PHONY: clean  lib_compile LIBS_BONUS

