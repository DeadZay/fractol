.PHONY: all re clean fclean

.SECONDARY: $(OBJ)

UNAMEVENT_S := $(shell uname -s)

override CFLAGS = -Wall -Wextra -Werror

FLAGS = $(CFLAGS) -Llibft -lft -lmlx

ifeq ($(UNAMEVENT_S),Darwin)
    FLAGS += -framework AppKit -framework OpenGL
else ifeq ($(UNAMEVENT_S),Linux)
    FLAGS += -lX11 -lXext -lOpenGL
else
	exit 1
endif

override CC = gcc

SRC = 	twin.c \
        check_arguments.c \
        fractol.c \
        ft_cpowl.c \
        ft_cabsl.c \
        ft_cdiv.c \
        ft_cadd.c \
        ft_cmul.c \
        ft_csub.c \
        main.c \
        tview.c \
        tview_init.c \
        tfractol.c \
        tfractol_util.c \
        fractol_event.c \
        fractol_event_func.c \
        fractol_calc.c

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
