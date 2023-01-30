/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libart.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:15:03 by ewurstei          #+#    #+#             */
/*   Updated: 2023/01/19 20:50:34 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBART_H
# define LIBART_H

# include <stdio.h>

/***** PRETTY *****/
/***** art_intro_mini.c *****/
void	intro_minishell(void);
void	intro_minishell_p2(void);
void	intro_minishell_p3(void);
void	color_reset(void);

/***** art_exit_mini.c *****/
void	exit_minishell(void);
void	exit_minishell_p2(void);
void	exit_minishell_p3(void);
void	cyan(void);

/***** art_intro_daftpunk.c *****/
// void	intro_daftpunk(void);
// void	intro_daftpunk_p2(void);
// void	intro_daftpunk_p3(void);
// void	intro_daftpunk_p4(void);

/***** art_colors.c *****/
void	lred(void);
void	lcyan(void);
void	lyellow(void);
void	lgray(void);
void	dgray(void);

#endif
