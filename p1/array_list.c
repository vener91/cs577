#include <stdio.h>
#include <stdlib.h>

#include "array_list.h"
#include "array_util.h"
#include "array_util.c"

void init (ArrayList *const list)
{
    initWithSize(list, 10000);
}
void initWithSize(ArrayList *const list, int size)
{
    initWithSizeAndIncRate(list, size, 5000);
}

void initWithSizeAndIncRate(ArrayList *const list, int size, int rate)
{
    list->size = size;
    list->increment_rate = rate;
    list->elements = (Element*) calloc(sizeof(Element), list->size);
    list->current = -1;
}

void clear (ArrayList *const list)
{
    while (list->current>=0)
    {
    list->elements[list->current] = (Element){0};
    list->current--;
    }
}

int set (ArrayList *const list, Element e, int index)
{
    if (index <= list->current)
    {
    list->elements[index] = e;
    }
    return 0;
}

Element* get (ArrayList *const list, int index)
{
    if (index <= list->current)
    {
    Element *e = &list->elements[index];
    return e;
    }
    return NULL;
}

int add (ArrayList *const list, Element e)
{
    if (++list->current < list->size)
    {
    list->elements[list->current] = e;
    return 1;
    }else
    {
    wide(list);
    list->elements[list->current] = e;
    return 1;
    }
    return 0;
}
static void wide(ArrayList* const list)
{
    list->size += list->increment_rate;
    Element *newArr = (Element*) calloc(sizeof(Element), list->size) ;
    arraryCopy(newArr, 0, list->elements, 0, list->current, list->size, sizeof(Element));
    free(list->elements);
    list->elements = newArr;
}

int insert (ArrayList *const list, Element e, int index)
{
    if (index <= list->current && ++list->current < list->size)
    {
    shift(list, index, 1, RIFHT);
    list->elements[index] = e;
    return 1;
    }
    return 0;
}

int lastIndexOf (const ArrayList *const list, Element e)
{
    int index = list->current;
    while (index >-1)
    {
    if (e.data == list->elements[index].data) return (list->current-index);
    index--;
    }
    return 0;
}

int indexOf (const ArrayList *const list, Element e)
{
    int index = 0;
    while (index <= list->current)
    {
    if (e.data == list->elements[index].data) return index;
    index++;
    }
    return 0;
}

int isEmpty (const ArrayList *const list)
{
    return list->current == -1;
}

Element    *removeAt(ArrayList *const list, int index)
{
    if (list->current >= index)
    {
    Element *e = &list->elements[index];
    shift(list, index, 1, LEFT);
    list->current--;    
    return e;
    }
    return NULL;
}

void print (const ArrayList *const list)
{
    int i;
    for (i=0; i<=list->current; i++)
    {
    Element e = list->elements[i];
    printElement(&e);
    }
    printf("\n");
}

void clean(ArrayList *list)
{
    free(list->elements);
}

static void printElement(const Element *const e)
{
    printf("%i ", e->data);
}

static void shift(ArrayList *const list, int index, int rooms, Shift dir)
{
    if (dir == RIFHT)
    {
    arraryCopy(list->elements, index+1, list->elements, index, rooms, list->current, sizeof(Element));
    }else //SHIFT
    {
    arraryCopy(list->elements, index, list->elements, index+1, rooms, list->current, sizeof(Element));
    }
}
