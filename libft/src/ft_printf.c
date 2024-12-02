/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 11:30:41 by jopereir          #+#    #+#             */
/*   Updated: 2024/11/01 10:11:40 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	Shows the fomat specified and return the amout of characters showed
*/
int	get_format(char c, va_list args)
{
	int				length;

	length = 0;
	if (c == 'd' || c == 'i')
		length = ft_get_int(va_arg(args, int));
	else if (c == 'u')
		length = ft_get_unsigned(va_arg(args, unsigned int));
	else if (c == '%')
		length = ft_get_percentage();
	else if (c == 'c')
		length = ft_get_char(va_arg(args, int));
	else if (c == 's')
		length = ft_get_string(va_arg(args, char *));
	else if (c == 'x')
		length = ft_itoa_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		length = ft_itoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		length = ft_get_pointer((unsigned long)va_arg(args, void *));
	return (length);
}

/*
	it shows the text char by char when it faces a '%' it verifies
	the format and shows the string of the var
	
	return - the number of char displayed at the terminal
*/
int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		num_char_displayed;

	va_start(args, str);
	num_char_displayed = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			num_char_displayed += get_format(str[i], args);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			num_char_displayed++;
		}
		i++;
	}
	va_end(args);
	return (num_char_displayed);
}

/*
#include "./include/ft_printf.h"
#include <stdio.h>

void	ft_test(void)
{
	int		mine;
	int		original;
	char	*s;
	char	*str;

	s = "Hello world";
	str = " Hi ";
	printf("\nOriginal\n");
	original = printf("Decimal: %d teste %d\n", -10, 50);
	printf("int: %i\n", ft_num_count(25));
	printf("unsigned: %u\n", -5);
	printf("Percentage: 5%% .05%%\n");
	printf("char: %c\n", 'c');
	printf("String: %s\n", "teste");
	printf("Hex_low: %x\n", 1015);
	printf("Hex_up %X\n", 1015);
	printf("Hex negativo: %x\n", -10);
	printf("Ponteiro: %p\n", (void *)s);
	printf("Ponteiro: %p\n", (void *)str);
	printf("return: %d\n\n", original);
	
	ft_printf("Mine\n");
	mine = ft_printf("Decimal: %d teste %d\n", -10, 50);
	ft_printf("int: %i\n", ft_num_count(25));
	ft_printf("unsigned: %u\n", -5);
	ft_printf("Percentage: 5%% .05%%\n");
	ft_printf("char: %c\n", 'c');
	ft_printf("String: %s\n", "teste");
	ft_printf("Hex_low: %x\n", 1015);
	ft_printf("Hex_up %X\n", 1015);
	ft_printf("Hex negativo: %x\n", -10);
	ft_printf("Ponteiro: %p\n", (void *)s);
	ft_printf("Ponteiro: %p\n", (void *)str);
	ft_printf("return: %d\n\n", mine);
}

int	main(void)
{
	ft_test();
	return (0);
}
*/
