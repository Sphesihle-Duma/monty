#include "monty.h"
/**
 * push - insert a node into the stack
 * @stack: pointer to pointer
 * @line_number: line number
 */
void push(stack_t **stack, unsigned int line_number)
{
	int int_value;
	unsigned int i;
	stack_t *new_node, *top = *stack;

	if (!str_value)
	{
		fprintf(stderr, "L%u: Error: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < strlen(str_value); i++)
	{
		if (str_value[i] == '-' && i == 0)
			continue;
		else if (!isdigit(str_value[i]))
		{
			fprintf(stderr, "l%u:Error: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
	}
	int_value = atoi(str_value);
	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	new_node->n = int_value;
	new_node->prev = NULL;
	new_node->next = top;
	if (top)
		top->prev = new_node;
	*stack = new_node;
}

/**
 * pall - displays all elements in a stack
 * @stack: pointer to pointer
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: Error: stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (top)
	{
		temp = top;
		free(top);
		printf("%d\n", temp->n);
		top = temp->next;
	}
}
