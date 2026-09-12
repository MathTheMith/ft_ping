#include <stdio.h>
#include "ft_ping.h"

int main(int ac, char **av)
{
    if (ac < 2)
    {
        fprintf(stderr, "ping: missing host operand\n");
        fprintf(stderr, "Try `ping --help' or `ping --usage' for more information.\n");
        return 64;
    }

    if (parse(ac, av) == -1)
    {
        fprintf(stderr, "ping: unknown host\n");
        return 1;
    }

    return 0;
}