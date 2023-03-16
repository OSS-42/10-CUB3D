/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c3_spt_p1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ewurstei <ewurstei@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 17:25:12 by ewurstei          #+#    #+#             */
/*   Updated: 2023/03/16 17:47:42 by ewurstei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D_bonus.h"

void	load_c3_spt_pot(t_vault *data)
{
	data->s_par->s[66].s_row = 5.5;
	data->s_par->s[66].s_col = 5.5;
	data->s_par->s[66].texture = 3;
	data->s_par->s[67].s_row = 9.5;
	data->s_par->s[67].s_col = 5.5;
	data->s_par->s[67].texture = 3;
	data->s_par->s[68].s_row = 13.5;
	data->s_par->s[68].s_col = 5.5;
	data->s_par->s[68].texture = 3;
	load_c3_spt_tab_p1(data);
}

void	load_c3_spt_tab_p1(t_vault *data)
{
	data->s_par->s[69].s_row = 2.5;
	data->s_par->s[69].s_col = 1.5;
	data->s_par->s[69].texture = 11;
	data->s_par->s[70].s_row = 2.5;
	data->s_par->s[70].s_col = 2.5;
	data->s_par->s[70].texture = 11;
	data->s_par->s[71].s_row = 2.5;
	data->s_par->s[71].s_col = 3.5;
	data->s_par->s[71].texture = 11;
	data->s_par->s[72].s_row = 2.5;
	data->s_par->s[72].s_col = 4.5;
	data->s_par->s[72].texture = 11;
	data->s_par->s[73].s_row = 2.5;
	data->s_par->s[73].s_col = 5.5;
	data->s_par->s[73].texture = 11;
	load_c3_spt_tab_p2(data);
}

void	load_c3_spt_tab_p2(t_vault *data)
{
	data->s_par->s[74].s_row = 5.5;
	data->s_par->s[74].s_col = 1.5;
	data->s_par->s[74].texture = 11;
	data->s_par->s[75].s_row = 5.5;
	data->s_par->s[75].s_col = 2.5;
	data->s_par->s[75].texture = 11;
	data->s_par->s[76].s_row = 5.5;
	data->s_par->s[76].s_col = 3.5;
	data->s_par->s[76].texture = 11;
	data->s_par->s[77].s_row = 5.5;
	data->s_par->s[77].s_col = 4.5;
	data->s_par->s[77].texture = 11;
	data->s_par->s[78].s_row = 9.5;
	data->s_par->s[78].s_col = 1.5;
	data->s_par->s[78].texture = 11;
	data->s_par->s[79].s_row = 9.5;
	data->s_par->s[79].s_col = 2.5;
	data->s_par->s[79].texture = 11;
	data->s_par->s[80].s_row = 9.5;
	data->s_par->s[80].s_col = 3.5;
	data->s_par->s[80].texture = 11;
	data->s_par->s[81].s_row = 9.5;
	data->s_par->s[81].s_col = 4.5;
	data->s_par->s[81].texture = 11;
	load_c3_spt_tab_p3(data);
}

void	load_c3_spt_tab_p3(t_vault *data)
{
	data->s_par->s[82].s_row = 7.5;
	data->s_par->s[82].s_col = 1.5;
	data->s_par->s[82].texture = 11;
	data->s_par->s[83].s_row = 7.5;
	data->s_par->s[83].s_col = 2.5;
	data->s_par->s[83].texture = 11;
	data->s_par->s[84].s_row = 7.5;
	data->s_par->s[84].s_col = 3.5;
	data->s_par->s[84].texture = 11;
	data->s_par->s[85].s_row = 7.5;
	data->s_par->s[85].s_col = 4.5;
	data->s_par->s[85].texture = 11;
	data->s_par->s[86].s_row = 7.5;
	data->s_par->s[86].s_col = 5.5;
	data->s_par->s[86].texture = 11;
	load_c3_spt_tab_p4(data);
}

void	load_c3_spt_tab_p4(t_vault *data)
{
	data->s_par->s[87].s_row = 13.5;
	data->s_par->s[87].s_col = 1.5;
	data->s_par->s[87].texture = 11;
	data->s_par->s[88].s_row = 13.5;
	data->s_par->s[88].s_col = 2.5;
	data->s_par->s[88].texture = 11;
	data->s_par->s[89].s_row = 13.5;
	data->s_par->s[89].s_col = 3.5;
	data->s_par->s[89].texture = 11;
	data->s_par->s[90].s_row = 13.5;
	data->s_par->s[90].s_col = 4.5;
	data->s_par->s[90].texture = 11;
	load_c3_spt_tab_p5(data);
}
