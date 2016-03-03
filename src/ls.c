/*
** ls.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Sat Nov 28 17:59:45 2015 Maisonnave Florian
** Last update Sun Nov 29 23:31:02 2015 Maisonnave Florian
*/

#include "struct.h"

void	rights(t_my_struct s)
{
  my_putstr((S_ISDIR(s.nfo.st_mode)) ? "d" : "-");
  my_putstr((s.nfo.st_mode & S_IRUSR) ? "r" : "-");
  my_putstr((s.nfo.st_mode & S_IWUSR) ? "w" : "-");
  my_putstr((s.nfo.st_mode & S_IXUSR) ? "x" : "-");
  my_putstr((s.nfo.st_mode & S_IRGRP) ? "r" : "-");
  my_putstr((s.nfo.st_mode & S_IWGRP) ? "w" : "-");
  my_putstr((s.nfo.st_mode & S_IXGRP) ? "x" : "-");
  my_putstr((s.nfo.st_mode & S_IROTH) ? "r" : "-");
  my_putstr((s.nfo.st_mode & S_IWOTH) ? "w" : "-");
  my_putstr((s.nfo.st_mode & S_IXOTH) ? "x" : "-");
}

int	ls_l(char **av)
{
  t_my_struct	s;

  if (av[2] != NULL)
    {
      s.dirp = opendir(av[2]);
      if (s.dirp == NULL)
	{
	  my_putstr("my_ls: cannot access ");
	  my_putstr(av[2]);
	  my_putstr(": No such file or directory\n");
	  return (0);
	}
    }
  if (av[2] == NULL)
    {
      s.dirp = opendir("./");
      my_putstr("total ");
      blocks(s);
      my_putchar('\n');
    }
  calc(av, s);
  closedir(s.dirp);
  return (0);
}

void	calc(char **av, t_my_struct s)
{
  while ((s.dp = readdir(s.dirp)) != NULL)
    {
      if (s.dp->d_name[0] != '.')
	{
	  stats(av, s);
	  my_putstr(s.dp->d_name);
	  my_putchar('\n');
	}
    }
}

void	blocks(t_my_struct s)
{
  DIR	*rep;
  int	t;
  int	t2;

  t = 0;
  t2 = 0;
  rep = opendir("./");
  while ((s.dp = readdir(rep)) != NULL)
    {
      if (s.dp->d_name[0] != '.')
	{
	  stat(s.dp->d_name, &s.nfo);
	  t = (s.nfo.st_blocks) + t;
	  t2 = t2 + t;
	}
    }
  my_putnbr(t / 2);
}

void	stats(char **av, t_my_struct s)
{
  char	*time;
  char	test[1000];

  test[0] = 0;
  my_strcpy(test, av[2]);
  my_strcat(test, s.dp->d_name);
  stat(test, &s.nfo);
  rights(s);
  my_putchar(' ');
  my_putnbr(s.nfo.st_nlink);
  my_putchar(' ');
  get_uid(s);
  my_putchar(' ');
  s.group = getgrgid(s.nfo.st_gid);
   my_putstr(s.group->gr_name);
  my_putchar(' ');
  my_putnbr(s.nfo.st_size);
  my_putchar(' ');
  time = (ctime(&s.nfo.st_ctime));
  write(1, 4 + time, 12);
  my_putchar(' ');
}
