/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabet <fabet@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 20:23:59 by fabet             #+#    #+#             */
/*   Updated: 2022/03/27 15:58:17 by fabet            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack_elem
{
	int					value;
	int					a_score;
	int					a_rscore;
	int					b_score;
	int					b_rscore;
	int					position;
	struct s_stack_elem	*next;
}	t_stack_elem;

void			ft_error(void);

char			**ft_init_arguments(int argc, char **argv);
void			ft_check_arguments(char **arguments);
void			ft_free_arguments(char **arguments);

t_stack_elem	*ft_init_stack(char **arguments);
int				ft_find_stack_size(t_stack_elem *stack);
void			ft_add_front(t_stack_elem **stack, t_stack_elem *new);
void			ft_add_back(t_stack_elem **stack, t_stack_elem *new);
t_stack_elem	*ft_find_penult_stack_elem(t_stack_elem *stack);
t_stack_elem	*ft_find_last_stack_elem(t_stack_elem *stack);
void			ft_free_stack(t_stack_elem	*head);

void			ft_sa_action(t_stack_elem **head, int output);
void			ft_pb_action(t_stack_elem **head,
					t_stack_elem **head_b, int output);
void			ft_pa_action(t_stack_elem **head_a,
					t_stack_elem **head_b, int output);
void			ft_ra_action(t_stack_elem **head, int output);
void			ft_rb_action(t_stack_elem **head, int output);
void			ft_rr_action(t_stack_elem **head_a,
					t_stack_elem **head_b, int output);
void			ft_rra_action(t_stack_elem **head, int output);
void			ft_rrb_action(t_stack_elem **head, int output);
void			ft_rrr_action(t_stack_elem **head_a,
					t_stack_elem **head_b, int output);
void			ft_sb_action(t_stack_elem **head, int output);
void			ft_ss_action(t_stack_elem **head_a,
					t_stack_elem **head_b, int output);

void			ft_find_triple(t_stack_elem **head,
					int *min, int *max, int *med);
t_stack_elem	*ft_fill_stack_b(t_stack_elem **head);
t_stack_elem	*ft_choose_best_elem(t_stack_elem *head, int *push_type);
void			ft_push_to_a(t_stack_elem **head_a, t_stack_elem **head_b);
void			ft_make_push(t_stack_elem **head_a,
					t_stack_elem **head_b, t_stack_elem *elem, int push_type);
t_stack_elem	*ft_sort_stack(t_stack_elem **head);
void			ft_final_sort_stack(t_stack_elem **head);

#endif