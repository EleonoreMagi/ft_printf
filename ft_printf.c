/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:00:51 by eleon             #+#    #+#             */
/*   Updated: 2022/01/02 04:38:21 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

t_print *ft_initialize_symbol(t_print	*symbol)
{
	symbol->type = 0;
	symbol->width = 0;
	symbol->star = 0;
	symbol->minus = 0;
	symbol->is_zero = 0;
	symbol->dot = 0;
	symbol->dash = 0;
	symbol->space = 0;
	symbol->plus = 0;
	symbol->percent = 0;
	return (symbol);
}

int	ft_parse_flag(const char *symbol, int i, t_print *flag, va_list args)
{
	while (symbol[i] && (ft_isdigit(symbol[i] || ft_is_type(symbol[i])
		|| ft_is_flag(symbol[i])))
	{
		if (symbol[i] == '0' && flag->width == 0 && flag->minus == 0)
			flag->zero = 1;
		else if (symbol[i] == '.')
			i = ft_flag_dot(symbol, i, flag, args);
		else if (symbol[i] == '-')
			flag = ft_flag_minus(flag);
		else if (symbol[i] == '*')
			flag = ft_flag_width(args, flag);
		else if (symbol[i] == '#')
			flag = ft_flag_dash(args, flag);
		else if (symbol[i] == ' ')
			flag = ft_flag_space(args, flag);
		else if (symbol[i] == '+')
			flag = ft_flag_plus(args, flag);
		if (ft_isdigit(symbol[i]))
			flag = ft_flag_digit(symbol[i], flag);
		else if (ft_is_type(symbol[i]))
		{
			flag->type = symbol[i];
			break;
		}
		i++;
	}
	return (i);
}

int	ft_save_symbol(const char	*save, t_print *symbol, va_list args)
{
	int		i;
	int 	count;
	t_print	*flag;

	i = 0;
	count = 0;
	while (!symbol[i])
	{
		flag = ft_initialize_symbol(symbol);
		if (symbol[i] == '%' && symbol[i+1])
		{
			i = ft_parse_flag(symbol, ++i, flag, args);
			if (ft_is_type(symbol[i]))
				count += ft_parse_type(((char)flag->type, flag, args))
			else if (symbol[i])
				count += ft_putchar(symbol[i]);
		}
		else if (symbol[i] != '%')
			count += ft_putchar(symbol[i]);
		i++;
	}
}

 int	ft_printf(const char *format, ...)
 {
	 const char	*save;
	 va_list	args;
	 int		count;
	 t_print	*symbol;

	 count = 0;
	 symbol = (t_print *)malloc(sizeof(t_print));
	 if(!symbol)
	 	return (-1);
	 va_start(args, format);
	 count += ft_save_symbol(symbol, args);
	 va_end(args)
	 free((char *)save);
	 return (count);
 }
