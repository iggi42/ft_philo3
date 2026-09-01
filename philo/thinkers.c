/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:36:24 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:36:26 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_types.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

void	init_thinker(t_philo *fresh, size_t i, t_philo_conf *c, t_frk *cutlery)
{
	fresh->id = i + 1;
	fresh->c = c;
	fresh->last_meal = 0;
	fresh->left = &cutlery[i];
	fresh->right = &cutlery[(i + 1) % c->n_phil];
}

void	cleanup_thinkers(t_philo *philos, size_t n)
{
	size_t	i;

	if (philos == NULL)
		return ;
	i = 0;
	while (i < n)
		pthread_mutex_destroy(&philos[i++].last_meal_mutex);
	free(philos);
}

t_philo	*create_thinkers(t_philo_conf *c, t_frk *cutlery)
{
	t_philo	*thinkers;
	size_t	i;

	i = 0;
	thinkers = ft_calloc(c->n_phil, sizeof(t_philo));
	if (thinkers == NULL || cutlery == NULL)
		return (free(thinkers), NULL);
	while (i < c->n_phil)
	{
		init_thinker(&thinkers[i], i, c, cutlery);
		if (pthread_mutex_init(&(thinkers[i].last_meal_mutex), NULL))
			return (cleanup_thinkers(thinkers, i), NULL);
		i++;
	}
	return (thinkers);
}

void	wait4thinkers(pthread_t *ids, size_t n)
{
	size_t	i;

	if (ids == NULL)
		return ;
	i = 0;
	while (i < n)
	{
		if (pthread_join(ids[i++], NULL))
			break ;
	}
	free(ids);
}
