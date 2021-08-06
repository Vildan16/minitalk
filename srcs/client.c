#include "../includes/minitalk.h"

int		ft_atoi(const char *nptr)
{
	int i;
	int res;
	int minus;

	i = 0;
	res = 0;
	minus = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n' || \
			nptr[i] == '\r' || nptr[i] == '\v' || nptr[i] == '\f')
		i++;
	if (nptr[i] == '-')
	{
		minus = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * minus);
}

int ft_send(int pid, char *str)
{
    int i;

    while(*str)
    {
        i = 0;
        while (i <= 7)
        {
            if (*str % 2)
                kill(pid, SIGUSR1);
            else
                kill(pid, SIGUSR2);
            *str /= 2;
            i++;
            usleep(50);
        }
        str++;
    }
    return (0);
}

int main(int ac, char **av)
{
    int pid;

    if (ac != 3)
    {
        write(1, "Error\nWrong number of arguments\n", 34);
        return (0);
    }
    pid = ft_atoi(av[1]);
    if (pid < 0 || pid > 99998)
    {
        write(1, "Error\nWrong pid\n", 18);
        return (0);
    }
    if (av[2])
        ft_send(pid, av[2]);
    return (0);
}