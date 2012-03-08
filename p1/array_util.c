#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#include "array_util.h"

void arraryCopy(void *dest, int dIndex, const void* src, int sIndex, int len, int destLen, size_t size)
{
   uint8_t *udest = (uint8_t*) dest;
   uint8_t *usrc = (uint8_t*) src;
   dIndex  *= size;
   sIndex  *= size;
   len     *= size;
   destLen *= size;
  
   if (src != dest)
   {
   memcpy(&udest[dIndex], &usrc[sIndex], len);
   }else
   {
   if (dIndex > sIndex)
   {
       uint8_t *tmp = (uint8_t*) calloc(destLen, size);
       memcpy(tmp, &udest[dIndex], (destLen-dIndex));
       memcpy(&udest[dIndex], &usrc[sIndex], len);
       memcpy(&udest[dIndex+len], tmp, (destLen-dIndex));
       free(tmp);
   }else if (sIndex > dIndex)
   {
       memcpy(&udest[dIndex], &usrc[sIndex], (destLen-sIndex)+1);
   }else
       return;
   }
}
