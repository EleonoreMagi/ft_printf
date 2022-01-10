/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:41:43 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 06:27:36 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

void	ft_parse_int(t_print *table)
{
	int		num;
	char	*c_num;

	num  = va_arg(table->args, int);
	if (num >= 0)
		table->sign = '+';
	else if (num < 0)
	{
		table->sign = '-';
		num *= -1;
	}
	c_num = ft_ulitoa_base((unsigned long int)num, "0123456789");
	ft_print_flags(c_num, ft_strlen(c_num), table);
	ft_clear_table(table);
}

void	ft_parse_unsigned_int(t_print *table)
{
	unsigned int	num;
	char			*c_num;

	num  = va_arg(table->args, unsigned int);
	c_num = ft_ulitoa_base((unsigned long int)num, "0123456789");
	ft_print_flags(c_num, ft_strlen(c_num), table);
	ft_clear_table(table);
}