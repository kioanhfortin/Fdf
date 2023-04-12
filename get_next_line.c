/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:31:18 by kfortin           #+#    #+#             */
/*   Updated: 2022/07/11 14:21:18 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_stock_line(char **stash, char **res, int end)
{
	int		len;
	char	*new_stash;
	int		flag;

	flag = 0;
	*res = ft_strdup(*stash, end, 1);
	len = ft_strlen(*stash + end + 1);
	if (!len)
	{
		free(*stash);
		*stash = NULL;
		return (*res);
	}
	new_stash = ft_strdup(*stash + end + 1, end, 2);
	free(*stash);
	*stash = new_stash;
	return (*res);
}

char	*ft_strdup(char *src, int end, int flag)
{
	char	*dup;
	int		i;

	i = -1;
	if (flag == 1)
	{
		dup = malloc(sizeof(char) * (end + 2));
		if (dup == 0)
			return (NULL);
		while (++i <= end)
			dup[i] = src[i];
		dup[i] = '\0';
	}
	if (flag == 2)
	{
		dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
		if (dup == 0)
			return (NULL);
		while (src[++i])
			dup[i] = src[i];
		dup[i] = '\0';
	}
	return (dup);
}

int	ft_last_line(char **stash, char **res, int size_read)
{
	int	i;

	i = 0;
	if (size_read < 0)
		return (-1);
	if (*stash)
		i = ft_strchr(*stash);
	if (*stash && (i > -1))
		ft_stock_line(stash, res, i);
	if (*stash)
	{
		*res = *stash;
		*stash = NULL;
		return (0);
	}
	*res = NULL;
	return (0);
}

void	ft_norminette(char **buf, char **stash)
{
	if (!(*stash))
		*stash = ft_strdup(*buf, BUFFER_SIZE, 2);
	else
		*stash = ft_strjoin(*stash, *buf);
	free(*buf);
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*stash;
	char		*res;
	int			j;

	res = NULL;
	j = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (read(fd, buf, BUFFER_SIZE) > 0 || ft_strchr(stash) != -1)
	{
		ft_norminette(&buf, &stash);
		j = ft_strchr(stash);
		if (j > -1)
			return (ft_stock_line(&stash, &res, j));
		j = 0;
		buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	}
	free(buf);
	if ((ft_last_line(&stash, &res, j)) < 0)
		return (NULL);
	return (res);
}
