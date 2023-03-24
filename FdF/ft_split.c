/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:55 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/21 17:57:35 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_is_charset(char c, char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

static int	ft_size_w(char *str, char *charset, int i)
{
	int	j;

	j = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset))
			return (j);
		j++;
		i++;
	}
	return (j);
}

int	ft_count_word(char *str, char *charset)
{
	int	i;
	int	j;
	int	count_word;

	i = 0;
	j = 0;
	count_word = 0;
    if (!str)
        return (0);
	while (str[i])
	{
		if (ft_is_charset(str[i], charset))
			j = 0;
		else if (!(ft_is_charset(str[i], charset)) && j == 0)
		{
			j = 1;
			count_word++;
		}
		i++;
	}
	return (count_word);
}

char	**ft_tab(char *str, char *charset, char **tab, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset) && !(ft_is_charset(str[i + 1],
					charset)) && j > 0)
		{
			k++;
			j = 0;
		}
		if (!(ft_is_charset(str[i], charset)))
		{
			if (j == 0)
				tab[k] = ft_calloc(sizeof(char), ft_size_w(str, charset, i) + 1);
			tab[k][j] = str[i];
			tab[k][j + 1] = 0;
			j++;
		}
		i++;
	}
	tab[ft_count_word(str, charset)] = NULL;
	return (tab);
}

int	*ft_split(char *str, char *charset)
{
	char	**tab;
	int		*tab_int;
	int		i;
	int		total_tab;

	i = 0;
	total_tab = ft_count_word(str, charset);
	tab = ft_calloc(sizeof(char *), (total_tab + 1));
	if (!tab)
		return (NULL);
	tab_int = ft_calloc(sizeof(int *), (total_tab + 1));
	if (!tab_int)
		return (NULL);
	tab = ft_tab(str, charset, tab, i);
	i = -1;
	while (++i < total_tab)
	{
		ft_error_long(tab, i, tab_int);
		tab_int[i] = ft_atol(tab[i]);
	}
	ft_free_tab2((void*)tab);
	return (tab_int);
}
