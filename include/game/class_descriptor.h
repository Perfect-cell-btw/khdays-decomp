/* The class descriptors the object system instantiates from (InstantiateClass): every scene task,
 * entity class and helper object is created from one of these rows. */
#ifndef GAME_CLASS_DESCRIPTOR_H
#define GAME_CLASS_DESCRIPTOR_H

#include "nitro/types.h"

typedef void (*GameClassFn)(void);

typedef struct GameClassDescriptor {
    u16 nClassId;                   /* 0x00 */
    u16 nGroupId;                   /* 0x02 */
    GameClassFn pfnCtor;            /* 0x04: returns the object's first state function */
    GameClassFn pfnMethod;          /* 0x08: stored in the object (+0x18) */
    int nAuxSize;                   /* 0x0c: size of the zero-filled state block */
    int *pArena;                    /* 0x10: the heap arena the object is allocated from */
} GameClassDescriptor;

#endif
