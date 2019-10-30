/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-kad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 15:58:11 by yait-kad          #+#    #+#             */
/*   Updated: 2019/10/30 18:45:50 by yait-kad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		find_word(char const *s1, char c1)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	while (s1[j] != '\0')
	{
		if (s1[j] == c1)
			nb = 0;
		else
		{
			if (nb == 0)
				i++;
			nb = 1;
		}
		j++;
	}
	return (i);
}

char	*size_word(char const *s2, int *n, char c2)
{
	char	*word;
	int		i;
	int		start;
	int		end;

	i = *n;
	while (s2[i] == c2)
		i++;
	start = i;
	while (s2[i] != c2)
		i++;
	end = i;
	*n = i;
	word = (char*)malloc(sizeof(char) * ((end - start) + 1));
	i = 0;
	while (start < end)
	{
		word[i] = s2[start];
		start++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		size;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	len = find_word(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * len + 1)))
		return (NULL);
	size = 0;
	i = 0;
	while (size < len)
	{
		dest[size] = size_word(s, &i, c);
		size++;
	}
	dest[size] = 0;
	return (dest);
}
