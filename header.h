#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#define print(s) printf("%i\n", s)
typedef struct i_array
{
    int *vetor;
    int size;
    int (*pop_element)(struct i_array *);
    int (*push_element)(struct i_array *, int);
} i_array;

static int vpop_element(i_array *array);
static int vpush_element(i_array *array, int element);
int construct_i_array(i_array *array, int elements);
#endif