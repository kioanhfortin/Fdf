/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfortin <kfortin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:36:37 by kfortin           #+#    #+#             */
/*   Updated: 2023/03/22 16:01:47 by kfortin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_lstnew(void *str)
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->str = str;
	newnode->next = NULL;
	return (newnode);
}

// int	ft_lstsize(t_list *lst)
// {
// 	int	i;

// 	i = 0;
// 	if (!lst)
// 		return (0);
// 	while (lst->next != NULL)
// 	{
// 		lst = (struct s_list*)lst->next;
// 		i++;
// 	}
// 	return (i + 1);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (*lst)
		last->next = (struct t_list*)new;
	else
		*lst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (lst);
	while (lst->next != NULL)
	{
		lst = (t_list*)lst->next;
	}
	return (lst);
}

void	ft_listclear(t_list* head)
{
    t_list* current = head;
    t_list* temp;

    while (current != NULL)
	{
        temp = current;
		if (current->str)
			free(current->str);
        current = (struct s_list *)current->next;
		if (temp)
        	free(temp);
    }
}

// void	ft_listclear(t_list *map)
// {
// 	t_list	*cleanmap;
// 	t_list	*temp;

// 	cleanmap = map;
// 	temp = map;
// 	while (cleanmap)
// 	{
// 		if (cleanmap->str)
// 			free (cleanmap->str);
// 		temp = map;
// 		map = (t_list*)cleanmap->next;
// 		if (temp)
// 		{
// 			free(temp);
// 			temp = NULL;
// 		}
// 	}
// }

// void	ft_lstclear(t_list **lst)
// {
// 	t_list	*cleanlst;

// 	while (*lst)
// 	{
// 		cleanlst = (struct s_list*)(*lst)->next;
// 		ft_lstdelone(*lst);
// 		*lst = cleanlst;
// 	}
// }


// void	ft_lstdelone(t_list *lst)
// {
// 	if (lst->str)
// 		free(lst->str);
// 	if (lst)
// 		free(lst);
// }