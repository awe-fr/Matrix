NAME = matrix

SOURCES = main.cpp

OBJECTS = $(SOURCES:.cpp=.o)

INCLUDES = -Ipml

COMPILER = c++ -std=c++20

FLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

all:		$(NAME)

$(NAME):	$(OBJECTS)
			$(COMPILER) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp
			$(COMPILER) -c $(FLAGS) $(INCLUDES) $< -o $@

clean:
			$(RM) $(OBJECTS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re