/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinkers_start.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 21:57:57 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 21:57:58 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logging.h"
#include "utils.h"
#include "thinkers.h"
#include "routine.h"
#include <unistd.h>

static pthread_t	*start_threats(t_philo_conf *c, t_philo *philo,
		void *(*routine)(void *))
{
	size_t		i;
	pthread_t	*thread_ids;

	thread_ids = ft_calloc(c->n_phil, sizeof(pthread_t));
	if (thread_ids == NULL)
		return (NULL);
	i = 0;
	log_queue(NULL, NULL);
	start_timer();
	while (i < philo->c->n_phil)
	{
		if (pthread_create(&thread_ids[i], NULL, routine, &philo[i]))
		{
			log_queue(log_close_queue, &philo[i]);
			wait4thinkers(thread_ids, i);
			return (NULL);
		}
		usleep(100);
		i++;
	}
	return (thread_ids);
}

pthread_t	*start_thinkers(t_philo_conf *c, t_philo *philo)
{
	if (philo == NULL)
		return (NULL);
	if (c->max_meals < 0)
		return (start_threats(c, philo, philo_routine_endless));
	else
		return (start_threats(c, philo, philo_routine_maxmeals));
}
