/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sha224.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:19:58 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/13 12:06:14 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static t_ssl		*other_ssl_sha224(t_ssl *s, char *sol, char *fn, int flag)
{
	int		fd;

	while ((fd = open(s->av[s->i], O_RDONLY)) > 2)
	{
		sol = "";
		sol = ft_strjoin(sol, handle_files(s, fd));
		if (s->fl & FLP)
			ft_putstr(sol);
		if (!(s->fl & FLQ) && (!(s->fl & FLR)))
			ft_printf("SHA256(%s)= ", s->av[s->i]);
		if (s->fl & FLR)
			fn = s->av[s->i];
		sha224_hash(sol, flag, fn);
		s->i++;
	}
	return (s);
}

void				ssl_sha224(int argc, char **argv)
{
	int		flag;
	char	*sol;
	char	*fn;
	t_ssl	*s;

	sol = "";
	fn = "";
	s = ft_memalloc(sizeof(t_ssl));
	s->i = -1;
	s->av = argv;
	s->ac = argc;
	while (++s->i <= s->ac)
	{
		if (s->av[s->i] && s->av[s->i][0] == '-')
			s = handle_flags(s);
		flag = (s->fl & FLR) ? 1 : 0;
		if (s->fl & FLS)
		{
			ft_printf("SHA224 (\"%s\") = ", s->av[s->i]);
			sha224_hash(s->av[s->i++], flag, "");
		}
		other_ssl_sha224(s, sol, fn, flag);
		if (s->ac == 0 || s->fl & FLP)
			handle_str(s, sol, "sha224");
	}
}
