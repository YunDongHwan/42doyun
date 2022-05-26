/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 21:46:24 by doyun             #+#    #+#             */
/*   Updated: 2020/11/04 23:49:24 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int temp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	i = 0;
	temp = nb;
	while (i < power - 1)
	{
		nb = nb * temp;
		i++;
	}
	return (nb);
}
