#include "so_long.h"


t_stack	*new_node(t_check_item *data)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	node->next = NULL;
	node->branch_x = data->x;
	node->branch_y = data->y;
	return (node);
}

t_stack	*new_sentinel(void)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (node == NULL)
		return (NULL);
	node->next = NULL;
	node->branch_x = -1;
	node->branch_y = -1;
	return (node);
}

//void	push(t_stack *stack, t_check_item *data)
int	push(t_stack *stack, t_check_item *data)
{
	t_stack	*head;
	t_stack	*head_next;

	head = new_node(data);
	if (head == NULL)
		return (-1);
	if (stack->next == NULL)
	{
		stack->next = head;
		return (0);
	}
	head_next = stack->next;
	stack->next = head;
	head->next = head_next;
	return (0);
}

void	pop(t_stack *stack)
{
	t_stack	*head;

	head = stack->next;
	if (head == NULL)
		return ;
	stack->next = head->next;
	free(head);
}
