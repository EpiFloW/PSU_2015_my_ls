/*
** flags.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Nov 28 16:56:31 2015 Maisonnave Florian
** Last update Sun Nov 29 21:56:57 2015 Maisonnave Florian
*/

#include "struct.h"

int	tab(char **av, char c)
{
  int	(*flags[1])(char **);
  char	*str;
  int	i;

  str = "l";
  i = 0;
  flags[0] = &ls_l;
  while (str[i] != c)
    {
      i++;
      if (i >= 2)
	return (0);
    }
  flags[i](av);
  return (1);
}

void	flags(int ac, char **av)
{
  int	i;
  int 	k;
  char	c;

  i = 1;
  k = 0;
  while (i <= (ac - 1))
    {
      while (av[i][k] != '\0')
	{
	  if (av[i][k] == '-')
	    {
	      k++;
	      c = av[i][k];
	      tab(av, c);
	    }
	  k++;
	}
      i++;
      k = 0;
    }
}
