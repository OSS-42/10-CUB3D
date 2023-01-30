/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art_intro_mini.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 09:00:40 by ewurstei          #+#    #+#             */
/*   Updated: 2022/12/22 00:01:37 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libart.h"

void	intro_minishell(void)
{
	printf("\n");
	lcyan();
	printf("                   /\\ \n");
	printf("                  /  \\ \n");
	printf("                 / /\\ \\ \n");
	printf("              /\\/ /  \\ \\/\\ \n");
	lred();
	printf("     /¯¯¯¯¯¯¯");
	lcyan();
	printf("/ / /    \\ \\ \\ ");
	lred();
	printf("¯¯¯¯¯¯¯\\ \n");
	printf("    / \\   / ");
	lcyan();
	printf("/ / /      \\ \\ \\ ");
	lred();
	printf(" \\   / \\ \n");
	printf("   /   \\/  ");
	lcyan();
	printf("/ / /        \\ \\ \\ ");
	lred();
	printf("  \\/   \\ \n");
	printf("  / \\ / \\ ");
	color_reset();
	intro_minishell_p2();
}

void	intro_minishell_p2(void)
{
	lcyan();
	printf("/ / /__________\\ \\ \\ ");
	lred();
	printf(" / \\ / \\ \n");
	printf(" /___/___");
	lcyan();
	printf("/_/ /            \\ \\_\\ ");
	lred();
	printf("___\\___\\ \n");
	lcyan();
	printf("    ________/              \\__");
	lyellow();
	printf("║");
	lcyan();
	printf("___");
	lyellow();
	printf("║");
	lcyan();
	printf("_ \n");
	printf("    \\            ");
	lyellow();
	printf("         ╔══ ║   ║");
	color_reset();
	intro_minishell_p3();
}

void	intro_minishell_p3(void)
{
	lcyan();
	printf("/ \n");
	printf("       \\        ");
	lyellow();
	printf("▀ ╔══ ║ ║ ╠═  ╚══ ╚══ \n");
	printf("    █▄ ▄█ ▀ █■■ █ ╚═╗ ╠═╣ ╚══");
	lcyan();
	printf("/\n");
	lyellow();
	printf("    █ ▀ █ █ █ █ █ ══╝ ║ ║ ");
	lcyan();
	printf("/ \n");
	lyellow();
	printf("    █   █ █     ");
	lcyan();
	printf("\\      / \n");
	lyellow();
	printf("    █   █          ");
	lcyan();
	printf("\\/ \n");
	color_reset();
	printf("________________________________________\n");
	printf("\n");
}
