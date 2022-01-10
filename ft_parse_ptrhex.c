/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ptrhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:14:45 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 05:18:05 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "ft_printf.h"

char	*ft_ulitoa_base(unsigned long int n, char *base)
{
	char					*str;
	unsigned long long int	nbr;
	size_t					size;
	int						b_len;

	b_len = ft_strlen(base);
	nbr = (unsigned long long int)n;
	size = 1;
	while (n /= b_len)
		size++;
	str = (char *)malloc(size + 1);
	if (!str)
		return (0);
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = base[nbr % b_len];
		nbr /= b_len;
	}
	if (size == 0 && str[1] == '\0')
		str[0] = '0';
	return (str);
}

void	ft_parse_ptr(t_print *table)
{
	unsigned long int	ptr;
	char				*c_ptr;
	
	ptr = va_arg(table->args, unsigned long int);
	c_ptr = ft_ulitoa_base(ptr, "0123456789abcdef");
	ft_print_flags(c_ptr, ft_strlen(c_ptr), table);
	ft_clear_table(table);
}

void	ft_parse_hex_sm(t_print *table)
{
	unsigned long int	hex;
	char				*c_hex;
	
	hex = va_arg(table->args, unsigned int);
	c_hex = ft_ulitoa_base((unsigned long int)hex, "0123456789abcdef");
	ft_print_flags(c_hex, ft_strlen(c_hex), table);
	ft_clear_table(table);
}

void	ft_parse_hex_bg(t_print *table)
{
	unsigned long int	hex;
	char				*c_hex;
	
	hex = (unsigned long int)va_arg(table->args, unsigned int);
	c_hex = ft_ulitoa_base((unsigned long int)hex, "0123456789ABCDEF");
	ft_print_flags(c_hex, ft_strlen(c_hex), table);
	ft_clear_table(table);
}