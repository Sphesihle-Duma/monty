#include "monty.h"
/**
 * exec_instruct - executes the instruction
 * @opcode: opcode
 * @stack: pointer to pointer
 * @line_number: line number
 */
void exec_instruct(char *opcode, stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].opcode)
	{
		if (strcmp(instructions[i].opcode, opcode) == 0)
		{
			instructions[i].f(stack, line_number);
			break;
		}
		i++;
	}

}
