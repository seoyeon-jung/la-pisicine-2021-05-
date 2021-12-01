/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 15:23:25 by seojung           #+#    #+#             */
/*   Updated: 2021/09/22 16:14:36 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	unsigned int	n;

	n = 1;
	if (str[n - 1] >= 'a' && str[n - 1] <= 'z')
		str[n - 1] = str[n - 1] - 32;
	while (str[n])
	{
		if (!((str[n - 1] >= 'A' && str[n - 1] <= 'Z') \
				|| (str[n - 1] >= 'a' && str[n - 1] <= 'z') \
				|| (str[n - 1] >= '0' && str[n - 1] <= '9')))
		{
			if (str[n] >= 'a' && str[n] <= 'z')
				str[n] = str[n] - 32;
		}
		else
		{
			if (str[n] >= 'A' && str[n] <= 'Z')
				str[n] = str[n] + 32;
		}
		n++;
	}
	return (str);
}
