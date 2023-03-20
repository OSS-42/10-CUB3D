/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1_spt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbertin <mbertin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:23:23 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/17 11:33:48 by mbertin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_c1_spt_pot(t_vault *data)
{
	data->s_par->s[7].s_row = 16.5;
	data->s_par->s[7].s_col = 15.5;
	data->s_par->s[7].texture = 3;
	data->s_par->s[8].s_row = 16.5;
	data->s_par->s[8].s_col = 20.5;
	data->s_par->s[8].texture = 3;
	data->s_par->s[9].s_row = 20.5;
	data->s_par->s[9].s_col = 15.5;
	data->s_par->s[9].texture = 3;
	data->s_par->s[10].s_row = 20.5;
	data->s_par->s[10].s_col = 20.5;
	data->s_par->s[10].texture = 3;
	data->s_par->s[11].s_row = 17.5;
	data->s_par->s[11].s_col = 20.5;
	data->s_par->s[11].texture = 5;
	data->s_par->s[12].s_row = 19.5;
	data->s_par->s[12].s_col = 20.5;
	data->s_par->s[12].texture = 5;
	load_c1_spt_tab_p1(data);
}

void	load_c1_spt_tab_p1(t_vault *data)
{
	data->s_par->s[13].s_row = 16.5;
	data->s_par->s[13].s_col = 16.5;
	data->s_par->s[13].texture = 11;
	data->s_par->s[14].s_row = 16.5;
	data->s_par->s[14].s_col = 17.5;
	data->s_par->s[14].texture = 11;
	data->s_par->s[15].s_row = 16.5;
	data->s_par->s[15].s_col = 18.5;
	data->s_par->s[15].texture = 11;
	data->s_par->s[16].s_row = 16.5;
	data->s_par->s[16].s_col = 21.5;
	data->s_par->s[16].texture = 11;
	data->s_par->s[17].s_row = 16.5;
	data->s_par->s[17].s_col = 22.5;
	data->s_par->s[17].texture = 11;
	data->s_par->s[18].s_row = 16.5;
	data->s_par->s[18].s_col = 23.5;
	data->s_par->s[18].texture = 11;
	load_c1_spt_tab_p2(data);
}

void	load_c1_spt_tab_p2(t_vault *data)
{
	data->s_par->s[19].s_row = 13.5;
	data->s_par->s[19].s_col = 16.5;
	data->s_par->s[19].texture = 11;
	data->s_par->s[20].s_row = 13.5;
	data->s_par->s[20].s_col = 17.5;
	data->s_par->s[20].texture = 11;
	data->s_par->s[21].s_row = 13.5;
	data->s_par->s[21].s_col = 18.5;
	data->s_par->s[21].texture = 11;
	data->s_par->s[22].s_row = 13.5;
	data->s_par->s[22].s_col = 19.5;
	data->s_par->s[22].texture = 11;
	data->s_par->s[23].s_row = 13.5;
	data->s_par->s[23].s_col = 20.5;
	data->s_par->s[23].texture = 11;
	data->s_par->s[24].s_row = 13.5;
	data->s_par->s[24].s_col = 21.5;
	data->s_par->s[24].texture = 11;
	data->s_par->s[25].s_row = 13.5;
	data->s_par->s[25].s_col = 22.5;
	data->s_par->s[25].texture = 11;
	data->s_par->s[26].s_row = 13.5;
	data->s_par->s[26].s_col = 23.5;
	data->s_par->s[26].texture = 11;
	load_c1_spt_tab_p3(data);
}

void	load_c1_spt_tab_p3(t_vault *data)
{
	data->s_par->s[27].s_row = 18.5;
	data->s_par->s[27].s_col = 16.5;
	data->s_par->s[27].texture = 11;
	data->s_par->s[28].s_row = 18.5;
	data->s_par->s[28].s_col = 17.5;
	data->s_par->s[28].texture = 11;
	data->s_par->s[29].s_row = 18.5;
	data->s_par->s[29].s_col = 18.5;
	data->s_par->s[29].texture = 11;
	data->s_par->s[30].s_row = 18.5;
	data->s_par->s[30].s_col = 21.5;
	data->s_par->s[30].texture = 11;
	data->s_par->s[31].s_row = 18.5;
	data->s_par->s[31].s_col = 22.5;
	data->s_par->s[31].texture = 11;
	data->s_par->s[32].s_row = 18.5;
	data->s_par->s[32].s_col = 23.5;
	data->s_par->s[32].texture = 11;
	data->s_par->s[115].s_row = 25.5;
	data->s_par->s[115].s_col = 6.5;
	data->s_par->s[115].texture = 3;
	load_c1_spt_tab_p4(data);
}

void	load_c1_spt_tab_p4(t_vault *data)
{
	data->s_par->s[33].s_row = 20.5;
	data->s_par->s[33].s_col = 16.5;
	data->s_par->s[33].texture = 11;
	data->s_par->s[34].s_row = 20.5;
	data->s_par->s[34].s_col = 17.5;
	data->s_par->s[34].texture = 11;
	data->s_par->s[35].s_row = 20.5;
	data->s_par->s[35].s_col = 18.5;
	data->s_par->s[35].texture = 11;
	data->s_par->s[36].s_row = 20.5;
	data->s_par->s[36].s_col = 21.5;
	data->s_par->s[36].texture = 11;
	data->s_par->s[37].s_row = 20.5;
	data->s_par->s[37].s_col = 22.5;
	data->s_par->s[37].texture = 11;
	data->s_par->s[38].s_row = 20.5;
	data->s_par->s[38].s_col = 23.5;
	data->s_par->s[38].texture = 11;
	data->s_par->s[116].s_row = 25.5;
	data->s_par->s[116].s_col = 8.5;
	data->s_par->s[116].texture = 3;
	load_c2_spt_pot(data);
}
