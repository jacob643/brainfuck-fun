#include <stdio.h>
#include <ios>
#include <fstream>
#include <iostream>
#include "brainfuck.h"

// initialize the tape with 30,000 zeroes
unsigned char tape[30000] = {0};

// index starts at 0
size_t index = 0;

void go_to_next_matching_bracket(size_t& i, char* input)
{
	unsigned short loop = 1;
	char current_char;

	while (loop > 0)
	{
		current_char = input[++i];
		if (current_char == '[')
		{
			loop++;
		}
		else if (current_char == ']')
		{
			loop--;
		}
	}
}

void go_to_prev_matching_bracket(size_t& i, char* input)
{
	unsigned short loop = 1;
	char current_char;

	while (loop > 0)
	{
		current_char = input[--i];
		if (current_char == '[')
		{
			loop--;
		}
		else if (current_char == ']')
		{
			loop++;
		}
	}
}

void debug_here(bool& ShouldExit)
{
	ShouldExit = false;
	using namespace std;
	cout << endl << "debug ----------" << endl
		<< "ptr is on: " << index << endl
		<< "tape:";
	for (size_t i = 0; i < index + 1; i++)
	{
		cout << " [" << i << ":" << (int)tape[i] << "] -";
	}
	cout << endl << "end of debug----" << endl;
	char entered = 'y';
	while (entered != 'c' && entered != 'q')
	{
		cout << "q to quit, c to continue" << endl;
		cin >> entered;
	}
	if (entered == 'q')
	{
		ShouldExit = true;
	}
}

void evaluate_character(char* input, size_t& i, bool& ShouldExit)
{
	ShouldExit = false;
	char current_char = input[i];

	if (current_char == '>')
	{
		++index;
	}
	else if (current_char == '<')
	{
		--index;
	}
	else if (current_char == '+')
	{
		++tape[index];
	}
	else if (current_char == '-')
	{
		--tape[index];
	}
	else if (current_char == '.')
	{
		putchar(tape[index]);
	}
	else if (current_char == ',')
	{
		tape[index] = getchar();
	}
	else if (current_char == '[' && !(tape[index]))
	{
		go_to_next_matching_bracket(i, input);
	}
	else if (current_char == ']' && tape[index])
	{
		go_to_prev_matching_bracket(i, input);
	}
	else if (current_char == 'd' && input[i + 1] == 'e' && input[i + 2] == 'b' && input[i + 3] == 'u' && input[i + 4] == 'g' && input[i + 5] == 'h' && input[i + 6] == 'e' && input[i + 7] == 'r' && input[i + 8] == 'e')
	{
		//debughere encountered:
		debug_here(ShouldExit);
	}
}

void interpret_code(char* input)
{
    size_t i;
    for (i = 0; input[i] != 0; i++)
	{
		bool ShouldExit;
		evaluate_character(input, i, ShouldExit);
		if (ShouldExit) break;
    }
}

char* read_file(int argc, char *argv[])
{
	using namespace std;

	const char* path = "brainfuck.code";
	if(argc > 1) path = argv[1];

	unsigned int next_char_position = 0;
	unsigned int size_of_array = 10;
	char* code = new char[size_of_array];

	ifstream file;
	file.open (path, ifstream::in);

	char c = file.get();
	while (file.good())
	{
		if(next_char_position == size_of_array)
		{
			size_of_array *= 2;

			char* old_array = code;
			code = new char[size_of_array];
			for(int i = 0; i < size_of_array/2; i++)
			{
				code[i] = old_array[i];
			}

			delete[] old_array;
		}
		code[next_char_position++] = c;
		c = file.get();
	}

	file.close();

	{
		char* old_array = code;
		code = new char[next_char_position+1];
		for(int i = 0; i < next_char_position; i++)
		{
			code[i] = old_array[i];
		}
		code[next_char_position-1] = (char)0;

		delete[] old_array;
	}
	cout << next_char_position << " size of array" << endl;

	return code;
}

int main(int argc, char *argv[])
{
	setbuf(stdout, NULL);
	char* code = read_file(argc, argv);

	interpret_code(code);

	delete[] code;

    return 0;
}
