/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rheidary <rheidary@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/26 17:41:09 by rheidary          #+#    #+#             */
/*   Updated: 2026/04/26 18:02:29 by rheidary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# define RESET        "\033[0m"

/* Regular colors */
# define BLACK        "\033[30m"
# define RED          "\033[31m"
# define GREEN        "\033[32m"
# define YELLOW       "\033[33m"
# define BLUE         "\033[34m"
# define MAGENTA      "\033[35m"
# define CYAN         "\033[36m"
# define WHITE        "\033[37m"

/* Bold */
# define BBLACK       "\033[1;30m"
# define BRED         "\033[1;31m"
# define BGREEN       "\033[1;32m"
# define BYELLOW      "\033[1;33m"
# define BBLUE        "\033[1;34m"
# define BMAGENTA     "\033[1;35m"
# define BCYAN        "\033[1;36m"
# define BWHITE       "\033[1;37m"

/* Underline */
# define URED         "\033[4;31m"
# define UGREEN       "\033[4;32m"
# define UBLUE        "\033[4;34m"

/* Background colors */
# define ON_RED       "\033[41m"
# define ON_GREEN     "\033[42m"
# define ON_YELLOW    "\033[43m"
# define ON_BLUE      "\033[44m"

/* combined */
# define BLACK_BG_BLACK "\033[30;40m"

#endif