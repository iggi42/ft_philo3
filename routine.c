/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:28:57 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/23 20:29:00 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "logging.h"
#include "routine.h"
#include "meal.h"
#include <unistd.h>

// returns true if it has slept the full time
// returns false if philo should abort
// logging is included as side effect (sleeping log at start,
// thinking log afterwards)
static bool	philo_routine_sleep(t_philo *thinker)
{
	if (!log_queue(log_sleeping, thinker))
		return (false);
	philo_sleep(thinker->c->t2nap);
	return (log_queue(log_thinking, thinker));
}

void	*philo_routine_maxmeals(void *s)
{
	t_philo	*me;
	int		meals;

	me = s;
	meals = 0;
	while (true)
	{
		if (!philo_routine_eating(me))
			return (NULL);
		if (++meals >= me->c->max_meals)
			break ;
		if (!philo_routine_sleep(me))
			return (NULL);
	}
	set_last_meal2off(me);
	return (NULL);
}

void	*philo_routine_endless(void *s)
{
	t_philo	*me;

	me = s;
	while (true)
	{
		if (!philo_routine_eating(me))
			break ;
		if (!philo_routine_sleep(me))
			break ;
	}
	return (NULL);
}
