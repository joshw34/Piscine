/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwhitley <jwhitley@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:36:39 by jwhitley          #+#    #+#             */
/*   Updated: 2024/06/21 18:59:55 by jwhitley         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static	void	cheapest(t_node *stack)
{
	t_node	*temp;
	int		lowest;

	temp = stack;
	lowest = INT_MAX;
	while (temp != NULL)
	{
		if (temp->total_cost < lowest)
			lowest = temp->total_cost;
		temp = temp->next;
	}
	while (stack != NULL)
	{
		if (stack->total_cost == lowest)
			stack->cheapest = true;
		else
			stack->cheapest = false;
		stack = stack->next;
	}
}

static	int	calc_cost(t_node *node, int len)
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
		result = (len - node->current_index) + 1;
	return (result);
}

void	set_cost(t_node *src, t_node *dest)
{
	int		s_cost;
	int		d_cost;
	t_node	*temp;

	temp = src;
	while (src != NULL)
	{
		s_cost = calc_cost(src, count_nodes(src));
		d_cost = calc_cost(src->target_node, count_nodes(dest));
		src->push_cost = s_cost;
		src->target_node->push_cost = d_cost;
		if (s_cost == d_cost && src->top_half == src->target_node->top_half)
			src->total_cost = s_cost;
		else if (s_cost > d_cost && src->target_node->top_half == src->top_half)
			src->total_cost = s_cost;
		else if (s_cost < d_cost && src->target_node->top_half == src->top_half)
			src->total_cost = d_cost;
		else
			src->total_cost = s_cost + d_cost;
		src = src->next;
	}
	cheapest(temp);
}
