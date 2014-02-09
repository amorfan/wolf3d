/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 12:05:14 by amorfan           #+#    #+#             */
/*   Updated: 2014/01/10 20:52:08 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_countn(int n);
char			*ft_check(char *str, int n, size_t countn);
char			*ft_except(char *str);

char			*ft_itoa(int n)
{
	char		*str;
	size_t		countn;
	int			i;

	i = 0;
	countn = 0;
	str = NULL;
	if (n == -2147483648)
		return (str = ft_except(str));
	if (n < 0)
	{
		n = n * -1;
		i = 1;
	}
	countn = ft_countn(n) + i;
	if ((str = ft_strnew(countn + 1)) == NULL)
		return (NULL);
	ft_check(str, n, countn);
	if (i == 1)
		str[0] = '-';
	return (str);
}

size_t			ft_countn(int n)
{
	size_t		count;

	count = 0;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char			*ft_check(char *str, int n, size_t countn)
{
	str = str + countn;
	while (countn > 0)
	{
		*str = n % 10 + '0';
		n = n / 10;
		countn--;
		str--;
	}
	*str = n % 10 + '0';
	return (str);
}

char			*ft_except(char *str)
{
	size_t	t;

	t = 11;
	str = ft_strnew(11);
	return (ft_strcpy(str, "-2147483648"));
}
