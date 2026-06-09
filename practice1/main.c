#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    const char *name;

    if (argc > 1)
    {
        name = argv[1];
    }
    else
    {
        name = getenv("USERNAME");

        if (name == NULL)
        {
            name = "world";
        }
    }

    printf("Hello, %s!\n", name);
    return 0;
}