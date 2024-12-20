/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juaho <juaho@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 15:38:11 by juaho             #+#    #+#             */
/*   Updated: 2024/11/14 12:14:02 by juaho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	atoi2_inner(const char *a, int *i, int neg)
{
	int num;
	int	overflow;

	num = 0;
	overflow = 0;
	while (*a >= '0' && *a <= '9')
	{
		num *= 10;
		if (neg)
		{
			num -= *a - '0';
			if (!overflow && num > 0)
				overflow = 1;
		}
		else
		{
			num += *a - '0';
			if (!overflow && num < 0)
				overflow = 1;
		}
		a++;
	}
	*i = num;
	return (overflow);
}

int	ft_atoi2(const char *a, int *i)
{
	int		neg;

	neg = 0;
	while ((*a >= 9 && *a <= 13) || *a == ' ')
		a++;
	if (*a == '-' || *a == '+')
	{
		if (*a == '-')
			neg = 1;
		a++;
	}
	return (atoi2_inner(a, i, neg));
}
