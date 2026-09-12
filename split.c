#include <stdlib.h>
#include <string.h>
#include "ft_ping.h"

char **split(const char *str, char delim)
{
    int count = 1;
    int i = 0;
    char **result;
    const char *p;

    for (p = str; *p; p++)
    {
        if (*p == delim)
            count++;
    }

    result = malloc(sizeof(char *) * (count + 1));
    if (!result)
        return NULL;

    const char *start = str;

    while (i < count)
    {
        const char *end = strchr(start, delim);
        size_t len;

        if (end)
            len = end - start;
        else
            len = strlen(start);

        result[i] = malloc(len + 1);
        if (!result[i])
        {
            while (i > 0)
                free(result[--i]);
            free(result);
            return NULL;
        }

        memcpy(result[i], start, len);
        result[i][len] = '\0';

        i++;

        if (!end)
            break;

        start = end + 1;
    }

    result[i] = NULL;

    return result;
}

void free_split(char **split)
{
    int i = 0;

    if (!split)
        return;

    while (split[i])
    {
        free(split[i]);
        i++;
    }

    free(split);
}
