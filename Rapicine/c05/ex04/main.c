/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 22:29:47 by doyun             #+#    #+#             */
/*   Updated: 2020/11/03 03:11:10 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_fibonacci(int index);

int		main(void)
{
	int index;
	int i;

	i = 0;
	index = 5;
	while (i < index)
	{
		printf("%d ", ft_fibonacci(i));
		i++;
	}
	return (0);
}
