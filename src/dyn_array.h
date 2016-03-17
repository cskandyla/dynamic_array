#ifndef __DYN_ARRAY_H
#define __DYN_ARRAY_H
#include <stddef.h>
#define STARTING_CAPACITY 100

typedef
struct dyn_array
{

    size_t size;
    size_t capacity;
    size_t elem_size;
    void * data;

} dyn_array;


void* dyn_array_alloc(dyn_array *array,size_t elem_size);
void  dyn_array_realloc(dyn_array *array);
void  dyn_array_add(dyn_array *array,void *value);
void* dyn_array_get(dyn_array *array,size_t index);
void  dyn_array_remove_at(dyn_array *array,size_t index);
void  dyn_array_remove(dyn_array *array);
void  dyn_array_free(dyn_array *array);
#endif
