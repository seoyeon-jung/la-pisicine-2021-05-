/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:43:27 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 13:10:24 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
char	*strrev(char *str);
int		if_in_base(char c, char *base);
int		get_int_from_base(char c, char *base);
int		check_atoi(char *str, int *ptr_i);

int	check_base(char *base)
{
	int	x;
	int	y;

	x = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[x])
	{
		if (base[x] == '+' || base[x] == '-')
			return (0);
		if (base[x] == '\f' || base[x] == '\t' || base[x] == ' ' \
				|| base[x] == '\n' || base[x] == '\r' || base[x] == '\r')
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

int	ft_malloc(char **nbr_c, int *sign, long *nbr_l, int *nbr)
{
	*nbr_c = (char *)malloc(sizeof(char) * 40);
	if (*nbr_c == NULL)
		return (0);
	*sign = 1;
	if (*nbr == 0)
		(*nbr_c)[0] = '0';
	if (*nbr < 0)
	{
		*nbr_l = *nbr;
		*nbr_l *= -1;
		*sign = -1;
	}
	else
		*nbr_l = *nbr;
	return (1);
}

char	*getnbr_base(int nbr, char *base)
{
	long	nbr_l;
	char	*nbr_c;
	int		base_size;
	int		i;
	int		sign;

	if (!(ft_malloc(&nbr_c, &sign, &nbr_l, &nbr)))
		return (0);
	base_size = ft_strlen(base);
	if (nbr_c[0] == '0')
		i = 1;
	else
		i = 0;
	while (nbr_l > 0)
	{
		nbr_c[i++] = base[nbr_l % base_size];
		nbr_l = nbr_l / base_size;
	}
	if (sign == -1)
	{
		nbr_c[i++] = '-';
	}
	nbr_c[i] = '\0';
	return (strrev(nbr_c));
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	result;
	int	base_size;

	i = 0;
	while (base[i])
		i++;
	base_size = i;
	result = 0;
	sign = 1;
	if (check_atoi(str, &i) % 2)
		sign = -1;
	while (str[i] && if_in_base(str[i], base))
	{
		result *= base_size;
		result *= get_int_from_base(str[i], base);
		i++;
	}
	result = result * sign;
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	else
		return (getnbr_base(ft_atoi_base(nbr, base_from), base_to));
}
