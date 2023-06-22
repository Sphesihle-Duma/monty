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
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
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
	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		str_value = strtok(line, " \n\t");
		opcode = str_value;
		if (opcode == NULL || opcode[0] == '#')
			continue;
		str_value = strtok(NULL, " \t\n");
		exec_instruct(opcode, &stack, line_number);
		free(line);
		line = NULL;
		len = 0;
	}
	fclose(file);
	return (0);
}
