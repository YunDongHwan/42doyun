/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 22:55:58 by doyun             #+#    #+#             */
/*   Updated: 2020/11/01 04:41:11 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>


char		*ft_strstr(char *str, char *to_find);

int			main(void)
{
	char str[50] = "my name he";
	char tp_find[50] = "name";
	
	printf("%s",ft_strstr(str, tp_find));
	return (0);
}
