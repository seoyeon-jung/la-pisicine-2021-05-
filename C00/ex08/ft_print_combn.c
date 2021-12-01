/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:08:26 by seojung           #+#    #+#             */
/*   Updated: 2021/09/18 19:50:07 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char arr)
{
	write(1, &arr, 1);
}

void	num(char *arr, int n, int index, int x)
{
	int	i;

	if (index == n)
	{
		write(1, arr, n);
		if (arr [0] != 10 - n + 48)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		return ;
	}
	i = x;
	while (1)
	{
		if (i > 10 - n + index)
		{
			return ;
		}
		arr[index] = i + 48;
		num(arr, n, index + 1, i + 1);
		i++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	char	arr[9];

	num(arr, n, 0, 0);
	return ;
}
