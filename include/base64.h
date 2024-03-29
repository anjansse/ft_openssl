/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base64.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjansse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 16:01:22 by anjansse          #+#    #+#             */
/*   Updated: 2019/06/14 13:10:58 by anjansse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE64_H
# define BASE64_H

# define B64_ENCODING \
	"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"

# define SPEC_POWER2(x) ((1 << x) - 1)

# define RIGHT_SHIFT(c) (c >> 2)
# define LEFT_SHIFT(c) (c & 63)
# define SHIFT(old, nw, x, y) ((old & SPEC_POWER2((6 - y))) << y) | (nw >> x)

# define DECRYPT_B64(old, nw, x, y) \
	((old & SPEC_POWER2((8 - x))) << x | nw >> y)

# define FLE 0x01
# define FLD 0x02
# define FLI 0x04
# define FLO 0x08

typedef struct			s_base64 {
	int					size;
	unsigned char		flag;
}						t_base64;

t_base64				check_b64_flags(t_base64 base, char *flag);
char					*get_input(char *str, t_base64 base);
char					*pad_end(char *str, int pad);
int						extra_pad(char *str);
int						get_size(char *str, char c);
int						*dispatch_b64(char *str);

#endif
