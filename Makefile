CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c pv_printer.c
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\nBuilding $(NAME)..."
	@ar rcs $(NAME) $(OBJS)
	@echo "\nDone!"

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJS)
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
	@$(CC) $(CFLAGS) -c $(SRCS)
	@ar rcs $(NAME) $(OBJS)
	@$(CC) $(CFLAGS) $(INCLUDES) main.c $(NAME) -o main && ./main
	@rm -f main $(OBJS) $(NAME)