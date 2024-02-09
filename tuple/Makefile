
NAME = tuple

SRC = main.cpp
CFLAGS = -std=c++20 -Wall -Wextra -Werror -pedantic

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CFLAGS) $(SRC) -o $(NAME)

re: fclean $(NAME)

fclean:
	@rm -f $(NAME)
