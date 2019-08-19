#include <iostream>
#include <algorithm>

char* reversed(char *input) 
{
    int size = 0;
    while (input[size++] != '\0');
    std::reverse(input, input + size - 1);
    return input;
}

int main(int argc, char **argv)
{
    std::cout << reversed(argv[1]) << std::endl;

    return 0;
}
