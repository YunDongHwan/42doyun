/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 18:36:19 by doyun             #+#    #+#             */
/*   Updated: 2020/10/22 00:53:17 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void		ft_div_mod(int a, int b, int *div, int *mod);

int			main(void)
{
	int a;
	int b;
	int div;
	int mod;

	a = 10;
	b = 2;
	div = 0;
	mod = 0;
	ft_div_mod(a, b, &div, &mod);
	printf("%d, %d, %d, %d", a, b, div, mod);
}
