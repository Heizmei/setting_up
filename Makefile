##
## EPITECH PROJECT, 2024
## makefile
## File description:
## makefile
##

SRC		=	setting_up.c		\
			my_str_to_word_array.c	\
			algo.c	\
			my_putstr.c	\
			generate_map.c	\
			my_getnbr.c		\
			my_strcat.c		\

DIR_SRC        =    $(addprefix source/, $(SRC))

MAIN_SRC    =    source/main.c	\

TEST        =    unit_test.c\

DIR_TESTS    =    $(addprefix tests/, $(TEST))

OBJ_DIR_SRC    =    $(DIR_SRC:.c=.o)

OBJ_MAIN    =    $(MAIN_SRC:.c=.o)

OBJ            =    $(OBJ_DIR_SRC) $(OBJ_MAIN)

CPPFLAGS    =    -I include/                        \

CFLAGS        =    -Wall -Wextra -ggdb3

NAME        =    setting_up

$(NAME):    $(OBJ)
		gcc -o $(NAME) -g $(CFLAGS) $(OBJ)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -rf unit_tests
		rm -rf *.log
		rm -rf *.gcov
		rm -rf *.gcda
		rm -rf *.gcno
		rm -f $(NAME)
		rm -rf vgcore.*

re:        fclean all

unit_tests:    re
		mkdir unit_tests
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:    unit_tests
		./unit_tests/unit_tests

.PHONY: all clean fclean re tests_run
