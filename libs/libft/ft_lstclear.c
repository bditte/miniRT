/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:57:05 by bditte            #+#    #+#             */
/*   Updated: 2019/11/17 15:29:47 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	ptr = *lst;
	while (ptr)
	{
		next_lst = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = next_lst;
	}
	*lst = NULL;
}
