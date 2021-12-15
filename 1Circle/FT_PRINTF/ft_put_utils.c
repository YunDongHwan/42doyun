/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:16:19 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 01:37:21 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putprecision(t_op *op, char **format, va_list ap)
{
	if (**format == '*')
	{
		op->precision = va_arg(ap, int);
		op->p_ast = 1;
		(*format)++;
	}
	while (**format >= '0' && **format <= '9')
	{
		op->precision = (op->precision * 10) + **format - 48;
		(*format)++;
	}
	if (op->precision == 0)
		op->dot = 1;
}

int		ft_putargpnt(char **temp, char **addr, t_arg *arg)
{
	if (!(*temp))
		return (-1);
	if (arg->p == 1)
		*addr = ft_strjoin("0x", *temp);
	else
		*addr = ft_strjoin("0X", *temp);
	if (!(*addr))
		return (-1);
	free(*temp);
	*temp = 0;
	return (0);
}

void	ft_putargd(t_op *op, int nb)
{
	if (op->sign == 0)
		ft_putblank(op);
	ft_putnbr(nb, op);
	if (op->sign == 1)
		ft_putblank(op);
}

void	ft_putargu(t_op *op, unsigned int nb)
{
	if (op->sign == 0)
		ft_putblank(op);
	ft_putnbr(nb, op);
	if (op->sign == 1)
		ft_putblank(op);
}

void	ft_putargx(t_op *op, char *hex)
{
	if (op->sign == 0)
		ft_putblank(op);
	ft_puthex(op, hex);
	if (op->sign == 1)
		ft_putblank(op);
}
