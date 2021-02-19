/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 20:58:01 by hekang            #+#    #+#             */
/*   Updated: 2020/10/05 21:24:53 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(f)(void *),
		void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*cur;

	if (lst == NULL || (new = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	cur = new;
	tmp = lst->next;
	while (tmp)
	{
		if ((cur->next = ft_lstnew(f(tmp->content))) == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		cur = cur->next;
		tmp = tmp->next;
	}
	return (new);
}
