/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 20:28:57 by fkruger           #+#    #+#             */
/*   Updated: 2026/09/06 16:56:36 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "logging.h"
#include "meal.h"
#include "routine.h"
#include <unistd.h>

// returns true if it has slept the full time
// returns false if philo should abort
// logging is included as side effect (sleeping log at start,
// thinking log afterwards)
static bool	philo_routine_sleep(t_philo *thinker)
{
	bool		result;
	t_timespan	start_time;

	start_time = read_timer();
	if (!log_queue(log_sleeping, thinker))
		return (false);
	philo_sleep_until(start_time + thinker->c->t2nap);
	result = log_queue(log_thinking, thinker);
	if (thinker->c->n_phil % 2 == 1)
		philo_sleep_until(read_timer()
			+ ((thinker->c->t2die - thinker->c->t2eat - thinker->c->t2nap) / 2)
			);
	return (result);
}

void	*philo_routine_maxmeals(void *me)
{
	int			meals;
	t_timespan	start_time;

	start_time = read_timer();
	meals = 0;
	if (((t_philo *)me)->id % 2 == 1)
		philo_sleep_until(start_time + (((t_philo *)me)->c->t2eat / 2));
	while (true)
	{
		if (!philo_routine_eating(me))
			return (NULL);
		if (++meals >= ((t_philo *)me)->c->max_meals)
			break ;
		if (!philo_routine_sleep(me))
			return (NULL);
	}
	set_last_meal_off(me);
	return (NULL);
}

void	*philo_routine_endless(void *s)
{
	t_philo		*me;
	t_timespan	start_time;

	start_time = read_timer();
	me = s;
	if (((t_philo *)me)->id % 2 == 1)
		philo_sleep_until(start_time + (((t_philo *)me)->c->t2eat / 2));
	while (true)
	{
		if (!philo_routine_eating(me))
			break ;
		if (!philo_routine_sleep(me))
			break ;
	}
	return (NULL);
}
