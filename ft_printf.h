/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 20:15:37 by releanor          #+#    #+#             */
/*   Updated: 2020/02/19 17:16:39 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/includes/libft.h"

typedef struct	s_struct
{
	char		*fmt;
	int			nprinted;
	int			i;
	int			len;
	int			minus;
	int			plus;
	int			space;
	int			zero;
	int			hash;
	int			width;
	int			precisiontf;
	int			precision;
	int			length;
}				t_struct;

void	conversions(char c, va_list params, t_struct *new_struct);
void	type_char(t_struct *new_struct, va_list params);

#endif
