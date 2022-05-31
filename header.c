#include "header.h"
#include <stdio.h>
#include <stdlib.h>
static int vpop_element(i_array *array)
{
    if (!array)
        return 0;
    int vetor[array->size];
    for (register int i = 0; i < array->size; i++)
        vetor[i] = array->vetor[i];
    array->vetor = (int *)realloc(array->vetor, (array->size - 1) * sizeof(int));
    array->size--;
    if (!array->vetor)
        return 0;
    for (register int i = 0; i < array->size; i++)
        array->vetor[i] = vetor[i];
    return 1;
}
static int vpush_element(i_array *array, int element)
{
    if (!array)
        return 0;
    int vetor[array->size];
    for (register int i = 0; i < array->size; i++)
        vetor[i] = array->vetor[i];
    array->vetor = (int *)realloc(array->vetor, (array->size + 1) * sizeof(int));
    array->size++;
    if (!array->vetor)
        return 0;
    for (register int i = 0; i < array->size - 1; i++)
        array->vetor[i] = vetor[i];
    array->vetor[array->size] = element;
    return 1;
}
int construct_i_array(i_array *array, int elements)
{
    if (!array)
        return 0;
    elements = (elements == 0) ? 1 : elements;
    array->vetor = (int *)malloc(elements * sizeof(int));
    if (!array->vetor)
        return 0;
    array->size = elements;
    array->push_element = vpush_element;
    array->pop_element = vpop_element;
    return 1;
}