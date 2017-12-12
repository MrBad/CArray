#ifndef ARRAY_H
#define ARRAY_H

#include <stdbool.h>

// initial number of elements that can be stored; capacity
#define ARRAY_INITIAL_CAPACITY 16

typedef struct Array Array;

struct Array {
    void *data;         // pointer to array of elements
    int elementSize;    // size of one array's element in bytes
    int capacity;       // number of elements that ca be stored / capacity
    int length;         // number of allocated/active elements
};

/**
 * The type of function to be called when comparing two elements
 */
typedef int (*cmpFunc) (const void *a, const void *b);


/**
 * Runs the array tests
 */
bool arrayTest();

/**
 * Creates a new Array
 *
 * @return new array
 */
void *arrayCreate(int elementSize);

/**
 * Destrois the array
 */
void arrayDestroy(Array *array);

/**
 * Gets the number of elements in the array
 *
 * @param array - the array to check
 * @return number of elements
 */
int arrayLen(Array *array);

/**
 * Creates a new element inside the array
 *
 * @param array - the array
 * @return a pointer to a new allocated element inside the array,
 *      or NULL on error
 */
void *arrayNewElement(Array *array);

/**
 * Deletes the element at index idx and shrink the array
 * shifting the elements after it
 * It also change the lenght of array, so use it careful in loops
 *
 * @param array - the array
 * @param idx - index to delete
 * @return true on success false on error
 */
bool arrayDeleteIndex(Array *array, int idx);

/**
 * Searches for element pointed by *element and deletes it
 * shifting the elements after it
 * It also change the lenght of array, so use it careful in loops
 *
 * @param array - the array
 * @param element - pointer to element to delete
 * @return true on success, false on error
 */
bool arrayDeleteElement(Array *array, void *element);

/**
 * Resets the array, keeping the alocated buffer
 *
 * @param array - the array
 */
void arrayReset(Array *array);

/**
 * Sorts the array
 *
 * @param array - the array
 * @param func - function to be called on every 2 compared elements
 */
void arraySort(Array *array, cmpFunc func);

/**
 * Finds the index on the given element, by using binary search
 * expects the array to be sorted, in order to work
 *
 * @param array - the array
 * @param element - the element to search for
 * @param func - the function to compare element with the others
 */
int arrayIndexOf(Array *array, void *element, cmpFunc func);

#endif // ARRAY_H
