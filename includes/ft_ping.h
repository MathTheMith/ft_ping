#ifndef FT_PING_H
# define FT_PING_H

char	**split(const char *str, char delim);
void	free_split(char **tab);

int		check_number(const char *str);
int		check_ip(char *ip);
int		parse(int ac, char **av);

#endif
