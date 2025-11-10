NAME = ZombieHorde
SRC = Zombie.cpp main.cpp ZombieHorde.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
FLAGS = -std=c++98 -Wall -Werror -Wextra -MMD
-include $(DEP)
all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ) $(DEP)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re