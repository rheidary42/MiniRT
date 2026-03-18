#include "minirt.h"

void	put_pixel(t_game *g, int x, int y, int color)
{
	char	*dst;

	dst = g->addr + (y * g->line_len + x * (g->bpp / 8));
	*(unsigned int *)dst = color;
}

// 0x00FF0000 → red
// 0x0000FF00 → green
// 0x000000FF → blue
void	render(t_game *g)
{
	int x;
	int y;
	int color;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			// << 16 -> shift into red channel
			// << 8 -> shift into green channel
			color = (x * 255 / WIDTH) << 16 | (y * 255 / HEIGHT) << 8;
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

int main(int argc, char **argv)
{
	t_game	game;

	// parse_input();
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, WIDTH,  HEIGHT, "MiniRT");
	game.img = mlx_new_image(game.mlx, WIDTH, HEIGHT);
	game.addr = mlx_get_data_addr(game.img, &game.bpp, 
			&game.line_len, &game.endian);

	render(&game);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 0, 0);

	mlx_hook(game.win, 17, 0, close_window, &game);
	mlx_loop(game.mlx);
	return (0);
}