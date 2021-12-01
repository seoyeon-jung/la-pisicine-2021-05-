/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:04:06 by seojung           #+#    #+#             */
/*   Updated: 2021/09/20 15:19:19 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	num;

	num = 0;
	while (num < (size - 1))
	{
		if (tab[num] > tab[num + 1])
		{
			i = tab[num];
			tab[num] = tab[num + 1];
			tab[num + 1] = i;
			num = 0;
		}
		else
			num++;
	}
}
