/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:54:04 by dforte            #+#    #+#             */
/*   Updated: 2022/02/19 13:30:35 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>
#include<sys/wait.h>

typedef struct s_stacks
{
	int		*sa;
	int		*sb;
	int		alen;
	int		blen;
	int		*position;
}				t_stacks;

// push_swap functions
int		init_stacks(t_stacks *stacks, int ac, char **av);
int		check_av(char *av);
int		stackcmp(t_stacks stacks, int arg);
int		check_stack(t_stacks stack, int arg);
int		sb_check(t_stacks *stack, int ac);
int		hold_first(t_stacks *stack, int len, int k);
int		hold_second(t_stacks *stack, int len, int k);
int		find_num(int *stack, int len, int num);
int		findmin(int	*stack, int len);
int		findmax(int	*stack, int len);
int		order_check(int *stack, int len);
int		check_minmax(int *stack, int len, int position);
void	backtob(t_stacks *stack);
void	big_sort(t_stacks *stack, int chunks);
void	orderb(t_stacks *stack);
void	pushtotop(t_stacks *stack, int len, int i, int check);
void	quick_sort(t_stacks *stack);
void	error_message(t_stacks *stack, int *tmp);
void	get_position(int sa[], int *position, int args, int *tmp);
void	init_position(int *position, int *tmp, int args, int sa[]);
void	free_all(t_stacks *stacks, int *tmp);
void	process_start(t_stacks *stack, int ac);
void	allocate_struct(t_stacks *stack, int ac);
void	ft_pa(t_stacks *stack, int len);
void	ft_pb(t_stacks *stack, int len);
void	ft_sa(t_stacks *stack);
void	ft_sb(t_stacks *stack);
void	ft_ra(t_stacks *stack, int len);
void	ft_rb(t_stacks *stack, int len);
void	ft_rra(t_stacks *stack, int len);
void	ft_rrb(t_stacks *stack, int len);
void	ft_ss(t_stacks *stack);
void	ft_rr(t_stacks *stack);
void	ft_rrr(t_stacks *stack);

//checker functions
int		ft_read(int ac, t_stacks *stacks);
int		check_buffer(char *buffer);
int		bsb_check(t_stacks *stack, int ac);
int		border_check(t_stacks *stack, int ac);
void	exec_action(t_stacks *stack, int ac, char *buffer);
void	ft_bpa(t_stacks *stack, int args, int i);
void	ft_bpb(t_stacks *stack, int args, int i);
void	ft_bsa(t_stacks *stack);
void	ft_bsb(t_stacks *stack);
void	ft_bra(t_stacks *stack, int args, int i);
void	ft_brb(t_stacks *stack, int args, int i);
void	ft_brra(t_stacks *stack, int args, int i);
void	ft_brrb(t_stacks *stack, int args, int i);
void	ft_bss(t_stacks *stack);
void	ft_brr(t_stacks *stack, int args, int i);
void	ft_brrr(t_stacks *stack, int args, int i);

#endif