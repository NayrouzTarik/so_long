NAME = so_long

INC = inc/so_long.h 

LIBFT =	libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = parcing.c \
	  parcing2.c \
	  double_check.c \
	  gnl/get_next_line.c \
	  gnl/get_next_line_utils.c \
	  minilbx.c \
	  main.c \
	  drawing.c \
	  init.c \
	  
OBJ = $(SRC:.c=.o)

m := MakefileAutoPush

all: $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	$(CC) $(OBJ) -lmlx  -framework OpenGL -framework AppKit -o $(NAME) $(LIBFT)

%.o : %.c $(INC)
	${CC} ${CFLAGS} -Imlx -c -o $@ $<

clean:
	make clean -C libft
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

git :
	git add .
	git status
	git commit -m "$(m)"
	git push

.PHONY: all clean fclean re