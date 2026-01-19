NAME = Forms
SRC = main.cpp Bureaucrat.cpp AForm.cpp \
	  PresidentialPardonForm.cpp \
	  RobotomyRequestForm.cpp \
	  ShrubberyCreationForm.cpp
OBJ = $(SRC:.cpp=.o)
DEP = $(OBJ:.o=.d)
FLAGS = -std=c++98 -Wall -Werror -Wextra -MMD
all : $(NAME)

$(NAME) : $(OBJ)
	c++ $(FLAGS) $(SRC) -o $(NAME)

%.o : %.cpp
	c++ $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ) $(DEP) Forms.d

fclean : clean
	rm -f $(NAME)

re : fclean all
-include $(DEP)

.PHONY : all clean fclean re