CXX			:=	clang++
CXXFLAGS	:=	-Wall -Wextra -Werror -std=c++98 --pedantic
NAME		:=	exe
SRCS		:=	main.cpp Animal.cpp Dog.cpp Cat.cpp Brain.cpp
OBJS		:=	$(SRCS:.cpp=.o)

.PHONY		:	all clean fclean re

all			:	$(NAME)
$(NAME)		:	$(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean		:
	$(RM) -rf $(OBJS)

fclean		:	clean
	$(RM) $(NAME)

re			:	fclean all

.PHONY		:	runtest

runtest		: all
	$(MAKE) -C ../ex01
	../ex01/$(NAME) > out1
	./$(NAME) > out2
	! diff -u out{1,2}
