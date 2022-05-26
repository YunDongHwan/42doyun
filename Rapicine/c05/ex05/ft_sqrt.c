/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 01:32:51 by doyun             #+#    #+#             */
/*   Updated: 2020/11/05 00:28:24 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	unsigned int i;
	unsigned int k;

	k = nb;
	i = 1;
	while (i * i <= k)
	{
		if (i * i == k)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
