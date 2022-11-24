/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 13:55:27 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/23 16:42:17 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_count(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	if (!s || !s[0])
		return (0);
	if (s[0] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

int	word_len(const char *s, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

char	*word_generator(const char *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		len;
	char		*word;

	i = 0;
	j = 0;
	len = word_len(s + i, c);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (s[i] && s[i] != c)
		word[j++] = s[i++];
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t		i;
	size_t		j;
	size_t		counter;
	char		**res;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	counter = word_count(s, c);
	res = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!res)
		return (NULL);
	while (s[i] && j < counter)
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res[j++] = word_generator(s + i, c);
		while (s[i] && s[i] != c)
			i++;
	}
	res[j] = 0;
	return (res);
}
