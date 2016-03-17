#include "dyn_array.h"
#include <string.h>
#include <stdlib.h>
void* dyn_array_alloc(dyn_array *array,size_t elem_size)
{

    array->capacity=STARTING_CAPACITY;
    array->size=0;
    array->elem_size=elem_size;
    array->data=malloc(elem_size*STARTING_CAPACITY);

}


void dyn_array_realloc(dyn_array *array)
{
    array->capacity*=2;
    array->data=realloc(array->data,array->elem_size*array->capacity);

}

void dyn_array_add(dyn_array *array,void *value)
{
    if(array->size>=array->capacity)
    {
        dyn_array_realloc(array);
    }
    memcpy(array->data+array->size*array->elem_size,value,array->elem_size);
    array->size++;

}

void* dyn_array_get(dyn_array *array,size_t index)
{

    if(index>=array->size || index<0)
    {
        return NULL;
    }
    else
    {
        return array->data+index*array->elem_size;
    }

}

void dyn_array_remove_at(dyn_array *array,size_t index)
{

    //TO DELETE AT INDEX SHIFT EVERYTHING ONE LEFT~EXPENSIVE
    size_t numelems_shift=array->size-index;
    if(numelems_shift>0)
    {
        /*[ 1 2 3 4 5 6 7 ] remove_at 3(4) => shift [5 6 7 ] one left
         */
        memcpy(array->data+array->elem_size*index,array->data+array->elem_size*(index+1),numelems_shift*array->elem_size);
        array->size--;
    }


}

void dyn_array_remove(dyn_array *array)
{
    //Keep allocated memory as is no point in reallocating
    array->size--;
    if(array->size<0)
    {
        array->size=0;
    }

}


void dyn_array_free(dyn_array *array)
{

    free(array->data);

}
