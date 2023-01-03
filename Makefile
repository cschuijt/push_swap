OBJFILES := main.o instructions.o initialize_stack.o instruction_performers.o \
						debug.o instruction_printing.o
CFLAGS   := -Werror -Wall -Wextra -g -I lib
LIBFT_A  := lib/libft/libft.a
HEADER   := push_swap.h
NAME     := push_swap

$(NAME) : $(OBJFILES) $(LIBFT_A) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJFILES) $(LIBFT_A)

all : $(NAME)

re : fclean all

clean :
	rm -f $(OBJFILES) libft.a

fclean :
	rm -f $(NAME) $(OBJFILES)

$(LIBFT_A) :
	make -C lib/libft

%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY : clean fclean re
