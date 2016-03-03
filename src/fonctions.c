/*
** fonctions.c for  in /home/maison_f/rendu/PSU_2015_my_ls
**
** Made by Maisonnave Florian
** Login   <maison_f@epitech.net>
**
** Started on  Fri Nov 27 18:45:52 2015 Maisonnave Florian
** Last update Sun Nov 29 19:11:21 2015 Maisonnave Florian
*/

#include "struct.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putnbr(int nb)
{
  int	i;

  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  i = nb % 10;
  if (nb >= 10)
    my_putnbr(nb / 10);
  my_putchar(i + 48);
}

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  if (dest == NULL || src == NULL)
    {
      return (0);
    }
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '/';
  dest[i + 1] = '\0';
  return (dest);
}

char    *my_strcat(char *dest, char *src)
{
  int   a;
  int   b;

  a = 0;
  b = 0;
  while (dest[a] != '\0')
    {
      a = a + 1;
    }
  while (src[b] != '\0')
    {
      dest[a] = src[b];
      b = b + 1;
      a = a + 1;
    }
  dest[a] = '\0';
  return (dest);
}
