NAME	=	a.out

CC		=	c++ -Wall -Wextra -Werror -O3 -std=c++98

SOURCE	=	main.cpp \
			Sample.class.cpp \

OBJ		=	$(SOURCE:%.cpp=%.o)

OBJ_DIR	=	obj/

MKDIR_P	=	mkdir -p

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(addprefix $(OBJ_DIR), $(OBJ))
	$(CC) $(addprefix $(OBJ_DIR), $(OBJ)) -o $(NAME)

$(OBJ_DIR)%.o:		%.cpp
	$(CC) -c $< -o $@

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)

clean:
	@rm -fr $(OBJ_DIR)

fclean:		clean
	@rm -fr $(NAME)

re:			fclean all
