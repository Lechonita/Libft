/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:45:50 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/21 11:56:11 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int		ft_strlen(const char *s);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	if (start > (unsigned int)ft_strlen((char *)s))
	{
		sub = (char *)malloc(sizeof(char));
		if (!sub)
			return (NULL);
	}
	else
	{
		if (len > (unsigned int)ft_strlen((char *)(s + start)))
			len = (unsigned int)ft_strlen((char *)(s + start));
		sub = (char *)malloc(sizeof(char) * (len + 1));
		if (!sub)
			return (NULL);
		if (start < (unsigned int)ft_strlen(s))
		{
			while (s[start] && i < len)
				sub[i++] = s[start++];
		}
	}
	sub[i] = '\0';
	return (sub);
}

/*#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_substr("bonjour ca va bien", 3, 5));
}*/
