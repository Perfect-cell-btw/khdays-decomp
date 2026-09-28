/* ov096 class descriptor data_ov096_020bc014, 0x020bc014-0x020bc028 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020ba7d4, method 020ba7fc, 0x2f90-byte state.
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

extern void Ov096_stateCtorReturnHandler(void);
extern void Ov096_setupTriple(void);

GameClassDescriptor data_ov096_020bc014 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov096_stateCtorReturnHandler,  /* pfnCtor */
    Ov096_setupTriple,  /* pfnMethod */
    12176,  /* nAuxSize */
    0,  /* pArena */
};
