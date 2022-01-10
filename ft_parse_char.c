/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 02:35:01 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 05:30:26 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_align_char(t_print *table, int minus)
{
	while (table->width - minus > 0)
	{
		if (table->zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		table->length++;
		table->width--;
	}
}

void	ft_parse_char(t_print *table)
{
	char	c;

	c = va_arg(table->args, int);
	if (!tab->minus)
		ft_align_char(table, 1);
	ft_putchar_count(c, table);
	if (tab->minus)
		ft_align_char(table, 1);
	ft_clear_table(table);
}

void	ft_parse_string(t_print *table)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	if ((table->dot && table->prc > ft_strlen(str)) || !table->dot)
		table->prc = ft_strlen(str);
	if (!tab->minus)
	{
		ft_align_char(table, table->prc);
	}
	ft_putstr_count(str, table->prc, table);
	if (tab->minus)
	{
		ft_align_char(table, table->prc);
	}
	ft_clear_table(table);
}

void	ft_parse_percent(t_print *table)
{
	if (!tab->minus)
		ft_align_char(table, 1);
	ft_putchar_count('%', table);
	if (tab->minus)
		ft_align_char(table, 1);
	ft_clear_table(table);
}