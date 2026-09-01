/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_eating.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:06:36 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:06:37 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "frk.h"
#include "logging.h"
#include "meal.h"
#include "philo_types.h"
#include "time.h"
#include <stdbool.h>
#include <unistd.h>

static void	ft_switch(t_frk **a, t_frk **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

// this decides which fork to take up first and which secound
// returns true if it has eaten
// returns false if philo should abort
// logging is included as side effect
bool	philo_routine_eating(t_philo *me)
{
	t_frk		*fs[2];
	bool		has_eaten;

	fs[0] = me->left;
	fs[1] = me->right;
	has_eaten = false;
	if (me->id % 2 == 0)
		ft_switch(&fs[0], &fs[1]);
	if (frk_pickup(fs[0]))
	{
		if (!log_queue(log_forklift, me) || (fs[0] == fs[1]))
			return (frk_putdown(fs[0]), false);
		if (frk_pickup(fs[1]))
		{
			if (!log_queue(log_forklift, me))
				return (frk_putdown(fs[0]), frk_putdown(fs[1]), false);
			has_eaten = set_last_meal(me) && philo_sleep_until(read_timer() + me->c->t2eat);
			frk_putdown(fs[1]);
		}
		frk_putdown(fs[0]);
	}
	return (has_eaten);
}
