/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:48:07 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/16 17:16:40 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen((char *)s);
	if (c == 0)
		return ((char *)(s + i));
	while (i--)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	return (NULL);
}
