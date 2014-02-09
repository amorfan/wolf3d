/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:07:14 by amorfan           #+#    #+#             */
/*   Updated: 2014/01/18 19:57:33 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		ft_dash_right(t_data *e)
{
	e->pos.Py -= sin(ft_get_radian(e->pos.a - 90)) * 5;
	e->pos.Px += cos(ft_get_radian(e->pos.a - 90)) * 5;
	if (e->map[(int)(e->pos.Py / 64)][(int)(e->pos.Px / 64)] == 1)
		ft_dash_left(e);
}

void		ft_dash_left(t_data *e)
{
	e->pos.Py -= sin(ft_get_radian(e->pos.a + 90)) * 5;
	e->pos.Px += cos(ft_get_radian(e->pos.a + 90)) * 5;
	if (e->map[(int)(e->pos.Py / 64)][(int)(e->pos.Px / 64)] == 1)
		ft_dash_right(e);
}

void		ft_move_up(t_data *e)
{
	e->pos.Py -= sin(ft_get_radian(e->pos.a)) * 5;
	e->pos.Px += cos(ft_get_radian(e->pos.a)) * 5;
	if (e->map[(int)(e->pos.Py / 64)][(int)(e->pos.Px / 64)] == 1)
		ft_move_down(e);
}

void		ft_move_down(t_data *e)
{
	e->pos.Py += sin(ft_get_radian(e->pos.a)) * 5;
	e->pos.Px -= cos(ft_get_radian(e->pos.a)) * 5;
	if (e->map[(int)(e->pos.Py / 64)][(int)(e->pos.Px / 64)] == 1)
		ft_move_up(e);
}

void		ft_move_left(t_data *e)
{
	e->pos.a += 5;
	if (e->pos.a > 359)
		e->pos.a -= 359;
}
