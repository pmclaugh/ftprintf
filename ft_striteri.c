/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:20:41 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/01 02:51:21 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_rc(char *s, void (*f)(unsigned int, char *), unsigned int i)
{
	if (!s)
		return ;
	if (!*s)
		return ;
	f(i, s);
	ft_rc(s + 1, f, i + 1);
}

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s)
		return ;
	if (!*s)
		return ;
	if (!f)
		return ;
	i = 0;
	ft_rc(s, f, i);
}
