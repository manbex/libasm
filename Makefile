NAME			=	test
LIBNAME			=	libasm

NAME_BONUS		=	test_bonus
LIB_BONUS		=	libasm_bonus

ASM				=	nasm
ASFLAGS			=	-f elf64

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

SRC_DIR			=	srcs/
BONUS_DIR		=	bonus/
OBJ_DIR			=	obj/

LIB_SRC			=	ft_strlen.s	\
					ft_strcpy.s	\
					ft_strcmp.s	\
					ft_write.s	\
					ft_read.s	\
					ft_strdup.s
BONUS_SRC		=	ft_list_push_front.s	\
					ft_list_size.s


LIB_OBJ			=	$(addprefix $(OBJ_DIR), $(LIB_SRC:.s=.o))
LIB_OBJ_BONUS	=	$(addprefix $(OBJ_DIR), $(BONUS_SRC:.s=.o))

SRC				=	main.c
SRC_BONUS		=	main_bonus.c

OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJ_BONUS		=	$(addprefix $(OBJ_DIR), $(SRC_BONUS:.c=.o))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.s
					@mkdir -p $(@D)
					$(ASM) $(ASFLAGS) $< -o $@

$(OBJ_DIR)%.o:	$(BONUS_DIR)%.s
					@mkdir -p $(@D)
					$(ASM) $(ASFLAGS) $< -o $@

$(OBJ_DIR)%.o:	%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

bonus:			$(NAME_BONUS)

$(LIBNAME):		$(LIB_OBJ)
					ar rcs $@.a $(LIB_OBJ)

$(LIB_BONUS):	$(LIB_OBJ_BONUS)
					ar rcs $@.a $(LIB_OBJ_BONUS)

$(NAME):		$(LIBNAME) $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $@ -L./ -lasm

$(NAME_BONUS):	$(LIB_BONUS) $(OBJ_BONUS)
					$(CC) $(CFLAGS) $(OBJ_BONUS) -o $@ -L./ -lasm_bonus

clean:
					$(RM) -r $(OBJ_DIR)

fclean:			clean
					$(RM) $(NAME) $(LIBNAME).a $(NAME_BONUS) $(LIB_BONUS).a

re:				fclean all

.PHONY:			all clean fclean re
