/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:18:33 by amorfan           #+#    #+#             */
/*   Updated: 2013/11/26 00:20:01 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (*s1 != '\0' && i < n)
	{
		j = j + *s1;
		s1++;
		i++;
	}
	i = 0;
	while (*s2 != '\0' && i < n)
	{
		k = k + *s2;
		s2++;
		i++;
	}
	return (j - k);
}
