/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:40:05 by dforte            #+#    #+#             */
/*   Updated: 2022/02/05 15:08:38 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef unsigned int	t_uint;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}			t_list;

typedef struct s_flags
{
	int		minus;
	int		width;
	int		len;
	int		zero;
	int		space;
	int		plus;
	int		hashtag;
	int		precision;
	int		nsign;
	char	sep;
}				t_flags;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int ch);
int			ft_atoi(const char *str);
int			ft_tolower(int ch);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_atoi(const char *str);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_lstsize(t_list *lst);
int			ft_printf(const char *print, ...);
int			checkch(char c);
int			arg_print(const char *print, int *count, va_list args, size_t index);
int			c_minus(t_uint *i, char *spc);
int			pget_len(unsigned long long int nbr, int size, int is_neg);
int			nlen(int nb);
int			u_nlen(t_uint nb);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strdup(const char *src);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_p_rc(unsigned long long int nbr, char *base, char *res, int is_neg);
char		*ft_putnbr_base(unsigned long long int nbr, char *base, int is_neg);
char		*ft_uitoa(t_uint n);
char		*get_hnumber(int nb, char *base, t_flags flag);
char		*get_paddr(long int addr, char *base, t_flags flag);
void		*ft_calloc(size_t count, size_t size);
void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *str1, const void *str2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		print_arg(char *spc, va_list arg, int *count, int ch);
void		p_char(int c, int *count, char *spc);
void		p_string(char *s, int *count, char *spc);
void		p_pointer(long int addr, int *count, char *spc);
void		putnstr(char *s, int len, int *count);
void		print_widht(t_flags flags, int *count, char ch);
void		init_struct(t_flags	*strct);
void		p_digit(int nb, int *count, char *spc);
void		check_fplace(char *s, t_flags *strc, int nb, t_uint *i);
void		check_precision(char *s, t_uint i, t_flags *strc, int nb);
void		print_dwidht(t_flags flag, int *count);
void		ft_putnbr(int nb, t_flags flag, int *count);
void		ft_putnnbr(char *nbr, t_flags flag, int *count, int nb);
void		print_zero(t_flags strc, int nb, int *count);
void		p_uint(t_uint nb, int *count, char *spc);
void		check_ufplace(char *s, t_flags *strc, t_uint *i);
void		check_uprecision(char *s, t_uint i, t_flags *strc, t_uint nb);
void		print_udwidht(t_flags flag, int *count);
void		ft_uputnbr(t_uint nb, t_flags flag, int *count);
void		ft_uputnnbr(char *nbr, t_flags flag, int *count, t_uint nb);
void		p_hex(int nb, int *count, char *spc, char *base);
void		print_uzero(t_flags strc, t_uint nb, int *count);
void		check_hfplace(char *s, t_flags *strc, t_uint *i, int nb);
void		print_hwidth(t_flags flag, int *count, int nb, char *base);
void		ft_puthex(char *nbr, t_flags flag, int *count, char *base);
void		check_hprecision(char *s, t_uint i, t_flags *strc, char *nbr);
void		all_nhex(char *nhex);
void		print_hzero(t_flags strc, char *nbr, int *count);
void		init_ch(char *ch, char *base);
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstnew(void *content);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlcat(char *dest, char *src, size_t size);

#endif