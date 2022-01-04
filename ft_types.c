/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 04:19:06 by eleon             #+#    #+#             */
/*   Updated: 2022/01/02 04:38:09 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_type(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p')
		|| (c == 'd') || (c == 'i') || (c == 'u')
		|| (c == 'x') || (c == 'X') || (c == 'c%'))
}

int	ft_parse_type(int c, t_print *flag, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_parse_char(va_arg(args, int), flag);
	else if (c == 's')
		count = ft_parse_string(va_arg(args, char *), flag);
	else if (c == 'p')
		count = ft_parse_ptr(va_arg(args, unsigned long long), flag);
	else if (c == 'd' || c == 'i')
		count = ft_parse_int(va_arg(args, int), flag);
	else if (c == 'u')
		count = ft_parse_unit((unsigned int)va_arg(args, unsigned int), flag);
	else if (c == 'x')
		count = ft_parse_hex(va_arg(args, unsigned int), 1, flag);
	else if (c == 'X')
		count = ft_parse_hex(va_arg(args, unsigned int), 0, flag);
	else if (c == '%')
		count = ft_parse_percent(flag);
	return (count);
}