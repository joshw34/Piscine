/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:46 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:58:15 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	int				start_pos;

	a = NULL;
	b = NULL;
	start_pos = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		start_pos = 0;
	}
	create_stack_a(&a, argv, start_pos);
	sort(&a, &b);
	free_stack(&a);
	return (0);
}


//Output tester

/*t_stack_node	*temp;
	temp = a;
	while (temp != NULL)
	{
		ft_printf("Nbr: %d, Ind: %d, Top: %d, Current: %p, Next: %p, Prev: %p\n", temp->nbr, temp->current_index, temp->top_half, temp, temp->next, temp->prev);
		ft_printf("\n");
		temp = temp->next;
	}*/