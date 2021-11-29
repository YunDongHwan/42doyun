/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 06:16:19 by doyun             #+#    #+#             */
/*   Updated: 2021/03/17 01:37:21 by doyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"
# include <stdio.h>

typedef struct	s_op
{
	int			sign;
	int			miner;
	int			zero;
	int			zerolen;
	ssize_t		width;
	ssize_t		precision;
	int			dot;
	int			nodot;
	int			blank;
	int			total;
	int			p_ast;
	int			chk;
	int			big[2];
}				t_op;

typedef struct	s_arg
{
	int			c;
	int			s;
	int			p;
	int			d;
	int			i;
	int			u;
	int			x;
	int			bigx;
	int			per;
}				t_arg;

int				ft_printf(const char *format, ...);
int				ft_apply_option(va_list ap, t_op *op, t_arg *arg);

int				ft_checkvalid(va_list ap, char **format, t_op *op, t_arg *arg);

int				ft_get_max(int num1, int num2);
char			*ft_change_hex(size_t i, t_arg *arg, t_op *op);
void			ft_putnbr(ssize_t nb, t_op *op);
void			ft_puthex(t_op *op, char *hex);

void			ft_get_blanklen(t_op *op, int arglen, t_arg *arg);
int				ft_get_nbrlen(ssize_t nb, t_op *op);

void			ft_case_cpper(t_op *op, int arglen);
void			ft_case_str(t_op *op, int arglen);
void			ft_case_arglenbig(t_op *op, int arglen);
void			ft_case_precisionbig(t_op *op, int arglen);

void			ft_putblank(t_op *op);
void			ft_putzero(t_op *op);
void			ft_reset_op(t_op *op, t_arg *arg);

void			ft_putprecision(t_op *op, char **format, va_list ap);
void			ft_putargd(t_op *op, int nb);
void			ft_putargu(t_op *op, unsigned int nb);
void			ft_putargx(t_op *op, char *hex);
int				ft_putargpnt(char **temp, char **addr, t_arg *arg);

void			ft_apply_per(t_op *op, t_arg *arg);
void			ft_apply_u(va_list ap, t_op *op, t_arg *arg);
int				ft_apply_x(va_list ap, t_op *op, t_arg *arg);
void			ft_apply_di(va_list ap, t_op *op, t_arg *arg);

#endif
