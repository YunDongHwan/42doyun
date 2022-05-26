/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 02:34:56 by doyun             #+#    #+#             */
/*   Updated: 2020/11/05 03:48:49 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_find_next_prime(int nb)
{
	unsigned int i;
	unsigned int k;

	i = 3;
	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (nb);
	if (nb <= 5)
		return (5);
	if (nb <= 7)
		return (7);
	if (nb <= 11)
		return (11);
	if (nb % 2 == 0)
		nb++;
	k = nb;
	while (i < k)
	{
		if (k % i == 0)
		{
			k = k + 1;
			ft_find_next_prime(k);
		}
		i = i + 2;
	}
	return (k);
}
