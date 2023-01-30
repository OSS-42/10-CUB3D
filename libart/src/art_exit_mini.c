/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   art_exit_mini.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:04:28 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/30 09:05:51 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libart.h"

void	exit_minishell(void)
{
	printf("\n");
	lcyan();
	printf("	                        ░             \n");
	printf("	                        ▒             \n");
	lred();
	printf("	 ╔══════════════\\≡≡≡≡≡≡/");
	lcyan();
	printf("▓");
	lred();
	printf("════════════╗\n");
	printf("	 ║               ¯¯¯¯¯¯ ");
	lcyan();
	printf("█");
	lred();
	printf("            ║\n");
	printf("	 ║");
	lcyan();
	printf("   ████████ ██    ██  █ ████████   ");
	lred();
	printf("║\n");
	printf("	 ║   ");
	exit_minishell_p2();
}

void	exit_minishell_p2(void)
{
	lyellow();
	printf("██");
	lcyan();
	printf("        ██  ██  /¯\\   ██      ");
	lred();
	printf("║\n");
	printf("	 ║   ");
	lyellow();
	printf("██████      ██    ");
	lcyan();
	printf("\\O/   ██      ");
	lred();
	printf("║\n");
	printf("	 ║   ");
	lyellow();
	printf("██        ██  ██   ");
	lcyan();
	printf("▒");
	lyellow();
	printf("    ██      ");
	lred();
	printf("║\n");
	printf("	 ║   ");
	exit_minishell_p3();
}

void	exit_minishell_p3(void)
{
	lyellow();
	printf("████████ ██    ██ ");
	lcyan();
	printf("/ \\   ");
	lyellow();
	printf("██      ");
	lred();
	printf("║\n");
	printf("	 ╚═                                 ═╝\n");
	lyellow();
	printf("	═════════Ø═══════════════════Ø═════════\n");
	printf("\n");
	color_reset();
}
