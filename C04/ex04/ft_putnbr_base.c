/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpoinsu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 14:07:25 by dpoinsu           #+#    #+#             */
/*   Updated: 2020/07/16 15:24:20 by dpoinsu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	is_neg(unsigned int *nb, int *nbr)
{
	if (*nbr < 0)
	{
		ft_putchar('-');
		*nbr *= -1;
		*nb *= -1;
	}
	if (*nbr == 0)
		ft_putchar('0');
}

void	ft_putnbr_base(int nbr, char *base)
{
	int				i;
	int				len;
	int				nb_final[50];
	unsigned int	nb;

	i = -1;
	len = 0;
	nb = nbr;
	if (check_base(base))
	{
		is_neg(&nb, &nbr);
		while (base[len])
			len++;
		while (nb)
		{
			nb_final[i + 1] = nb % len;
			nb /= len;
			i++;
		}
		while (i >= 0)
		{
			ft_putchar(base[nb_final[i]]);
			i--;
		}
	}
}
