/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 01:55:03 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 16:54:12 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
 #include "ft_printf.h"

void	ft_putchar_count(char c, t_print *table)
{
	write(1, &c, 1);
	table->length++;

}

void	ft_putstr_count(char *str, int len, t_print *table)
{
	int	i;

	if (str != NULL)
	{
		i = 0;
		while (str[i] && i < len)
			ft_putchar_count(str[i++], table);
	}
}

void	ft_print_width(t_print *table, int len)
{
	if (table->sign == '-' || (table->plus == 1 && table->sign == '+') ||
		(table->space == 1 && table->plus == 0 && table->sign == '+'))
		table->width--;
	if (table->prc <= len)
		table->prc = len;
	if (table->zero == 1 && (table->minus == 1 || table->dot == 1))
		table->zero = 0;
	while (table->width > table->prc)
	{
		if (table->zero)
			ft_putchar_count('0', table);
		else
			ft_putchar_count(' ', table);
		table->width--;
	}
}

void	ft_print_extra(t_print *table, int len)
{
	int		j;

	if ((table->type == 'x' && table->alt == 1) || table->type == 'p')
		ft_putstr_count("0x", 2, table);
	if (table->type == 'X' && table->alt == 1)
		ft_putstr_count("0X", 2, table);
	if (table->minus == 0 && table->zero == 1)
		ft_print_width(table, len);
	if (table->dot == 1)
	{
		j = table->prc;
		while (j-- > len)
			ft_putchar_count('0', table);
	}
}

void	ft_print_flags(char *str, int len, t_print	*table)
{
	if (((table->type == 'x' || table->type == 'X') && table->alt == 1) ||
			table->type == 'p')
		table->width -= 2;
	if (table->dot == 1)
		table->zero = 0;
	if (table->minus == 0)
		ft_print_width(table, len);
	if (table->sign == '-' || (table->plus == 1 && table->sign == '+'))
		ft_putchar_count(table->sign, table);
	if (table->space == 1 && table->plus == 0 && table->sign == '+')
		ft_putchar_count(' ', table);
	ft_print_extra(table, len);
	if (!(table->dot == 1 && table->prc == 0))
		ft_putstr_count(str, len, table);
	if (table->minus == 1)
		ft_print_width(table, len);
}
