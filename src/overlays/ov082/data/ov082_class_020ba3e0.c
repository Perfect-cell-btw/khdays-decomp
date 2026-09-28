/* ov082 class descriptor data_ov082_020ba3e0, 0x020ba3e0-0x020ba3f4 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b8114, method 020b8194, 0x3a60-byte state.
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

extern void Ov082_InitSubsystemAndReturnTick(void);
extern void Ov082_ShutdownAndFree(void);

GameClassDescriptor data_ov082_020ba3e0 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov082_InitSubsystemAndReturnTick,  /* pfnCtor */
    Ov082_ShutdownAndFree,  /* pfnMethod */
    14944,  /* nAuxSize */
    0,  /* pArena */
};
