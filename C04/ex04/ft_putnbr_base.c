/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 09:53:38 by seojung           #+#    #+#             */
/*   Updated: 2021/09/25 15:06:42 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	base_check(char *base)
{
	int	x;
	int	y;

	x = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[x])
	{
		if (base[x] == '-' || base[x] == '+')
			return (0);
		if (base[x] < 32 || base[x] > 126)
			return (0);
		y = x + 1;
		while (base[y])
		{
			if (base[x] == base[y])
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

void	ft_putnbr(int n, char *base, int base_n)
{
	if (n >= base_n)
	{
		ft_putnbr(n / base_n, base, base_n);
		ft_putnbr(n % base_n, base, base_n);
	}
	else
		write(1, &base[n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_size;
	int	i;

	i = 0;
	base_size = 0;
	if (base_check(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[base_size])
			base_size++;
		ft_putnbr(nbr, base, base_size);
	}
}
