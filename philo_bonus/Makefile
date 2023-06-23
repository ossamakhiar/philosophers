NAME = philo_bonus
SRCS = ./philo_bonus.c ./philo_utils_bonus.c ./philo_init_bonus.c ./philo_life_bonus.c ./destruct_bonus.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -rf ${NAME}

re: fclean all
