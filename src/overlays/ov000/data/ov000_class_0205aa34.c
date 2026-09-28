/* ov000 class descriptor data_ov000_0205aa34, 0x0205aa34-0x0205aa48 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02051c48, method 02051f94, 0x6a64-byte state.
 */

typedef void (*GameClassFn)(void);

typedef struct GameClassDescriptor {
    unsigned short nClassId;  /* 0x00 */
    unsigned short nGroupId;  /* 0x02 */
    GameClassFn pfnCtor;      /* 0x04: returns the object's first state fn */
    GameClassFn pfnMethod;    /* 0x08 */
    int nAuxSize;             /* 0x0c: zero-filled state block */
    int *pArena;              /* 0x10 */
} GameClassDescriptor;

extern void Ov000_LoadScreenInit(void);
extern void Ov000_DestroyScene(void);

GameClassDescriptor data_ov000_0205aa34 = {
    8,  /* nClassId */
    14,  /* nGroupId */
    Ov000_LoadScreenInit,  /* pfnCtor */
    Ov000_DestroyScene,  /* pfnMethod */
    27236,  /* nAuxSize */
    0,  /* pArena */
};
