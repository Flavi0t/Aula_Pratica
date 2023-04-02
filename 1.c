#include <stdio.h>

int
main ()
{
  int num, a;

  printf ("Digite o numero desejado:\n");
  scanf ("%d", &num);

  if (num <= 1)
    {
      printf ("%d nao eh primo\n", num);
    }
  else
    {
      for (a = 2; a * a <= num; a++)
	{
	  if (num % a == 0)
	    {
	      printf ("%d nao eh primo\n", num);
	      return 0;
	    }
	}
      printf ("%d eh primo!\n", num);
    }
  return 0;
}
