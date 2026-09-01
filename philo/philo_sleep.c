/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/01 20:34:03 by fkruger           #+#    #+#             */
/*   Updated: 2026/09/01 20:34:04 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logging.h"
#include <unistd.h>

static void	log_bs(t_philo *philo)
{
	(void)philo;
}

bool	philo_sleep_until(t_timespan target)
{
	t_timespan	now;

	while (42)
	{
		now = read_timer();
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
