/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meal.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:58:57 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 18:59:07 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logging.h"
#include "meal.h"

// returns true if it worked as expected
// returns false if the philo should abort
bool	set_last_meal(t_philo *p)
{
	t_timespan	now;

	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return (false);
	now = read_timer();
	if ((now - p->last_meal) > p->c->t2die)
		p->last_meal = (log_queue(log_died, p), -1);
	if (p->last_meal != -1)
		p->last_meal = (log_queue(log_eating, p), now);
	return (!pthread_mutex_unlock(&p->last_meal_mutex));
}

bool	set_last_meal_off(t_philo *p)
{
	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return (false);
	p->last_meal = -1;
	return (!pthread_mutex_unlock(&p->last_meal_mutex));
}

// returns the time since the last meal was registred, or -1 if thread is happy.
t_timespan	read_philo_state(t_philo *p)
{
	t_timespan	result;

	if (pthread_mutex_lock(&p->last_meal_mutex))
		return (-1);
	if (p->last_meal < 0)
		result = -1;
	else
		result = read_timer() - p->last_meal;
	if (result >= p->c->t2die)
		p->last_meal = (log_queue(log_died, p), -1);
	if (pthread_mutex_unlock(&p->last_meal_mutex))
		return (-1);
	return (result);
}
