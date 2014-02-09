/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 18:14:12 by amorfan           #+#    #+#             */
/*   Updated: 2013/12/08 18:31:54 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wd_nb(char const *s, char c);
int		ft_ltr_nb(char const *s, char c);

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		lock;

	i = 0;
	lock = 1;
	if ((tab = (char **)malloc(sizeof(char *) * (ft_wd_nb(s, c) + 1))) == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s != c && lock == 1)
		{
			tab[i] = (char *)malloc(sizeof(char) * (ft_ltr_nb(s, c) + 1));
			tab[i] = ft_strncpy(tab[i], s, ((size_t)ft_ltr_nb(s, c)));
			i++;
			lock = 0;
		}
		else if (*s == c)
			lock = 1;
		s++;
	}
	tab[i] = NULL;
	return (tab);
}

int		ft_wd_nb(char const *s, char c)
{
	int		word_nb;
	int		i;

	i = 0;
	word_nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			word_nb++;
			while (s[i] != c)
				i++;
		}
		while (s[i] == c)
			i++;
	}
	return (word_nb);
}

int		ft_ltr_nb(char const *s, char c)
{
	int		letter_nb;

	letter_nb = 0;
	while (s[letter_nb] != c && s[letter_nb] != '\0')
		letter_nb++;
	return (letter_nb);
}
