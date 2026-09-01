/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutlery.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:08:35 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:08:40 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUTLERY_H
# define CUTLERY_H
# include "philo_types.h"

t_frk	*bring_the_cutlery(size_t n);
void	cleanup_cutlery(t_frk *cutlery, size_t n);
#endif
