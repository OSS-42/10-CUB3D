/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2_spt_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:24:25 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/16 17:45:46 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_c2_spt_pot(t_vault *data)
{
	data->s_par->s[39].s_row = 8.5;
	data->s_par->s[39].s_col = 15.5;
	data->s_par->s[39].texture = 3;
	data->s_par->s[40].s_row = 8.5;
	data->s_par->s[40].s_col = 20.5;
	data->s_par->s[40].texture = 3;
	data->s_par->s[41].s_row = 12.5;
	data->s_par->s[41].s_col = 15.5;
	data->s_par->s[41].texture = 3;
	data->s_par->s[42].s_row = 12.5;
	data->s_par->s[42].s_col = 20.5;
	data->s_par->s[42].texture = 3;
	data->s_par->s[43].s_row = 7.5; 
	data->s_par->s[43].s_col = 20.5;
	data->s_par->s[43].texture = 5;
	load_c2_spt_tab_p1(data);
}

void	load_c2_spt_tab_p1(t_vault *data)
{
	data->s_par->s[44].s_row = 5.5;
	data->s_par->s[44].s_col = 16.5;
	data->s_par->s[44].texture = 11;
	data->s_par->s[45].s_row = 5.5;
	data->s_par->s[45].s_col = 17.5;
	data->s_par->s[45].texture = 11;
	data->s_par->s[46].s_row = 5.5;
	data->s_par->s[46].s_col = 18.5;
	data->s_par->s[46].texture = 11;
	data->s_par->s[47].s_row = 5.5;
	data->s_par->s[47].s_col = 19.5;
	data->s_par->s[47].texture = 11;
	data->s_par->s[48].s_row = 5.5;
	data->s_par->s[48].s_col = 20.5;
	data->s_par->s[48].texture = 11;
	data->s_par->s[49].s_row = 5.5;
	data->s_par->s[49].s_col = 21.5;
	data->s_par->s[49].texture = 11;
	data->s_par->s[50].s_row = 5.5;
	data->s_par->s[50].s_col = 22.5;
	data->s_par->s[50].texture = 11;
	data->s_par->s[51].s_row = 5.5;
	data->s_par->s[51].s_col = 23.5;
	data->s_par->s[51].texture = 11;
	load_c2_spt_tab_p2(data);
}

void	load_c2_spt_tab_p2(t_vault *data)
{
	data->s_par->s[52].s_row = 8.5;
	data->s_par->s[52].s_col = 16.5;
	data->s_par->s[52].texture = 11;
	data->s_par->s[53].s_row = 8.5;
	data->s_par->s[53].s_col = 17.5;
	data->s_par->s[53].texture = 11;
	data->s_par->s[54].s_row = 8.5;
	data->s_par->s[54].s_col = 18.5;
	data->s_par->s[54].texture = 11;
	data->s_par->s[55].s_row = 8.5;
	data->s_par->s[55].s_col = 21.5;
	data->s_par->s[55].texture = 11;
	data->s_par->s[56].s_row = 8.5;
	data->s_par->s[56].s_col = 22.5;
	data->s_par->s[56].texture = 11;
	data->s_par->s[57].s_row = 8.5;
	data->s_par->s[57].s_col = 23.5;
	data->s_par->s[57].texture = 11;
	load_c2_spt_tab_p3(data);
}

void	load_c2_spt_tab_p3(t_vault *data)
{
	data->s_par->s[58].s_row = 11.5;
	data->s_par->s[58].s_col = 16.5;
	data->s_par->s[58].texture = 11;
	data->s_par->s[59].s_row = 11.5;
	data->s_par->s[59].s_col = 17.5;
	data->s_par->s[59].texture = 11;
	data->s_par->s[60].s_row = 11.5;
	data->s_par->s[60].s_col = 18.5;
	data->s_par->s[60].texture = 11;
	data->s_par->s[61].s_row = 11.5;
	data->s_par->s[61].s_col = 19.5;
	data->s_par->s[61].texture = 11;
	data->s_par->s[62].s_row = 11.5;
	data->s_par->s[62].s_col = 20.5;
	data->s_par->s[62].texture = 11;
	data->s_par->s[63].s_row = 11.5;
	data->s_par->s[63].s_col = 21.5;
	data->s_par->s[63].texture = 11;
	data->s_par->s[64].s_row = 11.5;
	data->s_par->s[64].s_col = 22.5;
	data->s_par->s[64].texture = 11;
	data->s_par->s[65].s_row = 11.5;
	data->s_par->s[65].s_col = 23.5;
	data->s_par->s[65].texture = 11;
	load_c3_spt_pot(data);
}
