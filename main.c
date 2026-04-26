/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:12:03 by rheidary          #+#    #+#             */
/*   Updated: 2026/04/26 18:02:06 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/minirt.h"

// !!! SKY/BACKGROUND WITH PUT_PIXEL?
// account for offset of the screen and pixels of image
// hard coded for 32 pixels 
void	put_pixel(t_game *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

t_vec3	vec_3(double x, double y, double z)
{
	t_vec3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

// t_ray	generate_ray(int x, int y)
// {
// 	t_ray	ray;
// 	double	nx;
// 	double	ny;
// 	double	aspect;
// 	double	scale;

// 	aspect = (double)WIDTH / HEIGHT;
// 	scale = tan((70.0 * 0.5) * M_PI / 180.0);
// 	nx = (2.0 * x / WIDTH - 1.0) * aspect * scale;
// 	ny = (1.0 - 2.0 * y / HEIGHT) * scale;
// 	ray.origin = vec_3(0, 0, 0);
// 	ray.dir = vec_3(nx, ny, -1);
// 	ray.dir = fast_normalize(ray.dir);
// }

// 0x00FF0000 → red
// 0x0000FF00 → green
// 0x000000FF → blue
void	render(t_game *g)
{
	int		x;
	int		y;
	int		color;
	t_ray	ray;

	y = 0;
	while (y < HEIGHT)
	{
		printf(BLACK_BG_BLACK "\n%d Rows remaining\n" RESET, HEIGHT - y);
		x = 0;
		while (x < WIDTH)
		{
			// << 16 -> shift into red channel
			// << 8 -> shift into green channel
			color = (x * 255 / WIDTH) << 16 | (y * 255 / HEIGHT);
			// ray = generate_ray(x, y);
			// color = trace_ray(ray);
			// int color =
			// (
			// (int)((ray.dir.x + 1) * 127.5) << 16 |
			// (int)((ray.dir.y + 1) * 127.5) << 8 |
			// (int)((ray.dir.z + 1) * 127.5)
			// );
			put_pixel(g, x, y, color);
			x++;
		}
		y++;
	}
}

int	close_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

// using X11 key symbol defintion macros
int	key_hook(int keycode, t_game *g)
{
	if (keycode != XK_Return)
		printf(CYAN "\nkeycode: %d\n" RESET, keycode);
	if (keycode == XK_Escape || keycode == XK_q)
		close_window(g);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	// parse_input();
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH, HEIGHT, "MiniRT");
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.addr = mlx_get_data_addr(game.img, &game.bpp,
			&game.line_len, &game.endian);

	render(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);

	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}
