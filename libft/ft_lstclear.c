/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:11:07 by melee             #+#    #+#             */
/*   Updated: 2023/05/04 15:16:13 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*node_delete;

	if (lst && *lst && del)
	{
		node = *lst;
		while (node)
		{
			node_delete = node;
			node = node->next;
			ft_lstdelone(node_delete, del);
		}
		*lst = (NULL);
	}
}
