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
#include <stdbool.h>
#include <unistd.h>

void	ft_switch(t_frk **a, t_frk **b)
{
	void	*c;

	c = *a;
	*a = *b;
	*b = c;
}

static void	philo_put_down(t_frk *fs[2])
{
	frk_putdown(fs[0]);
	frk_putdown(fs[1]);
}

// this decides which fork to take up first and which secound
void	sort_cutlery(t_philo *me, t_frk *(*target)[2])
{
	(*target)[0] = me->left;
	(*target)[1] = me->right;
	if (me->c->n_phil % 2 == 0)
	{
		if (me->id % 2 == 0)
			ft_switch(&(*target)[0], &(*target)[1]);
		return ;
	}
}

// bool	sync_takeup(unsigned char id, t_frk *f0, t_frk *f1)
bool static	philo_special_boy(t_philo *me)
{
	int		takenup_result;
	long	time_since_last_meal;

	time_since_last_meal = read_philo_state(me);
	if(time_since_last_meal == -1)
		return false;
	takenup_result = 0;
	while (takenup_result == 0)
	{
		takenup_result = frk_sync_takeup(me);
		if (takenup_result == -1)
			return (false);
		usleep(1);
	}
	if (takenup_result == 1)
	{
		if (!log_queue(log_eating, me) || !set_last_meal2now(me))
			return (false);
		if (!philo_sleep(me->c->t2eat))
			return (false);
		if (frk_sync_putdown(me) == -1)
			return (false);
	}
	return (takenup_result != -1);
}

// returns true if it has eaten
// returns false if philo should abort
// logging is included as side effect
bool	philo_routine_eating(t_philo *me)
{
	t_frk	*fs[2];
	bool	has_eaten;

	if ((me->c->n_phil % 2) == 1)
		return (philo_special_boy(me));
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
			if (!log_queue(log_forklift, me) || !log_queue(log_eating, me)
				|| !set_last_meal2now(me))
				return (philo_put_down(fs), false);
			philo_sleep(me->c->t2eat);
			has_eaten = true;
			frk_putdown(fs[1]);
		}
		frk_putdown(fs[0]);
	}
	return (has_eaten);
}
