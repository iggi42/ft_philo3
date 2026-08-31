/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkruger <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 12:03:06 by fkruger           #+#    #+#             */
/*   Updated: 2026/07/18 12:03:33 by fkruger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t n_el, size_t el_size)
{
	void	*result;

	if (n_el == 0 || el_size == 0 || (SIZE_MAX / n_el) < el_size)
		return (NULL);
	el_size *= n_el;
	result = malloc(el_size);
	memset(result, 0, el_size);
	return (result);
}

bool	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

// check if input is valid
bool	ft_aisi(char *input)
{
	if (input == NULL || *input == '\0')
		return (false);
	while (*input)
	{
		if (!ft_isdigit(*input))
			return (false);
		input++;
	}
	return (true);
}

// parse input
int	ft_atoi(char *input)
{
	long	result;

	result = 0;
	while (ft_isdigit(*input))
	{
		result = (result * 10) + (*input - 48);
		input++;
	}
	return (result);
}
