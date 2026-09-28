/* ov023 class descriptor data_ov023_0208a004, 0x0208a004-0x0208a018 (.data).
 *
 * InstantiateClass (02023930 / 02023960) builds a task object from it: the
 * u16 class / group ids, the constructor whose return is the first state
 * function, the method slot, the size of the zero-filled auxiliary block and
 * the arena reference.  Constructor 02082960, method 020829c4, 0x8-byte state.
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

extern void Ov023_SceneEnter(void);
extern void Ov023_SceneLeave(void);

GameClassDescriptor data_ov023_0208a004 = {
    8,  /* nClassId */
    13,  /* nGroupId */
    Ov023_SceneEnter,  /* pfnCtor */
    Ov023_SceneLeave,  /* pfnMethod */
    8,  /* nAuxSize */
    0,  /* pArena */
};
