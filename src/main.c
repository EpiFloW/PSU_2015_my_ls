/*
** main.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Fri Nov 27 18:02:30 2015 Maisonnave Florian
** Last update Sun Nov 29 21:33:36 2015 Maisonnave Florian
*/

#include "struct.h"

void	ls_alone()
{
  t_my_struct	s;

  s.dirp = opendir("./");
  while ((s.dp = readdir(s.dirp)) != NULL)
  {
    if (s.dp->d_name[0] != '.')
      {
	my_putstr(s.dp->d_name);
	my_putchar(' ');
      }
  }
  my_putchar('\n');
  closedir(s.dirp);
}

int	ls_mult(char **av, int i)
{
  t_my_struct	s;

  s.dirp = opendir(av[i]);
  if (s.dirp == NULL)
    {
      my_putstr("my_ls: cannot access ");
      my_putstr(av[i]);
      my_putstr(": No such file or directory\n");
      return (0);
    }
  while ((s.dp = readdir(s.dirp)) != NULL)
    {
      if (s.dp->d_name[0] != '.')
	{
	  my_putstr(s.dp->d_name);
	  my_putchar(' ');
	}
    }
  my_putchar('\n');
  closedir(s.dirp);
  return (0);
}

int	main(int ac, char **av)
{
  t_my_struct	s;

  s.i = 1;
  if (av[1] == NULL)
    ls_alone();
  else
    {
      if (av[1][0] == '-')
	flags(ac, av);
      else
	while (s.i != ac)
	  {
	    ls_mult(av, s.i);
	    s.i++;
	  }
    }
  return (0);
}
