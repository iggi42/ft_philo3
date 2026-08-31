/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 06:40:08 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/19 19:50:09 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_types.h"
#include <stdio.h>

void	log_forklift(t_philo *philo)
{
	printf("%ld %d has taken a fork\n", read_timer(), (int)philo->id);
}

void	log_eating(t_philo *philo)
{
	printf("%ld %d is eating\n", read_timer(), (int)philo->id);
}

void	log_sleeping(t_philo *philo)
{
	printf("%ld %d is sleeping\n", read_timer(), (int)philo->id);
}

void	log_thinking(t_philo *philo)
{
	printf("%ld %d is thinking\n", read_timer(), (int)philo->id);
}

void	log_died(t_philo *philo)
{
	printf("%ld %d died\n", read_timer(), (int)philo->id);
}
