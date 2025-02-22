/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsunda <bsunda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:38 by bsunda            #+#    #+#             */
/*   Updated: 2024/02/02 15:05:16 by bsunda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_str(char *value)
{
	if (!value)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(value, 1);
	return (ft_strlen(value));
}
