#include "../includes/minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	int		i;
	char	a[15];

	i = 0;
	if (n == 0)
		ft_putchar('0');
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -1 * n;
	}
	while (n != 0)
	{
		a[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(a[i]);
}

int		ft_power(int i)
{
	int		j;
	int		power;

	if (i == 0)
		return (1);
	j = 0;
	power = 1;
	while (j < i)
	{
		power *= 2;
		j++;
	}
	return (power);
}

void	ft_handle(int signum)
{
	int				signal;
	static int		c;
	static int		i;

	if (signum == SIGUSR1)
		signal = 1;
	else
		signal = 0;
	c += ft_power(i) * signal;
	i++;
	if (i == 8)
	{
		ft_putchar(c);
		i = 0;
		c = 0;
	}
}

int main(void)
{
	int pid;

	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, ft_handle);
	signal(SIGUSR2, ft_handle);
	char *c = "\u2764";
    write(1, c, 3);
	while (1)
		pause();
	return (0);
}