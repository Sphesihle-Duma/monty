#include "monty.h"
char *str_value = NULL;
/**
 * main - execute bytecode
 * @argc: number of strings
 * @argv: array of strings
 * Return: 0 on Success
 */
int main(int argc, char *argv[])
{
	FILE *file;
	char line[256];
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while(fgets(line, sizeof(line), file) != NULL)
	{
		line_number++;
		str_value = strtok(line, " \t\n");
		opcode = str_value;
		printf("%s %s\n", str_value, opcode);
		if (opcode == NULL || opcode[0] == '#')
			printf("Okay");
		str_value = strtok(NULL, " \t\n");
		exec_instruct(opcode, &stack, line_number);
	}
	fclose(file);
	return (0);
}
