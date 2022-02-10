/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <dforte@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 14:54:04 by dforte            #+#    #+#             */
/*   Updated: 2022/02/10 17:35:49 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdbool.h>

typedef struct	s_stacks
{
	int		*sa;
	int		*sb;
	bool	*bsa;
	bool	*bsb;
	int		*position;
}				t_stacks;

int		init_stacks(t_stacks *stacks, int ac, char **av);
int		check_av(char *av);
int		find_loc(t_stacks *stack, int num, int arg);
int		check_sa(t_stacks *stack, int arg);
int		stackcmp(t_stacks stacks, int arg);
int		check_stack(t_stacks stack, int arg);
int		c_sa(t_stacks *stack, int arg);
int		c_reversesa(t_stacks *stack, int arg);
void	get_position(int sa[], int *position, int args, int *tmp);
void	init_position(int *position, int *tmp, int args, int sa[]);
void	free_all(t_stacks *stacks, int *tmp);
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
void	process_start(t_stacks *stack, int ac);
void	fsort(t_stacks *stack, int arg);
void	asort(t_stacks *stack, int arg);
void	allocate_struct(t_stacks *stack, int ac);

#endif