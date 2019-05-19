/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 18:17:45 by hchau             #+#    #+#             */
/*   Updated: 2019/05/17 13:17:54 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_list	*gnl_struct(char *put, int num, t_list **put_in)
{
	t_gnl		strct;

	if (put)
	{
		strct.content = (char *)malloc(sizeof(char) * (ft_strlen(put) + 1));
		strct.content = ft_memcpy(strct.content, put, ft_strlen(put));
		strct.num = num;
		*put_in = ft_lstnew(&strct, sizeof(t_gnl));
	}
	return (*put_in);
}

int		join_in(char **line, t_list *put_in, int fd)
{
	t_gnl		*strct;
	t_list		*put_out;

	ft_putchar('o');
	put_out = put_in;
	if (put_out->content == NULL)
		return (0);
	while (put_out)
	{
		strct = (put_out->content);
		if (strct->num == fd)
		{
			*line = ft_strjoin(*line, ft_strcdup(strct->content, '\n'));
			if ((ft_strchr(strct->content, '\n')))
			{
				strct->content = ft_strdup((ft_strchr(strct->content, '\n') + 1));
				return (1);
			}
		}
		put_out = (put_out->next);
	}
	return (0);
}

int		read_this(int fd, char **line, t_list **reading)
{
	t_list	*put_in;
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*to_free;

	put_in = *reading;
	if (put_in != NULL)
	{	
		if (join_in(line, put_in, fd))
			return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		*line = ft_strjoin(*line, ft_strcdup(buf, '\n'));
		if ((ft_strchr(buf, '\n')))
		{
			to_free = ft_strdup((ft_strchr(buf, '\n') + 1));
			put_in = gnl_struct(to_free, fd, &put_in);
			if (*reading == NULL)
				*reading = put_in;
			return (1);
		}
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	t_gnl				*pok;
	static t_list		*osn;
	char				buf[BUFF_SIZE + 1];
	int					ret;

	*line = ft_strnew(0);
	/*while (priv)
	{
		ft_putchar ('o');
		pok = priv->content;
		if (pok->num == fd)
		{
			*line = ft_strcdup(pok->content, '\n');
			if (ft_strchr(pok->content, '\n'))
			{
				pok->content = ft_strdup((ft_strchr(pok->content, '\n') + 1));
				return (1);
			}
			free(pok->content);
		}
		priv = priv->next;
	}*/
	//if (osn == NULL)
	{
		if (read_this(fd, line, &osn) == 1)
		{
			//ft_putendl(*line);
			if (osn)
			{
				//ft_putchar('p');
				//pok = osn->content;
				//ft_putendl(pok->content);
			}
			return (1);
		}
	}
	return (0);
}

int		main()
{
	t_list	*priv;
	t_gnl	*pok;
	int		fd1;
	int		fd2;
	char	*line;
	char	buf[BUFF_SIZE + 1];
	int		ret;

	fd1 = open("/Users/hchau/Desktop/test2", O_RDONLY);
	fd2 = open("/Users/hchau/Desktop/test3", O_RDONLY);
	while (get_next_line(fd1, &line) == 1)
	{
		ft_putendl(line);
		//pok = priv->content;
		//ft_putendl(pok->content);
	}
	if (get_next_line(fd2, &line) == 1)
	{
		ft_putendl(line);
		//pok = priv->content;
		//ft_putendl(pok->content);
	}
	//ft_struct(buf, fd1, &priv);
	/*pok = priv->content;
	if (pok)
		ft_putstr(pok->content);*/
	return (0);
}
