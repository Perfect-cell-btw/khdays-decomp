/* ov075 class descriptor data_ov075_020b9d20, 0x020b9d20-0x020b9d34 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b8148, 0x30c0-byte state.
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

extern void Ov075_stateCtorMultiInitReturnHandler(void);
extern void Ov075_stateDtorCleanupMulti(void);

GameClassDescriptor data_ov075_020b9d20 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov075_stateCtorMultiInitReturnHandler,  /* pfnCtor */
    Ov075_stateDtorCleanupMulti,  /* pfnMethod */
    12480,  /* nAuxSize */
    0,  /* pArena */
};
