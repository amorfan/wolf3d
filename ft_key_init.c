/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 19:24:46 by amorfan           #+#    #+#             */
/*   Updated: 2014/01/19 18:58:28 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "wolf.h"

int			key_press(int keycode, t_data *env)
{
	if (keycode == ESCAPE)
		exit(0);
	if (keycode == UP)
		env->save[0] = 1;
	if (keycode == RIGHT)
		env->save[1] = 1;
	if (keycode == DOWN)
		env->save[2] = 1;
	if (keycode == LEFT)
		env->save[3] = 1;
	if (keycode == 97)
		env->save[4] = 1;
	if (keycode == 100)
		env->save[5] = 1;
	if (keycode == 65293)
		env->save[6] = 1;
	return (0);
}

int			key_release(int keycode, t_data *env)
{
	if (keycode == UP)
		env->save[0] = 0;
	if (keycode == RIGHT)
		env->save[1] = 0;
	if (keycode == DOWN)
		env->save[2] = 0;
	if (keycode == LEFT)
		env->save[3] = 0;
	if (keycode == 97)
		env->save[4] = 0;
	if (keycode == 100)
		env->save[5] = 0;
	if (keycode == 65293)
		env->save[6] = 0;
	return (0);
}

int			expose_hook(t_data *env)
{
	t_data	*data;

	data = (t_data *)env;
	mlx_put_image_to_window(data->ptr, data->win, data->img, 0, 0);
	return (0);
}

int			ft_init(t_data *e, char **argv)
{
	if (open(argv[1], O_RDONLY) == -1)
	{
		perror(argv[1]);
		return (0);
	}
	e->map = ft_gettab(argv, e);
	e->ptr = mlx_init();
	e->img = mlx_new_image(e->ptr, WIN_X, WIN_Y);
	e->win = mlx_new_window(e->ptr, WIN_X, WIN_Y, "Wolf3d");
	e->data = mlx_get_data_addr(e->img, &e->bpp, &e->sizeline, &e->endian);
	return (ft_init_pos(5, 5, e));
}

int			ft_init_pos(int x, int y, t_data *env)
{
	if (y <= env->y_max && x <= env->x_max && env->map[y][x] != 1)
	{
		env->pos.a = 90;
		env->pos.Px = x * 64 + 32;
		env->pos.Py = y * 64 + 32;
		return (1);
	}
	ft_putstr("Start position error\n");
	return (0);
}
