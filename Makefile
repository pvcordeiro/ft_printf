CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = ft_printf.o
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nBuilding $(NAME)..."
	@ar rcs $(NAME) $(OBJ)
	@echo "\nDone!"

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJ)
	@echo "\nDone!"

fclean: clean
	@echo "\nRemoving $(NAME)..."
	@rm -f $(NAME)
	@echo "\nDone!"

re: fclean all

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

test:
	@echo "\nCompiling everything and testing it:\n"
	@$(CC) $(CFLAGS) -c ft_printf.c
	@ar rcs $(NAME) $(OBJ)
	@$(CC) $(CFLAGS) $(NAME) && ./a.out
	@rm -f a.out $(OBJ) $(NAME)