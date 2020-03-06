/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <coclayto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 07:27:41 by coclayto          #+#    #+#             */
/*   Updated: 2020/03/03 08:06:06 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			float_math(long double num, t_struct *params, t_fstruct fstr)
{
	long double buf;
	int	i;
	
	i = 0;
	buf = num - fstr.d;
	while (i < params->precision)
	{
		buf *= 10;
		i++;
	}
	return (buf);
}

t_fstruct	float_from_fmt(t_struct *params, long double num, t_fstruct fstr)
{
	int i;

	i = 0;
	if (!params->precision)
		params->precision = 6;
	fstr.d = num;
	ft_putnbr((long)num);
	write(1, ".", 1);
	ft_putnbr((long)float_math(num, params, fstr));
	return (fstr);
}

t_fstruct		type_float(va_list args, t_struct *params)
{
	long double num;
	t_fstruct	fstr;

	fstr.before = "\0";
	if (params->length == LONG)
		num = (double)va_arg(args, double);
	if (params->length == LONGDOUBLE)  
		num = (long double)va_arg(args, long double);
	if (params->length == 0)
		num = (double)va_arg(args, double);
	float_from_fmt(params, num, fstr);
	return (fstr);
}