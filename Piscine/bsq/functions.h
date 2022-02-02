/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dforte <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 16:18:30 by dforte            #+#    #+#             */
/*   Updated: 2021/12/14 16:20:46 by dforte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H
# define FILE_CHECK(pt) if(pt == -1) {return (merr_msg());}
# define MALLOC_CHECK(ptr) if(!(ptr)) {return (malloc_err());}
# define MAP_ERROR return (merr_msg());
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_map
{
	int		row;
	int		col;
	int		solutions[2];
	char	signs[4];
	char	*f_row;
	char	**mat;
}				t_map;

void	init_struct(struct s_map *map);
void	get_rc(struct s_map *map, int file);
void	print_struct(struct s_map map);
void	process_start(struct s_map map);
void	skip_fr(int file, int len, char *c);
void	get_solutions(struct s_map *map, int i, int j, int *maxsize);
void	start_calc(struct s_map map, int *size, int o_cord[], int *v_cord);
void	print_solution(t_map map, int maxsize);
void	put_strend(char *str);
void	free_all(t_map *map);
void	start_program(char *filename);
int		check_mat(int file, char *sign);
int		check_num(char *str, int *i);
int		check_printchar(char *str, int *i, char *sign);
int		check_fr(int fp, char *sign);
int		check_map(char filen[]);
int		check_col(struct s_map map, int i, int j, int o_cord[]);
int		check_row(struct s_map map, int i, int j, int *flag);
int		get_frow(int file, struct s_map *map, int len);
int		get_mat(struct s_map *map, char *filename, int len);
int		load_struct(struct s_map *map, char *filename);
int		merr_msg(void);
int		malloc_err(void);
int		get_frow_len(char *file);

#endif
