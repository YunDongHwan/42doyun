/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:46:24 by doyun             #+#    #+#             */
/*   Updated: 2020/11/04 19:56:13 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_iterative_power(int nb, int power);

int		main(void)
{
	int nb;
	int power;

	nb = -2;
	power = 3;
	
	printf("%d", ft_iterative_power(nb, power));
	return (0);
}
