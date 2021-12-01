/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:57:15 by seojung           #+#    #+#             */
/*   Updated: 2021/09/20 13:46:31 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	size--;
	while (i < size)
	{
		j = tab[i];
		tab[i] = tab[size];
		tab[size] = j;
		i++;
		size--;
	}
}
