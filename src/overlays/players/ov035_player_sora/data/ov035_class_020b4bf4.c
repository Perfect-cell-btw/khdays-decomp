/* ov035 class descriptor data_ov035_020b4bf4, 0x020b4bf4-0x020b4c08 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b3264, 0x2e1c-byte state.
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

extern void Ov035_stateCtorCondConfigReturnHandler(void);
extern void Ov035_initRegionCondClearGlobal(void);

GameClassDescriptor data_ov035_020b4bf4 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov035_stateCtorCondConfigReturnHandler,  /* pfnCtor */
    Ov035_initRegionCondClearGlobal,  /* pfnMethod */
    11804,  /* nAuxSize */
    0,  /* pArena */
};
