/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 03:39:12 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/14 20:51:11 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cutlery.h"
#include "logging.h"
#include "meal.h"
#include "philo.h"
#include "thinkers.h"
#include "time.h"
#include <unistd.h>

static void	find_starved(t_philo_conf *c, t_philo *philo)
{
	size_t		i;
	t_timespan	t;
	bool		clean;

	if (philo == NULL)
	{
		log_queue(log_close_queue, NULL);
		return ;
	}
	i = 0;
	clean = true;
	while (i < c->n_phil)
	{
		t = read_philo_state(&philo[i]);
		if (t >= c->t2die)
			return ;
		else if (t >= 0)
			clean = false;
		if (i + 1 >= c->n_phil && clean)
			return ;
		else if (i + 1 >= c->n_phil)
			clean = true;
		i = (i + 1) % c->n_phil;
		usleep(50);
	}
}

bool	run_sim(t_philo_conf *c)
{
	t_frk		*frks;
	t_philo		*thinkers;
	pthread_t	*pthr_id;

	frks = bring_the_cutlery(c->n_phil);
	if (frks == NULL || 0 >= c->n_phil || c->n_phil > 200)
		return (cleanup_cutlery(frks, c->n_phil), false);
	thinkers = create_thinkers(c, frks);
	if (thinkers == NULL)
		return (cleanup_cutlery(frks, c->n_phil), false);
	pthr_id = start_thinkers(c, thinkers);
	if (pthr_id == NULL)
		return (false);
	find_starved(c, thinkers);
	wait4thinkers(pthr_id, c->n_phil);
	cleanup_thinkers(thinkers, c->n_phil);
	cleanup_cutlery(frks, c->n_phil);
	return (true);
}
