NAME 			    		:=  push_swap
CHECKER_NAME      :=  checker
CC				    		:=  gcc
COMPIL_FLAGS			?=  -Wall -Wextra -Werror -g
LINKFLAGS 				?=  -I include -I lib/libft

SRC_FILES	    		:=	copying_functions.c \
											debug.c \
											freeing_functions.c \
											initialize_stack.c \
											instruction_performers.c \
											instruction_printing.c \
											instructions_multiple.c \
											instructions.c \
											lis.c \
											main.c \
											patience_sort_distance.c \
											patience_sort_merging.c \
											patience_sort_optimal_moves.c \
											patience_sort_utils.c \
											patience_sort.c \
											small_sort.c \
											validations.c

CHECKER_SRC   		:=  checker_main.c \
											freeing_functions.c \
											initialize_stack.c \
											instruction_performers.c \
											instruction_printing.c \
											instructions.c \
											validations.c
    
OBJ_FILES			    :=	$(SRC_FILES:.c=.o)
CHECKER_OBJ_FILES :=	$(CHECKER_SRC:.c=.o)
SRC_DIR	      		:=	src/
OBJ_DIR	      		:=	obj/
OBJS	        		:=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))
CHECKER_OBJS	 		:=	$(addprefix $(OBJ_DIR), $(CHECKER_OBJ_FILES))
HEADER        		:=  include/push_swap.h
LIBFT_A       		:=  lib/libft/libft.a
LIBFT_H       		:=  lib/libft/libft.h


all : $(NAME)

$(NAME) : $(OBJS) $(LIBFT_A)
	@printf "$(COMP_HEADER)$(C_LGREEN)$@$(COMP_AFTER)"
	@$(CC) $(OBJS) $(COMPIL_FLAGS) -o $@ $(LINKFLAGS) $(LIBFT_A)
	@printf "$(COMP_DONE)"

$(CHECKER_NAME) : $(CHECKER_OBJS) $(LIBFT_A)
	@printf "$(COMP_HEADER)$(C_LGREEN)$@$(COMP_AFTER)"
	@$(CC) $(OBJS) $(COMPIL_FLAGS) -o $@ $(LINKFLAGS) $(LIBFT_A)
	@printf "$(COMP_DONE)"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(HEADER) | $(OBJ_DIR)
	@printf "$(COMP_HEADER)$(notdir $<)$(COMP_AFTER)"
	@$(CC) $(COMPIL_FLAGS) -o $@ $(LINKFLAGS) -c $<
	@printf "$(COMP_DONE)"

obj :
	@mkdir $(OBJ_DIR)

$(OBJ_DIR) :
	@mkdir $(OBJ_DIR)

$(LIBFT_A) : $(LIBFT_H)
	@printf "$(C_GREEN)Compiling $(C_CYAN)$(notdir $@) \n$(C_RESET)"
	make -C lib/libft

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(C_RED)Files cleaned\n$(C_RESET)"

fclean: clean
	@rm -f $(NAME) $(CHECKER_NAME)

re: fclean all

.phony : clean fclean all re

# Fancy shmancy

COMP_HEADER = $(C_ORANGE)Compiling: $(C_CYAN)$(C_BOLD)
COMP_AFTER  = $(C_RESET)$(C_ORANGE)... $(C_RESET)
COMP_DONE   = $(C_GREEN)(Done!)$(C_RESET)\n

C_RESET	    = \e[0m
C_BOLD	    = \e[1m

C_RED		    = \e[38;2;255;0;0m
C_ORANGE	  = \e[38;2;255;128;0m
C_LGREEN	  = \e[38;2;128;255;128m
C_GREEN		  = \e[38;2;0;255;0m
C_CYAN		  = \e[38;2;0;255;255m
