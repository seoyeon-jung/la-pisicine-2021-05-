/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:09:38 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 10:10:42 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	count;
	int	*tab;

	count = 0;
	if (min >= max)
		return (0);
	tab = (int *)malloc(sizeof(*tab) * (max - min));
	if (tab == NULL)
		return (0);
	else
	{
		while (min < max)
		{
			tab[count] = min;
			count++;
			min++;
		}
		return (tab);
	}
}
