/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouillo <jrouillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 15:04:44 by jrouillo          #+#    #+#             */
/*   Updated: 2022/11/22 11:52:09 by jrouillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_size(long nb)
{
	size_t	size;

	size = 0;
	if (nb < 0)
	{
		nb *= -1;
		size++;
	}
	if (nb == 0)
		size = 1;
	else
	{
		while (nb)
		{
			nb /= 10;
			size++;
		}
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	size;
	char	*s;

	nb = (long)n;
	size = ft_size(nb);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (NULL);
	else
		s[size] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		s[0] = '-';
	}
	else if (nb == 0)
		s[0] = '0';
	while (nb > 0)
	{
		s[size -1] = nb % 10 + '0';
		nb /= 10;
		size--;
	}
	return (s);
}
