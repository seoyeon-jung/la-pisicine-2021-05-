/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:44:34 by seojung           #+#    #+#             */
/*   Updated: 2021/09/25 12:57:52 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	base_check(char *base)
{
	int	x;
	int	y;

	x = 0;
	while (base[x])
	{
		if (base[x] == '-' || base[x] == '+' || base[x] < 32 || base[x] > 126)
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
	return (x);
}

int	atoi_check(char *str)
{
	int	i;
	int	minus_count;
	int	num;

	i = 0;
	minus_count = 0;
	num = 0;
	while ((str[i]) && (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' \
				|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	while ((str[i] != '\0') && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	while ((str[i] != '\0') && (str[i] >= '0' && str[i] <= '9'))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (minus_count % 2 != 0)
		return (num * -1);
	return (num);
}

int	base_plus_atoi(char str2, char *base)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (base[a])
	{
		if (str2 == base[a])
			return (a);
		a++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	num;
	int	nb;
	int	tmp;
	int	len;

	nb = 0;
	i = 0;
	len = base_check(base);
	if (len >= 2)
	{
		num = atoi_check(str[i]);
		tmp = base_plus_atoi(str[i], base);
		while (tmp != -1)
		{
			nb = (nb * len) + tmp;
			i++;
			tmp = base_plus_atoi(str[i], base);
		}
		return (nb *= num);
	}
	return (0);
}
