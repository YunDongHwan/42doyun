/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 05:46:34 by doyun             #+#    #+#             */
/*   Updated: 2020/11/04 10:40:09 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_change(long long nbr, int basenum, char *base)
{
	int		num;
	char	tempbase[basenum];
	int		i;

	i = 0;
	while (base[i] != '\0')
	{
		tempbase[i] = base[i];
		i++;
	}
	num = 0;
	if (nbr > 0)
	{
		num = nbr % basenum;
		nbr = nbr / basenum;
		ft_change(nbr, basenum, base);
		write(1, &tempbase[num], 1);
	}
}

int		ft_checksame(char *base, int basenum)
{
	int i;
	int j;

	i = 0;
	if (*base == '\0' || basenum <= 1)
		return (0);
	while (base[i] != 0)
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		i++;
	}
	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			basenum;
	int			i;
	long long	temp;

	temp = nbr;
	basenum = 0;
	i = 0;
	while (base[i])
	{
		basenum++;
		i++;
	}
	i = 0;
	if (!(ft_checksame(base, basenum)))
		return ;
	if (temp == 0)
		write(1, &base[i], 1);
	if (temp < 0)
	{
		write(1, "-", 1);
		temp *= -1;
	}
	ft_change(temp, basenum, base);
}
