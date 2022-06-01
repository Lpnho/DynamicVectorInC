
#include <stdio.h>
#include <stdlib.h>
#include "vet.h"
int main(void)
{

  i_array v1;
  construct_i_array(&v1, 0);
  for (int i = 0; i < 50; i++)
  {
    if (i >= v1.size)
      v1.push_element(&v1, i);
    else
      v1.vetor[i] = i;
    printf("Número %i adicionado na posição %i. Tamanho do vetor: %i\n", v1.vetor[i], i, v1.size);
  }
  for (int i = 49; i >= 10; i--)
  {
    v1.pop_element(&v1);
    printf("\nNúmero %i removido da posição %i. Tamanho do vetor: %i\n", i, i, v1.size);
    printf("\nElemento Abaixo: %i\n", v1.vetor[i - 1]);
  }
  return 0;
}
