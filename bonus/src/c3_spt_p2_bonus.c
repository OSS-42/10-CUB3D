/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_spt_p2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:26:04 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/16 18:23:26 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_c3_spt_tab_p5(t_vault *data)
{
	data->s_par->s[91].s_row = 11.5;
	data->s_par->s[91].s_col = 1.5;
	data->s_par->s[91].texture = 11;
	data->s_par->s[92].s_row = 11.5;
	data->s_par->s[92].s_col = 2.5;
	data->s_par->s[92].texture = 11;
	data->s_par->s[93].s_row = 11.5;
	data->s_par->s[93].s_col = 3.5;
	data->s_par->s[93].texture = 11;
	data->s_par->s[94].s_row = 11.5;
	data->s_par->s[94].s_col = 4.5;
	data->s_par->s[94].texture = 11;
	data->s_par->s[95].s_row = 11.5;
	data->s_par->s[95].s_col = 5.5;
	data->s_par->s[95].texture = 11;
	load_c3_spt_lmp(data);
}

void	load_c3_spt_lmp(t_vault *data)
{
	data->s_par->s[96].s_row = 2.5;
	data->s_par->s[96].s_col = 2.5;
	data->s_par->s[96].texture = 9;
	data->s_par->s[113].s_row = 2.5;
	data->s_par->s[113].s_col = 3.5;
	data->s_par->s[113].texture = 9;
	data->s_par->s[97].s_row = 2.5;
	data->s_par->s[97].s_col = 4.5;
	data->s_par->s[97].texture = 9;
	data->s_par->s[98].s_row = 5.5;
	data->s_par->s[98].s_col = 2.5;
	data->s_par->s[98].texture = 9;
	data->s_par->s[99].s_row = 5.5;
	data->s_par->s[99].s_col = 3.5;
	data->s_par->s[99].texture = 9;
	data->s_par->s[100].s_row = 5.5;
	data->s_par->s[100].s_col = 4.5;
	data->s_par->s[100].texture = 9;
	load_c3_spt_lmp_p1(data);
}

void	load_c3_spt_lmp_p1(t_vault *data)
{
	data->s_par->s[101].s_row = 7.5;
	data->s_par->s[101].s_col = 2.5;
	data->s_par->s[101].texture = 9;
	data->s_par->s[102].s_row = 7.5;
	data->s_par->s[102].s_col = 3.5;
	data->s_par->s[102].texture = 9;
	data->s_par->s[103].s_row = 7.5;
	data->s_par->s[103].s_col = 4.5;
	data->s_par->s[103].texture = 9;
	data->s_par->s[104].s_row = 9.5;
	data->s_par->s[104].s_col = 2.5;
	data->s_par->s[104].texture = 9;
	data->s_par->s[105].s_row = 9.5;
	data->s_par->s[105].s_col = 3.5;
	data->s_par->s[105].texture = 9;
	data->s_par->s[106].s_row = 9.5;
	data->s_par->s[106].s_col = 4.5;
	data->s_par->s[106].texture = 9;
	load_c3_spt_lmp_p2(data);
}

void	load_c3_spt_lmp_p2(t_vault *data)
{
	data->s_par->s[107].s_row = 11.5;
	data->s_par->s[107].s_col = 2.5;
	data->s_par->s[107].texture = 9;
	data->s_par->s[108].s_row = 11.5;
	data->s_par->s[108].s_col = 3.5;
	data->s_par->s[108].texture = 9;
	data->s_par->s[109].s_row = 11.5;
	data->s_par->s[109].s_col = 4.5;
	data->s_par->s[109].texture = 9;
	data->s_par->s[110].s_row = 13.5;
	data->s_par->s[110].s_col = 2.5;
	data->s_par->s[110].texture = 9;
	data->s_par->s[111].s_row = 13.5;
	data->s_par->s[111].s_col = 3.5;
	data->s_par->s[111].texture = 9;
	data->s_par->s[112].s_row = 13.5;
	data->s_par->s[112].s_col = 4.5;
	data->s_par->s[112].texture = 9;
}
