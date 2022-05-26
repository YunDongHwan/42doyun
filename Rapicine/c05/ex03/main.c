/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:05:08 by doyun             #+#    #+#             */
/*   Updated: 2020/11/03 05:24:40 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_power(int nb, int power);

int		main(void)
{
	int nb;
	int power;
	
	nb = 10;
	power = -3;
	printf("%d",ft_recursive_power(nb, power));
	return (0);
}
