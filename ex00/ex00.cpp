#include <iostream>
#include <cstdlib>

void writeinup(char *arg)
{
    int x = 0;
    char c;

    while(arg[x])
    {
        c = toupper(arg[x]);
        printf("%c", c);
        x++;
    }
}

int main( int argc, char **argv)
{
    int x = 1;

    while(x < argc)
    {
        writeinup(argv[x]);
        x++;
    }
    printf("\n");
    return 0;
}