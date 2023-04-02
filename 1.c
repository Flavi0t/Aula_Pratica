#include <stdio.h>

int
main ()
{
  int num, a;

  printf ("Digite o nC:mero desejado:\n");
  scanf ("%d", &num);

  if (num <= 1)
    {
      printf ("%d nC#o C) primo\n", num);
    }
  else
    {
      for (a = 2; a * a <= num; a++)
	{
	  if (num % a == 0)
	    {
	      printf ("%d nC#o C) primo\n", num);
	      return 0;
	    }
	}
      printf ("%d C) primo!\n", num);
    }
  return 0;
}
