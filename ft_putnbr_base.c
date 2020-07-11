#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int		check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	while (base[i])
	{
		z = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[z])
		{
			if (base[i] == base[z])
				return (0);
			z++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
    int i;
	int	len;
	int	nb_final[20];

	i = 0;
	len = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			nbr = -nbr;
			ft_putchar('-');
		}
		while (base[len])
			len++;
		while (nbr)
		{
			nb_final[i] = nbr % len;
			nbr = nbr / len;
			i++;
		}
		while (--i >= 0)
			ft_putchar(base[nb_final[i]]);
	}
}