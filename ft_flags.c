/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 03:07:18 by eleon             #+#    #+#             */
/*   Updated: 2022/01/02 04:38:25 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_flag(int c)
{
	return ((c == '-') || (c == '0') || (c == '.')
		|| (c == '*') || (c == '#') || (c == ' ')
		|| (c == '+'))
}

t_print	*ft_flag_minus(t_print	*flag)
{
	flag->minus = 1;
	flag->zero = 0;
	return (flag);
}

t_print	*ft_flag_with(va_list args, t_print	*flag)
{
	flag->star = 1;
	flag->width = va_arg(args, int);
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	return (flag);
}

int	ft_flag_dot(const char *symbol, int start,
		t_print *flag, va_list args)
{
	int	i;

	i = start;
	i++;
	if (symbol[i] == '*')
	{
		flag->dot = va_args(args, int);
		i++;
	}
	else
	{
		flag->dot = 0;
		while (ft_isdigit(symbol[i]))
			flag->dot = (flag->dot * 10) + (symbol[i++] - '0');
	}
	return (i);
}