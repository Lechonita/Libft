/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:01:59 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/24 15:16:11 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	ft_strlen(const char *s);*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lendst;
	size_t	lensrc;
	size_t	i;

	if ((!dst || !src) && !size)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	i = 0;
	if (size <= lendst || size == 0)
		return (lensrc + size);
	while (src[i] && lendst + i < size - 1)
	{
		dst[lendst + i] = (char)src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lensrc + lendst);
}
