NAME		=	test
LIBNAME		=	libasm

ASM			=	nasm
ASFLAGS		=	-f elf64

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

SRC_DIR		=	srcs/
OBJ_DIR		=	obj/

LIB_SRC 		=	ft_strlen.s
LIB_OBJ			=	$(addprefix $(OBJ_DIR), $(LIB_SRC:.s=.o))

SRC				=	main.c
OBJ				=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

$(OBJ_DIR)%.o:	$(SRC_DIR)%.s
					@mkdir -p $(@D)
					$(ASM) $(ASFLAGS) $< -o $@

$(OBJ_DIR)%.o:	%.c
					@mkdir -p $(@D)
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(LIBNAME):		$(LIB_OBJ)
					ar rcs $@.a $(LIB_OBJ)

$(NAME):		$(LIBNAME) $(OBJ)
					$(CC) $(CFLAGS) $(OBJ) -o $@ -L./ -lasm


clean:
					$(RM) -r $(OBJ_DIR)

fclean:			clean
					$(RM) $(NAME) $(LIBNAME).a

re:				fclean all

.PHONY:			all clean fclean re
