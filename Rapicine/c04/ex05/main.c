/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:33:13 by doyun             #+#    #+#             */
/*   Updated: 2020/11/02 13:06:59 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_atoi_base(char *str, char *base);

int		main(void)
{
	char *str = " ---+--+42ab567";
	char *base = "0123456789ABCDEF";

	ft_atoi_base(str, base);
	return (0);
}

