#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include "ft_ping.h"

int check_number(const char *str)
{
    const char *p = str;
    char *end;
    long value;

    if (!*p)
        return -1;

    while (*p)
    {
        if (!isdigit((unsigned char)*p))
            return -1;
        p++;
    }

    errno = 0;
    value = strtol(str, &end, 10);

    if (errno == ERANGE)
        return -1;

    if (*end != '\0')
        return -1;

    if (value < 0 || value > 255)
        return -1;

    return 0;
}

int check_ip(char *ip)
{
    char **adress = split(ip, '.');
    int i = 0;

    if (!adress)
        return -1;

    while(adress[i])
    {
        if (check_number(adress[i]) == -1)
        {
            free_split(adress);
            return -1;
        }
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
