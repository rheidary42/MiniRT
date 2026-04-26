/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:41:17 by rheidary          #+#    #+#             */
/*   Updated: 2026/04/26 18:43:37 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "libs/minilibx-linux/mlx.h"
# include "colors.h"

# include <stdint.h>
# include <stdio.h>

# include <X11/keysym.h>

// Window Info
# define WIDTH 500
# define HEIGHT 500



// Colors
# define COLOR_BLACK   0x00000000
# define COLOR_WHITE   0x00FFFFFF
# define COLOR_RED     0x00FF0000
# define COLOR_GREEN   0x0000FF00
# define COLOR_BLUE    0x000000FF
# define COLOR_YELLOW  0x00FFFF00
# define COLOR_CYAN    0x0000FFFF
# define COLOR_MAGENTA 0x00FF00FF



// Data types
typedef int8_t		t_i8;
typedef int16_t		t_i16;
typedef int32_t		t_i32;
typedef int64_t		t_i64;
typedef uint8_t		t_u8;
typedef uint16_t	t_u16;
typedef uint32_t	t_u32;
typedef uint64_t	t_u64;

typedef t_i8		t_b8;
typedef t_i32		t_b32;

typedef float		t_f32;



// Structs
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_cam
{
	t_vec3	pos;
	t_vec3	dir;
	double	fov;
}	t_cam;

typedef struct s_light
{
	t_vec3	pos;
	double	brightness;
}	t_light;



// Objects
typedef struct s_sphere
{
	t_vec3	center;
	double	radius;
	t_vec3	color;
}	t_sphere;

typedef struct s_plane
{

}	t_plane;

typedef struct s_cylinder
{

}	t_cylinder;


// Main struct
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_game;

#endif