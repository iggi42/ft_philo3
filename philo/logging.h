/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logging.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/23 22:07:06 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/23 22:07:07 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGGING_H
# define LOGGING_H
# include "philo_types.h"

void	log_forklift(t_philo *philo);
void	log_eating(t_philo *philo);
void	log_sleeping(t_philo *philo);
void	log_thinking(t_philo *philo);
void	log_animated(t_philo *philo);
void	log_died(t_philo *philo);
void	log_close_queue(t_philo *philo);
bool	log_queue(void (*print_smth)(t_philo *p), t_philo *p);
#endif
