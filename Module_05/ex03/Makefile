NAME	=	program

CC		=	c++ -Wall -Wextra -Werror -O3 -std=c++98 -fsanitize=address

FILES	=	main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			ShrubberyCreationForm.cpp \
			RobotomyRequestForm.cpp \
			PresidentialPardonForm.cpp \
			Intern.cpp \

SRC_DIR	=	sources/
OBJ_DIR	=	objects/

SRC		=	$(addprefix $(SRC_DIR), $(FILES))
OBJ		=	$(addprefix $(OBJ_DIR), $(FILES:%.cpp=%.o))


MKDIR_P	=	mkdir -p

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.cpp
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)

clean:
	@rm -fr $(OBJ_DIR)

fclean:		clean
	@rm -fr $(NAME)

re:			fclean all
