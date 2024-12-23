/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinursul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 15:53:17 by dinursul          #+#    #+#             */
/*   Updated: 2024/12/16 11:34:57 by dinursul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_copy;
	unsigned char		c_copy;
	size_t				i;

	i = 0;
	c_copy = (unsigned char)c;
	s_copy = (const unsigned char *)s;
	while (i < n)
	{
		if (s_copy[i] == c_copy)
			return ((void *)&s_copy[i]);
		i++;
	}
	return (NULL);
}
