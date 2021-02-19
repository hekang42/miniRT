/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hitlst_info_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hekang <hekang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:07:26 by hekang            #+#    #+#             */
/*   Updated: 2021/02/02 16:17:18 by hekang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_hitlst_info       *hitlst_info_new(t_ray *r)
// {
//     t_hitlst_info   *result;

//     result = (t_hitlst_info *)malloc(sizeof(t_hitlst_info));
//     result->ray = r;
//     result->t_min = HIT_T_MIN;
//     result->t_max = INFINITY;
//     result->rec = hit_record_new();
//     return (result);
// }

// void                free_hitlst_info(t_hitlst_info *info, int is_ray_ori_free)
// {
//     free_ray(info->ray, is_ray_ori_free);
//     free_hit_record(info->rec);
//     free(info);
// }