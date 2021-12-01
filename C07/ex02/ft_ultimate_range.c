/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:11:40 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 10:14:35 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	count;
	int	*tab;

	count = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab == NULL)
		return (-1);
	else
	{
		while (min < max)
		{
			tab[count] = min;
			count++;
			min++;
		}
		*range = tab;
		return (count);
	}
}
