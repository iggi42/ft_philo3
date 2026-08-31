/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:02:29 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 12:02:40 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// time related things
#ifndef TIME_H
# define TIME_H
# include <stdbool.h>

typedef long	t_timespan;

void			start_timer(void);
t_timespan		read_timer(void);
bool			philo_sleep(long wait_me);

#endif
