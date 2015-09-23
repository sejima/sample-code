#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv)
{
  enum { NUM = 256*1024*1024, };

  int i, j;
  unsigned long long int a;
  char *p = (char *)malloc(NUM);

  memset(p, 0x0a, NUM);

  a = 0;
  for (i = 0; i < 256*4*1024; i++)
    for (j = 0; j < NUM/4096/4/1024; j++)
      if (memcmp(p, p+j*4096, 4096) == 0)
	++a;

  printf("%llu\n", a);

  free(p);

  return 0;
}
