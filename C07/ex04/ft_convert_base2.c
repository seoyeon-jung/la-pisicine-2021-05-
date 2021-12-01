/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:43:34 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 13:10:34 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*strrev(char *str)
{
	int		i;
	int		size;
	char	tmp;

	size = ft_strlen(str);
	size--;
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		i++;
		size--;
	}
	return (str);
}

int	if_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != c && base[i])
		i++;
	if (base[i] == '\0')
		return (0);
	else
		return (1);
}

int	get_int_from_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	check_atoi(char *str, int *ptr_i)
{
	int	minus_count;
	int	i;

	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' ' \
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		i++;
	minus_count = 0;
	while (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			minus_count++;
		i++;
	}
	*ptr_i = 1;
	return (minus_count);
}
