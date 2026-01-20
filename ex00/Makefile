C++ = c++
STD = -std=c++11
C++_FLAGS = -Wall -Wextra -Werror

INFILES =	Bureaucrat.cpp \
			main.cpp

OBJFILES = $(INFILES:.cpp=.o)

NAME = bureaucrat

all: $(NAME)

$(NAME):$(OBJFILES)
	$(C++) $(STD) $(C++_FLAGS) $(OBJFILES) -o $(NAME) 

%.o: %.cpp
	$(C++) $(STD) $(C++_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
