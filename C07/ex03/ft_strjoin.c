/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:25:04 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 12:38:41 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	make_new_str(char **strs, int size, char *sep)
{
	int	i;
	int	sep_size;

	i = 0;
	sep_size = 0;
	while (i < size)
	{
		sep_size = sep_size + ft_strlen(strs[i]);
		i++;
	}
	sep_size = sep_size + (size - 1) * ft_strlen(sep) + 1;
	return (sep_size);
}

char	*ft_strcat(char *dest, char *src)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (dest[x])
		x++;
	while (src[y])
	{
		dest[x + y] = src[y];
		y++;
	}
	dest[x + y] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	char	*str;

	if (size == 0)
	{
		str = malloc(sizeof(char));
		*str = 0;
		return (str);
	}
	str = malloc(sizeof(char) * make_new_str(strs, size, sep));
	if (str == NULL)
		return (0);
	*str = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		if (i < size - 1)
			ft_strcat(str, sep);
		i++;
	}
	return (str);
}
