/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 01:07:58 by doyun             #+#    #+#             */
/*   Updated: 2020/10/28 18:31:02 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_changehex(unsigned char ten, unsigned char one, unsigned char k)
{
	write(1, "\\", 1);
	ten = k / 16;
	if (ten >= 10)
	{
		ten += 87;
		write(1, &ten, 1);
	}
	else
	{
		ten += 48;
		write(1, &ten, 1);
	}
	one = k % 16;
	if (one >= 10)
	{
		one += 87;
		write(1, &one, 1);
	}
	else
	{
		one += 48;
		write(1, &one, 1);
	}
}

void		ft_putstr_non_printable(char *str)
{
	unsigned char	ten;
	unsigned char	one;
	int				i;
	unsigned char	k;

	i = 0;
	ten = 0;
	one = 0;
	while (str[i])
	{
		k = str[i];
		if (k >= 32 && k <= 126)
		{
			write(1, &k, 1);
		}
		else
		{
			ft_changehex(ten, one, k);
		}
		i++;
	}
}
