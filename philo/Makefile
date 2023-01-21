NAME = philo
SRCS = ./philo.c ./philo_utils.c ./init_philo.c ./philo_life.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	cc ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all