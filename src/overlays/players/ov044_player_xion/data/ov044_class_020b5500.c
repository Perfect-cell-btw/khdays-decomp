/* ov044 class descriptor data_ov044_020b5500, 0x020b5500-0x020b5514 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 020b3234, method 020b32b4, 0x3a60-byte state.
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

extern void Ov044_InitSubsystemAndReturnTick(void);
extern void Ov044_ShutdownAndFree(void);

GameClassDescriptor data_ov044_020b5500 = {
    10,  /* nClassId */
    6,  /* nGroupId */
    Ov044_InitSubsystemAndReturnTick,  /* pfnCtor */
    Ov044_ShutdownAndFree,  /* pfnMethod */
    14944,  /* nAuxSize */
    0,  /* pArena */
};
