/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:39 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/18 16:36:40 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	cheapest(t_stack_node *stack)
{
	t_stack_node	*temp;
	int				lowest;
	int				result_ind;

	temp = stack;
	lowest = INT_MAX;
	while (temp != NULL)
	{
		if (temp->push_cost < lowest)
		{
			lowest = temp->push_cost;
			result_ind = temp->current_index;
		}
		temp = temp->next;
	}
	while (stack != NULL)
	{
		if (stack->current_index == result_ind)
			stack->cheapest = true;
		else
			stack->cheapest = false;
		stack = stack->next;
	}
}

static	int	calc_cost(t_stack_node *node, int len)
{
	int	result;

	if (node->current_index == 1)
		result = 0;
	else if (node->current_index == 2)
		result = 1;
	else if (node->current_index > 2 && node->top_half == true)
		result = node->current_index - 1;
	else if (node->current_index == len)
		result = 1;
	else if (node->current_index < len && node->top_half == false)
		result = len - node->current_index + 1;
	return (result);
}

void	set_cost(t_stack_node *src, t_stack_node *dest)
{
	int				src_len;
	int				dest_len;
	int				s_cost;
	int				d_cost;
	t_stack_node	*temp;

	src_len = count_nodes(src);
	dest_len = count_nodes(dest);
	temp = src;
	while (src != NULL)
	{
		s_cost = calc_cost(src, src_len);
		d_cost = calc_cost(src->target_node, dest_len);
		if (s_cost == d_cost && src->top_half == src->target_node->top_half)
			src->push_cost = s_cost;
		else
			src->push_cost = s_cost + d_cost;
		src = src->next;
	}
	cheapest(temp);
}