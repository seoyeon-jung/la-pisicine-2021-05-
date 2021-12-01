/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 09:34:29 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 10:07:10 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		src_len;
	int		i;
	char	*dest;

	src_len = 0;
	while (src[src_len])
		src_len++;
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (dest == NULL)
		return (0);
	i = 0;
	while (i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
