CC = cc -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c ft_strjoin.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_strtrim.c ft_split.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) compile
	@echo "\nCreating static library $(NAME)..."
	@ar rcs $(NAME) $(OBJS)
	@echo "\nDone!"

bonus: $(OBJS) $(BONUS_OBJS)
	@echo "\nCreating static library with bonus $(NAME)..."
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)
	@echo "\nDone!"

compile: $(OBJS)
	@echo "\nCompiling .c files into .o files...\n\nDone!"

%.o: %.c
	@$(CC) -I. -c $< -o $@

clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJS) $(BONUS_OBJS)
	@echo "\nDone!"

fclean: clean
	@echo "\nRemoving library $(NAME)..."
	@rm -f $(NAME)
	@echo "\nDone!"

re: fclean all

# test: $(NAME) bonus
# 	@echo "\nCompiling main with $(NAME) into test..."
# 	@$(CC) main.c $(NAME) -lbsd -o test
# 	@echo "\nDone!"
# 	@echo "\nCleaning everything up..."
# 	@rm -f $(OBJS) $(BONUS_OBJS) $(NAME)
# 	@echo "\nDone!\n\n"
# 	@echo "\nRead the instructions bellow:\n"
# 	@./test