CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98
 
SRC = Megaphone.cpp

OBJ = $(SRC:.cpp=.o)

NAME = megaphone

all : $(NAME)

$(NAME)	:	$(OBJ)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)


%.o : %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
		rm -rf $(OBJ)

re: clean all

fclean : clean
		rm -rf $(NAME)