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

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr;
	char	betterc;

	i = 0;
	ptr = (char *)s;
	betterc = (char)c;
	while (ptr[i] != '\0')
	{
		if (ptr[i] == betterc)
			return (ptr += i);
		i++;
	}
	if (ptr[i] == betterc)
		return (ptr += i);
	return (0);
}
