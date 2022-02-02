#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int	ft_strlen(char *str);
int	ft_power(int n, int p);
int	get_len(long int nbr, int size, int is_neg);
char	*ft_print_rc(long int nbr, char *base, char *res, int is_neg);
char	*ft_putnbr_base(long int nbr, char *base, int is_neg);
int	check_valid(char *base);
char	*check_sign(char *str, int *is_neg);
char	*ft_atoi(char *str, char *base, int *is_neg, int *size);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

#endif