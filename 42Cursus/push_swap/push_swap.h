/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:54:04 by dforte            #+#    #+#             */
/*   Updated: 2022/02/14 19:07:49 by dforte           ###   ########.fr       */
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
	bool	*bsa;
	bool	*bsb;
	int		*position;
}				t_stacks;

// push_swap functions
int		init_stacks(t_stacks *stacks, int ac, char **av);
int		check_av(char *av);
int		stackcmp(t_stacks stacks, int arg);
int		check_stack(t_stacks stack, int arg);
int		sb_check(t_stacks *stack, int ac);
int		order_check(t_stacks *stack, int ac);
int		find_holdf(t_stacks *stack, int n, int ac);
int		find_holds(t_stacks *stack, int n, int ac);
int		find_maxn(t_stacks *stack, int ac);
void	backtob(t_stacks *stack, int ac, int i);
void	reset_bstack(t_stacks *stack, int ac, int n);
void	check_bstack(t_stacks *stack, int ac);
void	pushtodown(t_stacks *stack, int ac, int j, int i);
void	pushtotop(t_stacks *stack, int ac, int i, int j);
void	error_message(t_stacks *stack, int *tmp);
void	get_position(int sa[], int *position, int args, int *tmp);
void	init_position(int *position, int *tmp, int args, int sa[]);
void	free_all(t_stacks *stacks, int *tmp);
void	process_start(t_stacks *stack, int ac);
void	allocate_struct(t_stacks *stack, int ac);
void	sorting_start(t_stacks *stack, int ac, int chunks, int *count);
void	ft_pa(t_stacks *stack, int args, int i);
void	ft_pb(t_stacks *stack, int args, int i);
void	ft_sa(t_stacks *stack);
void	ft_sb(t_stacks *stack);
void	ft_ra(t_stacks *stack, int args, int i);
void	ft_rb(t_stacks *stack, int args, int i);
void	ft_rra(t_stacks *stack, int args, int i);
void	ft_rrb(t_stacks *stack, int args, int i);
void	ft_ss(t_stacks *stack);
void	ft_rr(t_stacks *stack, int args, int i);
void	ft_rrr(t_stacks *stack, int args, int i);

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