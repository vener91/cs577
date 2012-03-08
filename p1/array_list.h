/*
 * ArrayList
 */
#ifndef ARRAYLIST_H
#define ARRAYLIST_H

typedef struct
{
    int data;
}Element;

typedef struct
{
    int current;
    int size;
    int increment_rate;
    Element *elements;
}ArrayList;

typedef enum
{
    RIFHT, LEFT
} Shift;

// public functions:
void        init           (ArrayList*const);
void        initWithSize   (ArrayList*const, int);
void        initWithSizeAndIncRate    (ArrayList*const, int, int);
void        clean          (ArrayList*);
int         add            (ArrayList*const, Element);
int         insert         (ArrayList*const, Element, int);
Element*    removeAt       (ArrayList*const, int);
void        clear          (ArrayList*const);
int         set            (ArrayList*const, Element, int);
Element*    get            (ArrayList*const, int);
void        print          (const ArrayList*const);
int         lastIndexOf    (const ArrayList*const, Element);
int         indexOf        (const ArrayList*const, Element);
int         isEmpty        (const ArrayList*const);
// TODO
int        hashCode        (const ArrayList*const);


// static (private) utility functions:

/* Abstracting the print method of the element by delegating it to the element itself (OOP-like feature) */
static void    printElement(const Element*const);
static void    shift(ArrayList *const list, int index, int rooms, Shift dir);
static void    wide(ArrayList* const);

#endif // ARRAYLIST_H
