/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 20:32:21 by seojung           #+#    #+#             */
/*   Updated: 2021/09/25 09:53:05 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
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
		return (num * (-1));
	return (num);
}
