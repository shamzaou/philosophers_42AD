NAME = philo

CC = cc

FLAGS = -Wall -Wextra -Werror -pthread -g

SRCS = main.c philo.c init.c utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all