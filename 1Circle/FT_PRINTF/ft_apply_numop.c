/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_numop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:16:19 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 01:37:21 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_apply_per(t_op *op, t_arg *arg)
{
	ft_get_blanklen(op, 1, arg);
	if (op->sign == 0)
		ft_putblank(op);
	if (op->zero == 1 && op->sign == 0)
		ft_putzero(op);
	ft_putchar_fd('%', 1);
	op->total += 1;
	if (op->sign == 1)
		ft_putblank(op);
}

void				ft_apply_u(va_list ap, t_op *op, t_arg *arg)
{
	unsigned int	nb;
	int				len;

	if (arg->u == 1)
	{
		nb = va_arg(ap, unsigned int);
		if ((op->nodot == 0 && op->precision == 0 && nb == 0) ||
						(op->dot == 1 && nb == 0))
		{
			op->blank = op->width;
			op->total += op->blank;
			ft_putblank(op);
		}
		else
		{
			len = ft_get_nbrlen(nb, op);
			ft_get_blanklen(op, len, arg);
			ft_putargu(op, nb);
		}
	}
}

int					ft_apply_x(va_list ap, t_op *op, t_arg *arg)
{
	size_t			nb;
	int				len;
	char			*hex;

	if (arg->x == 1 || arg->bigx == 1)
	{
		nb = va_arg(ap, unsigned int);
		hex = ft_change_hex(nb, arg, op);
		if (!hex)
			return (-1);
		len = ft_strlen(hex);
		ft_get_blanklen(op, len, arg);
		ft_putargx(op, hex);
		free(hex);
		hex = 0;
	}
	return (0);
}

void				ft_apply_di(va_list ap, t_op *op, t_arg *arg)
{
	int				nb;
	int				len;

	if (arg->d == 1 || arg->i == 1)
	{
		nb = va_arg(ap, int);
		if ((op->nodot == 0 && op->precision == 0 && nb == 0) ||
						(op->dot == 1 && nb == 0))
		{
			op->blank = op->width;
			op->total += op->blank;
			ft_putblank(op);
		}
		else
		{
			len = ft_get_nbrlen(nb, op);
			ft_get_blanklen(op, len, arg);
			ft_putargd(op, nb);
		}
	}
}
