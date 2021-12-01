/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:56:40 by seojung           #+#    #+#             */
/*   Updated: 2021/09/20 12:49:39 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= -214783648 || nb <= 214783647)
	{
		if (nb == -2147483648)
		{
			write(1, "-214783648", 11);
			return ;
		}
		if (nb < 0)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb < 10)
		{
			ft_putchar(nb + 48);
			return ;
		}
		else
		{
			ft_putchar(nb / 10 + 48);
		}
		ft_putchar(nb % 10 + 48);
	}
}

int main(void)
{
	ft_putnbr(-42);
}
