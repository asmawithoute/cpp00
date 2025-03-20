#include <iostream>

void writeinup(char *arg)
{
    for(int i=0; arg[i]; i++)
        std::cout << char(toupper(arg[i]));
}

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for(int i = 1; i < argc; i++)
        writeinup(argv[i]);
    std::cout << std::endl;
    return 0;
}
