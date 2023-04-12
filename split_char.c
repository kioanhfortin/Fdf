/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 17:29:30 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/18 17:38:45 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_charset(char c, char *charset)
{
	int		j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
			return (1);
		j++;
	}
	return (0);
}

int	ft_size_w(char *str, int i, char *charset)
{
	int		j;

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
	int		j;
	int		i;
	int		count_word;

	j = 0;
	i = 0;
	count_word = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset))
			j = 0;
		else if ((!(ft_is_charset(str[i], charset))) && j == 0)
		{
			j = 1;
			count_word ++;
		}
		i++;
	}
	return (count_word);
}

char	**ft_tab(char *str, char *charset, char **tab, int i)
{
	int		k;
	int		j;

	k = 0;
	j = 0;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset)
			&& (!(ft_is_charset(str[i + 1], charset))) && j > 0)
		{
			k++;
			j = 0;
		}
		if (!(ft_is_charset(str[i], charset)))
		{
			if (j == 0)
				tab[k] = malloc(sizeof(char) * ft_size_w(str, i, charset) + 1);
			tab[k][j] = str[i];
			tab[k][j + 1] = 0;
			j++;
		}
		i++;
	}
	tab[ft_count_word(str, charset)] = NULL;
	return (tab);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char *) * ft_count_word(str, charset) + 1);
	tab = ft_tab(str, charset, tab, i);
	return (tab);
}
