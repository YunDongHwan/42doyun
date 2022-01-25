NAME =		Vector

CC =		clang++

CXXFLAGS =	-Wall -Wextra -Werror

SRC =		stack.cpp #Vector.cpp

SRC_PATH =	$(addprefix ./srcs/, $(SRC))

OBJ = 		$(SRC_PATH:.cpp=.o)

INC_PATH = 	./includes

all :		$(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CXXFLAGS) -I $(INC_PATH) -o $@ $(SRC_PATH)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)

re :		fclean all

.PHONY :	all clean fclean re
