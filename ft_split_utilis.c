/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utilis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:30:18 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 17:36:52 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_is_charset(char c, char *charset)
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

int	ft_size_w(char *str, char *charset, int i)
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

int	ft_check_hexa(char *tab)
{
	if (tab[0] == '0' && tab[1] == 'x')
		return (1);
	else
		return (0);
}
