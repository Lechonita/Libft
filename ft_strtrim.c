/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:29:12 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/22 11:46:34 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	end;
	char	*s2;

	front = 0;
	if (s1 && set)
	{
		end = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > front)
			end--;
		s2 = (char *)malloc(sizeof(char) * (end - front + 1));
		if (!s2)
			return (NULL);
		else
			ft_strlcpy(s2, &s1[front], end - front + 1);
		return (s2);
	}
	return (NULL);
}

/*int	main(void)
{
	printf("%s\n", ft_strtrim("abqbc", "abc"));
	printf("%s\n", ft_strtrim("xavocadoyz", "xyz"));
}*/
