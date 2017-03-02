/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmclaugh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 22:17:39 by pmclaugh          #+#    #+#             */
/*   Updated: 2016/12/14 15:55:12 by pmclaugh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	list_push(t_list **head, t_list *add)
{
	if (*head == NULL)
		ft_lstadd(head, add);
	else
		ft_lstat(*head, ft_lstlen(*head) - 1)->next = add;
}

char	*list_flush(t_list **head)
{
	char	*output;
	int		offset;
	t_list	*temp;

	output = ft_memalloc(BUFF_SIZE * ft_lstlen(*head));
	if (!output)
		return (NULL);
	offset = 0;
	while (*head)
	{
		ft_memcpy(output + offset, (*head)->content, (*head)->content_size);
		offset += (*head)->content_size;
		temp = *head;
		*head = (*head)->next;
		free(temp->content);
		free(temp);
	}
	*head = NULL;
	output[offset] = 0;
	return (output);
}

t_rem	*get_rem(t_rem *remain, const int fd, char *buff, t_list **chain)
{
	ft_bzero(buff, BUFF_SIZE);
	*chain = NULL;
	while (remain->fd != fd)
	{
		if (remain->next)
			remain = remain->next;
		else
		{
			remain->next = (t_rem *)malloc(sizeof(t_rem));
			remain = remain->next;
			remain->fd = fd;
			remain->len = 0;
			ft_bzero(remain->rem, BUFF_SIZE);
			remain->next = NULL;
		}
	}
	return (remain);
}

void	pull_rem(char *buff, int *ret, t_rem *remain)
{
	ft_memcpy(buff, remain->rem, remain->len);
	*ret = remain->len;
	ft_bzero(remain->rem, BUFF_SIZE);
	remain->len = 0;
}

int		get_next_line(const int fd, char **line)
{
	char			b[BUFF_SIZE];
	int				ret;
	t_list			*b_chain;
	static t_rem	remainders;
	t_rem			*rem;

	rem = get_rem(&remainders, fd, b, &b_chain);
	if (rem->len)
		pull_rem(b, &ret, rem);
	else if ((ret = read(fd, b, BUFF_SIZE)) < 1)
		return (ret == 0 ? 0 : -1);
	while (ret > 0 && !ft_memchr(b, '\n', ret))
	{
		list_push(&b_chain, ft_lstnew(b, ret));
		ft_bzero(b, BUFF_SIZE);
		ret = read(fd, b, BUFF_SIZE);
	}
	if (ret > 0)
	{
		list_push(&b_chain, ft_lstnew(b, (char*)ft_memchr(b, '\n', ret) - b));
		rem->len = ret - ((char*)ft_memchr(b, '\n', ret) - b) - 1;
		ft_memcpy(rem->rem, (char*)ft_memchr(b, '\n', ret) + 1, rem->len);
	}
	*line = list_flush(&b_chain);
	return (1);
}
