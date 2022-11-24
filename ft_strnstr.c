/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:34:03 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/23 14:30:41 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	lenlittle;

	i = 0;
	lenlittle = ft_strlen((char *)little);
	if (!big || !little)
		return (NULL);
	if (lenlittle == 0 || (len > 0 && big == little))
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (ft_memcmp((char *)(big + i), (char *)little, lenlittle) == 0
			&& (size_t)lenlittle <= (len - i))
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
