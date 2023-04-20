/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:10:55 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/19 17:47:01 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
				tab[k] = ft_calloc(sizeof(char), ft_size_w(str, charset, i)
						+ 1);
			tab[k][j] = str[i];
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
		tab_int = ft_split_2(tab, i, tab_int);
	ft_free_tab2((void *)tab);
	return (tab_int);
}

int	*ft_split_2(char **tab, int i, int *tab_int)
{
	if (ft_str_is_alpha(tab[i]) == 1)
		ft_error_alpha((void **)tab);
	if (ft_check_hexa(tab[i]) == 1)
	{
		ft_error_int(ft_atoi_base(tab[i], "123456789ABCDEF"));
		tab_int[i] = ft_atoi_base(tab[i], "123456789ABCDEF");
	}
	else
	{
		ft_error_long(tab[i]);
		tab_int[i] = (int)ft_atol(tab[i]);
	}
	return (tab_int);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= 'a' && str[i] <= 'z')))
			return (0);
		i++;
	}
	return (1);
}
