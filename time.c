/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/14 19:04:33 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/24 01:10:01 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "logging.h"
#include "time.h"
#include <stddef.h>
#include <sys/time.h>
#include <unistd.h>

/// op can be
// 0 to start the timer from zero
// 1 to get the time passed since it was started
static long	timer(int op)
{
	static unsigned long long	start;
	struct timeval				tv;
	long						now;

	if (gettimeofday(&tv, NULL))
		return (-1);
	now = (tv.tv_sec * 1000 + (tv.tv_usec + 500) / 1000);
	if (op == 0)
		return (start = now, start);
	else if (op == 1)
		return (now - start);
	return (-1);
}

void	start_timer(void)
{
	timer(0);
}

long	read_timer(void)
{
	return (timer(1));
}

void	log_bs(t_philo *philo)
{
	(void)philo;
}

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000L + (500 + tv.tv_usec) / 1000L);
}
#include <stdio.h>

bool	philo_sleep_until(t_timespan target)
{
	t_timespan	now;

	while (42)
	{
		now = read_timer();
		// printf("now is %ld wating till %ld \n", now, target);
		if (now >= target)
			break ;
		if (now + 10 > target)
			usleep(1000);
		else
			usleep(100);
		if (!log_queue(log_bs, NULL))
			return (false);
	}
	return (log_queue(log_bs, NULL));
}

bool	philo_sleep(long duration_ms)
{
	long	start;
	long	elapsed;

	start = get_time_ms();
	while (42)
	{
		elapsed = get_time_ms() - start;
		if (elapsed >= duration_ms)
			break ;
		if (duration_ms - elapsed > 10)
			usleep(1000);
		else
			usleep(100);
		if (!log_queue(log_bs, NULL))
			return (false);
	}
	return (log_queue(log_bs, NULL));
}
