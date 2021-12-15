/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:31:56 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 06:28:03 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_apply_char(va_list ap, t_op *op, t_arg *arg)
{
	char		c;

	c = va_arg(ap, int);
	op->precision = 0;
	ft_get_blanklen(op, 1, arg);
	if (op->sign == 0)
		ft_putblank(op);
	ft_putchar_fd(c, 1);
	op->total += 1;
	if (op->sign == 1)
		ft_putblank(op);
}

void			ft_casestr_precision(t_op *op, int len, char *str)
{
	if (op->precision > 0 && op->precision < len)
	{
		while (op->precision > 0)
		{
			ft_putchar_fd(*str, 1);
			str++;
			op->total++;
			op->precision--;
		}
	}
	else
	{
		ft_putstr_fd(str, 1);
		op->total += len;
	}
}

void			ft_apply_str(va_list ap, t_op *op, t_arg *arg)
{
	char		*str;
	int			len;

	str = "";
	if (op->dot == 0)
	{
		str = va_arg(ap, char *);
		if (str == 0)
			str = "(null)";
	}
	len = ft_strlen(str);
	ft_get_blanklen(op, len, arg);
	if (op->sign == 0)
		ft_putblank(op);
	ft_casestr_precision(op, len, str);
	if (op->sign == 1)
		ft_putblank(op);
}

int				ft_apply_pnt(va_list ap, t_op *op, t_arg *arg)
{
	size_t		p;
	char		*temp;
	char		*addr;
	int			len;
	int			chk;

	p = va_arg(ap, size_t);
	temp = ft_change_hex(p, arg, op);
	chk = ft_putargpnt(&temp, &addr, arg);
	if (chk == -1)
		return (-1);
	op->precision = 0;
	len = ft_strlen(addr);
	op->total += len;
	ft_get_blanklen(op, len, arg);
	if (op->sign == 0)
		ft_putblank(op);
	ft_putstr_fd(addr, 1);
	if (op->sign == 1)
		ft_putblank(op);
	free(addr);
	addr = 0;
	return (0);
}

int				ft_apply_option(va_list ap, t_op *op, t_arg *arg)
{
	int			chk;

	chk = 0;
	if (arg->c == 1)
		ft_apply_char(ap, op, arg);
	else if (arg->s == 1)
		ft_apply_str(ap, op, arg);
	else if (arg->p == 1)
		chk = ft_apply_pnt(ap, op, arg);
	else if (arg->d == 1 || arg->i == 1)
		ft_apply_di(ap, op, arg);
	else if (arg->u == 1)
		ft_apply_u(ap, op, arg);
	else if (arg->x == 1 || arg->bigx == 1)
		chk = ft_apply_x(ap, op, arg);
	else if (arg->per == 1)
		ft_apply_per(op, arg);
	else
		return (-1);
	return (chk);
}
