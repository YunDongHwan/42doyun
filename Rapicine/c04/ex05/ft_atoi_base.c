/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 04:05:41 by doyun             #+#    #+#             */
/*   Updated: 2020/11/02 18:06:18 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

int		ft_checksame(char *base, int basenum)
{
	int i;
	int j;

	i = 0;
	if (*base != '\0' || basenum == 1)
		return (0);
	while (*base != 0)
	{
		if (*base == 43 || *base == 45)
			return (0);
		base++;
	}
	while (base[i + 2] != '\0')
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

int		ft_atoi(char *str, char *base)
{
	int i;
	int miner;
	int num;
	int count;
	int j;

	i = 0;
	miner = 1;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
	{
		i++;
	}
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			miner *= -1;
		i++;
	}
	count = 0;
	while (str != '\0' && base != '\0')
	{	
		j = 0;
		num = 0;	
		while (base[j])
		{
			if (str[i] == base[j])
			{
				i++;
				j = -1;
			}
			j++;
		}			
	}	
	num = num *+ (j * basenum);
		return (num);
}
			

	

