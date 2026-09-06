# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkruger <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/13 01:51:41 by fkruger           #+#    #+#              #
#    Updated: 2026/09/06 16:22:54 by fkruger          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = philo
CC = cc
CFLAGS += -MD -Wall -Wextra -Werror

# CFLAGS += -g -O1 -fsanitize=thread
# CFLAGS += -g
# CFLAGS += -O3

# utils functions
SRCS += utils.c ph_main.c time.c philo_sleep.c
# core logic
SRCS += frk.c cutlery.c run_sim.c meal.c routine.c routine_eating.c
SRCS += thinkers.c thinkers_start.c
# logging
SRCS += logging.c log_queue.c

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

# normal targets
.PHONY: fclean clean re all
all: $(NAME)
re: clean all
fclean: clean
	$(RM) $(NAME)
clean:
	$(RM) $(OBJS) $(DEPS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -pthread -o $@ $+
