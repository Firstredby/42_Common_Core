NAME = Fixed
SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
FLAGS = -std=c++98 -Wall -Werror -Wextra -MMD
all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(DEP)

fclean : clean
	rm -f $(NAME)

re : fclean all
-include $(DEP)

.PHONY : all clean fclean re