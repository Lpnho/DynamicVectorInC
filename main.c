#include "header.h"
#include <stdio.h>
#include <stdlib.h>
int main(void)
{

  i_array v1;
  construct_i_array(&v1, 3);
  for (int i = 0; i < 3; i++)
    v1.vetor[i] = i;
  for (int i = 0; i < 3; i++)
    print(v1.vetor[i]);
  print(v1.size);
  v1.pop_element(&v1);
  print(v1.size);

  return EXIT_SUCCESS;
}
