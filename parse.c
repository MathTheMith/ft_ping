#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_ping.h"


int check_ip(char *ip)
{
    char **adress = split(ip, '.');
    int i = 0;

    if (!adress)
        return -1;

    while(adress[i])
    {
        i++;
    }

    free_split(adress);

    if (i != 4)
        return -1;
    return 1;
}

int parse(int ac, char **av)
{
    if (ac != 2 && (ac != 3 || av[1][0] != '-'
        || (av[1][1] != 'v' && av[1][1] != '?') || av[1][2] != '\0'))
        return -1;

    if (check_ip(av[ac-1]) == -1)
        return -1;
    return 0;
}
