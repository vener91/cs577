#ifndef ARRAYUTIL_H
#define ARRAYUTIL_H

#include <stddef.h>

/**
 * dest    destination array
 * dIndex    index to which we will start copying
 * src        source array
 * sIndex    index from which we will start copying
 * len        number of elements that will be copied from source array
 * destArrLen    the length of the destination array (hence C doesn't know any length info about passed arrays)
 * size    the size of the type of the array (ex: if the array of type long, put in this parameter sizeof(long))
 */
void arraryCopy(void *dest, int dIndex, const void* src, int sIndex, int len, int destArrLen, size_t size);

#endif // ARRAYUTIL_H
