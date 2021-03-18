/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 17:10:34 by hekang            #+#    #+#             */
/*   Updated: 2021/03/18 17:47:45 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void			hitlst_add(t_list *lst, void *obj, int obj_type)
{
	if (lst->content)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = init_list();
		lst = lst->next;
	}
	lst->content = hittable_create(obj, obj_type);
}

int				hitlst_hit(t_list *lst, t_hit_record *rec)
{
	int			hit_anything;
	t_hittable	*hittable;

	hit_anything = 0;
	while (lst && lst->content)
	{
		hittable = (t_hittable *)(lst->content);
		if ((*(hittable->hit))(hittable->obj, rec->ray, rec))
		{
			hit_anything = 1;
			rec->t_max = rec->t;
		}
		lst = lst->next;
	}
	return (hit_anything);
}
