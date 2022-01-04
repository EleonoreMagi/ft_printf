/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleon <eleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:01:37 by eleon             #+#    #+#             */
/*   Updated: 2022/01/02 04:38:17 by eleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_printf
{
	va_list	args;
	int		type;
	int 	width;
	int		minus;
	int		is_zero;
	int		dot;
	int		dash;
	int 	space;
	int		plus;
	int		percent;
	
}				t_printf;

#endif