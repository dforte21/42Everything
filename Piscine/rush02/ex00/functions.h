/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 18:21:56 by dforte            #+#    #+#             */
/*   Updated: 2021/12/12 19:04:57 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_dict_str
{
	int		size;
	char	*nb;
	char	*wnb;
}				t_dict_struct;

void	load_dict(struct s_dict_str *dict_struct, int fp);
void	initialize_struct(struct s_dict_str *dict_struct, int maxlen, int size);
void	rush(struct s_dict_str *dict_struct, char *str, int size, int len);
void	initialize_nb(char *str);
void	ft_putstr(char *str);
void	newline(char c, int *flag, int *j, int *i);
void	double_point(char c, int *flag, int *j);
void	try_split(struct s_dict_str *dict_struct, char *str, int size);
void	split(struct s_dict_str *dict_struct, char *str, int size);
void	process_start(char *str, char *dict);
void	c_newline(char c, int *row, int *x);
void	print_cents(struct s_dict_str *dict_struct, char n, int max_size);
void	print_dec(struct s_dict_str *dict_struct, char n, char m, int max_size);
void	p_unit(struct s_dict_str *dict_struct, char *n, int size, int max_size);
void	change1(int *len, char *str);
void	change2(int *len, char *str);
char	*ft_strcpy(char *dest, char *src);
int		check_zero(char *str, char *str2, int ac);
int		check_cents(struct s_dict_str *dict_struct, char n, int max_size);
int		check_dec(struct s_dict_str *dict_struct, char n, char m, int max_size);
int		c_unit(struct s_dict_str *dict_struct, char *n, int size, int max_size);
int		c_nu(struct s_dict_str *dict_struct, char *str, int size, int max_size);
int		try_rush(struct s_dict_str *dict_struct, char *str, int size, int len);
int		check_nbr(char *str);
int		err_msg(void);
int		dicterr_msg(void);
int		str_cpy(char *c1, char *c2, int j);
int		f_n(struct s_dict_str *dict_struct, char *str, int size, int max_size);
int		count(int *size, int *max_len, char *dict);
int		check_dict(struct s_dict_str *dict_struct, int size);
int		str_len(char *str);

#endif
