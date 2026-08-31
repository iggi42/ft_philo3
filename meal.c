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

#include "meal.h"
#include "logging.h"

// returns true if it worked as expected
// returns false if the philo should abort
bool	set_last_meal2now(t_philo *p)
{
	bool	result;

	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return (false);
	result = p->last_meal != -1;
	if (result)
		p->last_meal = read_timer();
	return (!pthread_mutex_unlock(&p->last_meal_mutex));
}

bool	set_last_meal2off(t_philo *p)
{
	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return (false);
	p->last_meal = -1;
	return (!pthread_mutex_unlock(&p->last_meal_mutex));
}

bool	is_last_meal2on(t_philo *p)
{
	bool	result;

	if (p == NULL || pthread_mutex_lock(&p->last_meal_mutex))
		return (false);
	result = p->last_meal == -1;
	if (!pthread_mutex_unlock(&p->last_meal_mutex))
		return (false);
	return (result);
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
		result = ((read_timer() - p->last_meal));
	if (result >= p->c->t2die && log_queue(log_died, p))
		p->last_meal = -1;
	if (pthread_mutex_unlock(&p->last_meal_mutex))
		return (-1);
	return (result);
}
