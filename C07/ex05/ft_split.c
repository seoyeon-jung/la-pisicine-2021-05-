/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seojung <seojung@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:46:50 by seojung           #+#    #+#             */
/*   Updated: 2021/09/27 13:57:34 by seojung          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	char_separate(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_separate(str[i + 1], charset) == 1 && \
				char_separate(str[i], charset))
		{
			word++;
		}
	}
	return (word);
}

void	print_word(char *dest, char *from, char *charset)
{
	int	i;

	i = 0;
	while (char_separate(from[i], charset) == 0)
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

void	print_split(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (char_separate(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (char_separate(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			print_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		word;

	word = count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * (word + 1));
	result[word] = 0;
	print_split(result, str, charset);
	return (result);
}
