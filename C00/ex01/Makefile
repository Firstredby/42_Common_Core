NAME = Phonebook
SRC = PhoneBook.cpp
OBJ = $(SRC:.cpp=.o)
FLAGS = -std=c++98 -Wall -Werror -Wextra -g
all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re