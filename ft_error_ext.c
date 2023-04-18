/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_ext.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:19:40 by kfortin           #+#    #+#             */
/*   Updated: 2023/04/18 13:24:01 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_long(char *tab)
{
	if (ft_atol(tab) > 2147483647 || atol(tab) < -2147483648)
	{
		ft_free_tab2((void **)tab);
		ft_write_error();
	}
}

void	ft_error_int(int tab)
{
	if (tab > 2147483647 || tab < -2147483648)
		ft_write_error();
}

void	ft_write_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

char	*ft_copy_ext(char *argv, int i)
{
	char	*s1;
	int		k;
	int		j;

	s1 = NULL;
	k = i;
	j = 0;
	while (argv[k++])
		j++;
	s1 = ft_calloc(j + 1, sizeof(char));
	if (!s1)
		return (NULL);
	k = i;
	j = 0;
	while (argv[k])
		s1[j++] = argv[k++];
	return (s1);
}

void	ft_tchek_ext(char *argv)
{
	int		i;
	int		j;
	char	*s1;

	i = 0;
	j = 0;
	s1 = NULL;
	while (argv[i])
	{
		if (argv[i] == '.')
		{
			s1 = ft_copy_ext(argv, i);
			if (ft_strcmp(s1, ".fdf") != 0)
				ft_write_error();
		}
		i++;
	}
	free(s1);
}
