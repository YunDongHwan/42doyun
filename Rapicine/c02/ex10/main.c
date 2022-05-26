/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 23:55:59 by doyun             #+#    #+#             */
/*   Updated: 2020/10/28 18:12:28 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size);

int					main(void)
{
	char a[50] = "kkdsjejsehfk247";
	char b[20] = "BXVBCNCVXC";
	unsigned int k;
	int i;

	i = 0;
	k = 15;
	k = ft_strlcpy(a,b,k);
	while(a[i])
	{
		write(1, &a[i], 1);
		i++;
	}	
	return (0);
}
