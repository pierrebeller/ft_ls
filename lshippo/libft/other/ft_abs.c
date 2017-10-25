#include "../includes/libft.h"

int		ft_abs(int nbr)
{
	if (!nbr)
		return (0);
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}