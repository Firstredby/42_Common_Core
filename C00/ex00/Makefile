NAME = megaphone
SRC = Megaphone.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Werror -Wextra
all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re