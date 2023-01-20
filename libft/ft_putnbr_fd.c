/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jmeruma <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:05:51 by jmeruma       #+#    #+#                 */
/*   Updated: 2022/10/03 15:05:53 by jmeruma       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	checks(int fd, int n);

void	ft_putnbr_fd(int n, int fd)
{
	char	ptr[100];
	int		i;

	i = 0;
	if (checks(fd, n) == 1)
		return ;
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	while (n > 0)
	{
		ptr[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &ptr[i], 1);
		i--;
	}
}

static int	checks(int fd, int n)

{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (1);
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	return (0);
}
