NAME	=	a.out

CC		=	g++ -Wall -Wextra -Werror -O3 -std=c++98

SOURCE	=	main.cpp \
			Sample1.class.cpp \
			Sample2.class.cpp \

OBJ		=	$(SOURCE:%.cpp=%.o)

OBJ_DIR	=	obj/

MKDIR_P	=	mkdir -p

all:		$(NAME)

$(NAME):	$(OBJ_DIR) $(addprefix $(OBJ_DIR), $(OBJ))
	$(CC) $(addprefix $(OBJ_DIR), $(OBJ)) -o $(NAME)

$(OBJ_DIR)%.o:		%.cpp
	g++ -c $< -o $@

$(OBJ_DIR):
	$(MKDIR_P) $(OBJ_DIR)

clean:
	@rm -fr $(OBJ_DIR)

fclean:		clean
	@rm -fr $(NAME)

re:			fclean all
