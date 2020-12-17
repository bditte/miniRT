/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bditte <bditte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:05:31 by bditte            #+#    #+#             */
/*   Updated: 2019/11/18 12:07:34 by bditte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*ptr;

	ptr = lst;
	if (!ptr)
		return (0);
	size = 1;
	while (ptr->next)
	{
		size++;
		ptr = ptr->next;
	}
	return (size);
}
