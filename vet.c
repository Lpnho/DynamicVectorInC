#include "vet.h"
#include <stdio.h>
#include <stdlib.h>
static int vpop_element(i_array *array)
{
    if (!array)
    {
        return 0;
    }
    else
    {
        // POINTER TO ALTER SIZE;
        int *ponterSize = &array->size;
        // COPY ARRAY;
        int backup[array->size];
        for (register int count = 0; count < array->size; count++)
        {
            backup[count] = array->vetor[count];
        }
        // FREE OLD VECTOR;
        free(array->vetor);
        // LESS MEMORY
        *ponterSize -= 1;
        // NEW ALLOCATION;
        array->vetor = (int *)calloc(array->size, sizeof(int));
        if (!array->vetor)
            return 0;
        // PASTE OLD VECTOR;
        for (register int count = 0; count < array->size; count++)
        {
            array->vetor[count] = backup[count];
        }
        return 1;
    }
}
static int vpush_element(i_array *array, int element)
{
    if (!array)
    {
        return 0;
    }
    else
    {
        // POINTER TO ALTER SIZE;
        int *ponterSize = &array->size;
        // COPY ARRAY;
        int backup[array->size];
        for (register int count = 0; count < array->size; count++)
        {
            backup[count] = array->vetor[count];
        }
        // FREE OLD VECTOR;
        free(array->vetor);
        // MORE MEMORY
        *ponterSize += 1;
        // NEW ALLOCATION;
        array->vetor = (int *)calloc(array->size, sizeof(int));
        if (!array->vetor)
            return 0;
        // PASTE OLD VECTOR;
        for (register int count = 0; count < array->size; count++)
        {
            array->vetor[count] = backup[count];
        }
        // ADD NEW ELEMENT;
        array->vetor[array->size - 1] = element;
        return 1;
    }
}
int construct_i_array(i_array *array, int elements)
{
    if (!array)
        return 0;
    else
    {
        // POINTER TO ALTER SIZE;
        int *psize = &array->size;
        // DYNAMIC ALLOCATION;
        array->vetor = (int *)calloc(elements, sizeof(int));
        if (!array->vetor)
            return 0;
        //
        if ((elements == 0) || (elements == 1) || (elements == 2))
            *psize = 2;
        else
            *psize = elements;
        // BUILDING;
        array->push_element = vpush_element;
        array->pop_element = vpop_element;
        if ((!array->pop_element) || (!array->push_element))
            return 0;
        return 1;
    }
}