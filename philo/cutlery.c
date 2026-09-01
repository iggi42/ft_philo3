/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cutlery.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 20:07:13 by fkruger           #+#    #+#             */
/*   Updated: 2026/08/26 20:07:24 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cutlery.h"
#include "frk.h"
#include "utils.h"
#include <stdlib.h>

t_frk	*bring_the_cutlery(size_t n)
{
	t_frk	*result;
	size_t	i;

	i = 0;
	result = ft_calloc(n, sizeof(t_frk));
	while (result != NULL && i < n)
	{
		if (!frk_init(&result[i], i))
			result = (free(result), NULL);
		i++;
	}
	return (result);
}

void	cleanup_cutlery(t_frk *cutlery, size_t n)
{
	size_t	i;

	if (cutlery == NULL)
		return ;
	i = 0;
	while (i < n)
		frk_destroy(&cutlery[i++]);
	free(cutlery);
}
