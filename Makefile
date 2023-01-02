OBJFILES := 
FLAGS    := -Werror -Wall -Wextra -g -I lib
LIBFT_A  := lib/libft/libft.a
HEADER   := push_swap.h
NAME     := push_swap

ifeq ($(OS), Windows_NT)
	CC = gcc
	NAME := push_swap.exe
endif

$(NAME) : $(OBJFILES) $(LIBFT_A) $(HEADER)
	$(CC) $(FLAGS) -o $(NAME) $(OBJFILES) $(LIBFT_A) $(MLX42_A)

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(OBJFILES)

$(LIBFT_A) :
	make -C lib/libft

%.o : %.c $(HEADER)
	$(CC) -c $(FLAGS) -o $@ $<

.PHONY : clean fclean re
