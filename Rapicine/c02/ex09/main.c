/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:10:22 by doyun             #+#    #+#             */
/*   Updated: 2020/10/28 17:57:44 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char		*ft_strcapitalize(char *str);

int			main(void)
{
	char b[100] = "salut, commDDnt tu vas ? 42mots quD4anDte-deux; cinquante+et+un";
	char *c;

	c = ft_strcapitalize(b);
	while(*c)
	{
		write(1, c, 1);
		c++;
	}
	return (0);
}
