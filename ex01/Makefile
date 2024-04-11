NAME	=	Serializer

CXX		=	c++

CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98 -O0

SRCS		=	main.cpp\
				Serializer.cpp\
				
INCS		=	Serializer.hpp\
				Data.hpp\

OBJS	=	$(SRCS:.cpp=.o)

all:	$(NAME)

$(NAME)	: $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(INCS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY = all clean fclean re