/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:12:15 by amorfan           #+#    #+#             */
/*   Updated: 2013/12/08 13:11:43 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*a;
	size_t		i;

	i = 0;
	a = s;
	while (i <= n)
	{
		a[i] = '\0';
		i++;
	}
}
