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
	add_dnodeint(stack, int_value);
}

/**
 * pall - displays all elements in a stack
 * @stack: pointer to pointer
 * @line_number: line number
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL || !stack)
	{
		fprintf(stderr, "L%u: Error: stack is empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	while (top)
	{
		printf("%d\n", top->n);
		top = top->next;
	}
	free_dlistint(*stack);
}
