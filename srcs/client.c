#include "minitalk.h"

int main(int ac, char **av)
{
    int pid;

    if (ac != 3)
    {
        write(1, "Error\nWrong number of arguments\n", 34);
        return (0);
    }
    pid = ft_atoi(av[1]);
    if (pid < 0 || pid > 30000)
    {
        write(1, "Error\nWrong pid\n", 18);
        return (0);
    }
    
}