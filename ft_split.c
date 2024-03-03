/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaux <asaux@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:57:12 by asaux             #+#    #+#             */
/*   Updated: 2024/02/28 12:57:17 by asaux            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//count the numbers of world in the array
int	count_words(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

//duplicate the numbers of character (l) in the new array
char	*ft_strldup(const char *s1, int l)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (s1[i] && i < l)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

//calculate the numbers of characters in the word
int	count_char(char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

//split one answer in a double array with one word by entry
char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	int		i;
	int		k;

	i = 0;
	k = 0;
	str = (char *) s;
	tab = malloc(sizeof (char *) * (count_words(str, c) + 1));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != '\0')
		{
			tab[k] = ft_strldup(&str[i], count_char(&str[i], c));
			k++;
		}
		while (str[i] != c && str[i] != '\0')
			i++;
	}
	tab[k] = NULL;
	return (tab);
}
