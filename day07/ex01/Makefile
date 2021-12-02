NAME 	=	Iter

SRCS	=	main.cpp

INCLUDES	=	iter.hpp

OBJS	=	$(SRCS:.cpp=.o)

CC		=	clang++

CFLAGS	=	-Wall -Wextra -Werror -std=c++98

RM 		=	rm -f

$(NAME) : $(SRCS) $(INCLUDES)
		$(CC) -o $(NAME) $(CFLAGS) $(SRCS) -I.

.cpp.o	:
			$(CC) -c $(CFLAGS) $< -o $@

all 	:	$(NAME)

clean 	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re 		: 	fclean all