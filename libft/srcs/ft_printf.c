/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebengtss <ebengtss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 13:52:07 by ebengtss          #+#    #+#             */
/*   Updated: 2024/06/24 14:00:54 by ebengtss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	whichprint(const char *c, va_list printfargs, int *counter)
{
	if (*c == 'c')
		ft_putchar_len(va_arg(printfargs, int), counter);
	else if (*c == 's')
		ft_putstr_len(va_arg(printfargs, char *), counter);
	else if (*c == 'p')
		ft_getaddress(va_arg(printfargs, void *), counter);
	else if (*c == 'd' || *c == 'i')
		ft_putnbr_len(va_arg(printfargs, int), counter);
	else if (*c == 'u')
		ft_putuns_len(va_arg(printfargs, unsigned int), counter);
	else if (*c == 'x')
		ft_puthex_len(va_arg(printfargs, unsigned long long int), 0, counter);
	else if (*c == 'X')
		ft_puthex_len(va_arg(printfargs, unsigned long long int), 1, counter);
	else if (*c == '%')
		ft_putchar_len('%', counter);
	else if (*c == '\0' || *(c + 1) == '\0')
	{
		*counter = -1;
		return ;
	}
}

int	ft_printf(const char *args, ...)
{
	va_list	printfargs;
	size_t	i;
	int		counter;

	if (!args)
		return (-1);
	va_start (printfargs, args);
	i = 0;
	counter = 0;
	while (args[i])
	{
		if (counter == -1)
			break ;
		if (args[i] == '%')
			whichprint(&(args[++i]), printfargs, &counter);
		else
			ft_putchar_len(args[i], &counter);
		i++;
	}
	va_end (printfargs);
	return (counter);
}
