/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 21:07:15 by seojung           #+#    #+#             */
/*   Updated: 2021/09/22 16:12:54 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	num;

	hex = "0123456789abcdef";
	while (*str != '\0')
	{
		num = (unsigned char) *str;
		if (num < 32 || num == 127)
		{
			ft_putchar('\\');
			ft_putchar(hex[num / 16]);
			ft_putchar(hex[num % 16]);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
