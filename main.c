/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorfan <amorfan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 17:21:16 by amorfan           #+#    #+#             */
/*   Updated: 2014/01/19 18:28:50 by amorfan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static t_mov	t[8] =
{
	{UP, ft_move_up},
	{RIGHT, ft_move_right},
	{DOWN, ft_move_down},
	{LEFT, ft_move_left},
	{97, ft_dash_left},
	{100, ft_dash_right},
	{-1, NULL},
};

int			loop_hook(t_data *env)
{
	int		i;

	i = -1;
	while (++i != 7 && env->save[i] != 1)
	{
		if (i == 6 && env->save[i] == 0)
			return (0);
	}
	i = -1;
	while (t[++i].key != -1)
	{
		if (env->save[i] == 1)
			t[i].ptr_f(env);
		if (env->save[6] == 1)
			ft_init_pos(5, 5, env);
	}
	ft_draw_background(*env);
	ft_get_wall(env);
	mlx_put_image_to_window(env->ptr, env->win, env->img, 0, 0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_data	env;

	if (argc == 1)
	{
		ft_putstr("usage : ");
		ft_putstr(argv[0]);
		ft_putstr(" map\n");
	}
	else
	{
		if (ft_init(&env, argv) == 0)
			return (0);
		ft_draw_background(env);
		ft_get_wall(&env);
		mlx_hook(env.win, 2, 1, key_press, &env);
		mlx_hook(env.win, 3, 2, key_release, &env);
		mlx_loop_hook(env.ptr, loop_hook, &env);
		mlx_expose_hook(env.win, expose_hook, &env);
		mlx_loop(env.ptr);
	}
	return (0);
}
