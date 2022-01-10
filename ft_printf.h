/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:01:37 by eleon             #+#    #+#             */
/*   Updated: 2022/01/10 05:31:21 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf
{
	va_list	args;
	char	type;
	int		length;
	int		zero;
	int 	width;
	int		prc;
	int		minus;
	int		is_zero;
	char	sign;
	int		dot;
	int		alt;
	int 	space;
	int		plus;
	
}				t_printf;

#endif