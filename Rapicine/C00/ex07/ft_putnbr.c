/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:56:33 by doyun             #+#    #+#             */
/*   Updated: 2020/10/22 05:46:29 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_cut(int count, int cut, int len, int count2)
{
	int num;

	num = 0;
	while (count > 0)
	{
		cut = 1;
		while (count - 1 > 0)
		{
			cut *= 10;
			count--;
		}
		num = len / cut;
		len -= num * cut;
		num += '0';
		write(1, &num, 1);
		count = count2 - 1;
		count2 = count;
	}
}

int		ft_exeption(int nb)
{
	char miner;

	miner = '-';
	if (nb == -2147483648)
	{
		write(1, &miner, 1);
		write(1, "2147483648", 11);
	}
	else
	{
		nb *= -1;
		write(1, &miner, 1);
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int len;
	int cut;
	int count;
	int num;

	cut = 10;
	count = 0;
	len = nb;
	if (nb < 0)
		len = ft_exeption(nb);
	num = len;
	while (num > 0)
	{
		num /= cut;
		count++;
	}
	ft_cut(count, cut, len, count);
}
