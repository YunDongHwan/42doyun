/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 01:24:35 by doyun             #+#    #+#             */
/*   Updated: 2020/11/05 03:16:02 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef	FT_POINT.H
#define	FT_POINT.H

void set_point(t_point *point);
int main(void);

typedef struct s_point
{
	int x;
	int y;
}				t_point

#endif
