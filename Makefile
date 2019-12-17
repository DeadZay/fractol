.PHONY: all re clean fclean

.SECONDARY: $(OBJ)

UNAME_S := $(shell uname -s)

override CFLAGS = -Wall -Wextra -Werror

FLAGS = $(CFLAGS) -pthread -Llibft -lft -lmlx

ifeq ($(UNAME_S),Darwin)
    FLAGS += -framework AppKit -framework OpenGL
else ifeq ($(UNAME_S),Linux)
    FLAGS += -lX11 -lXext -lOpenGL
else
	exit 1
endif

override CC = gcc

SRC = main.c twin.c

OBJ = $(SRC:.c=.o)

NAME = fractol

all::
	$(MAKE) -C libft
all:: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $^ -o $@

clean:
	$(RM) -f $(OBJ)
	$(MAKE) -C libft clean

fclean:
	$(RM) -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all
