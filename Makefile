NAME = matrix.a

SOURCES = ./sources/Vector.cpp

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -Iincludes

COMPILER = c++
LIBCOMPILER = ar rcs

FLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(LIBCOMPILER) $(NAME) $(OBJECTS)

%.o: %.cpp
			$(COMPILER) -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
			$(RM) $(OBJECTS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re