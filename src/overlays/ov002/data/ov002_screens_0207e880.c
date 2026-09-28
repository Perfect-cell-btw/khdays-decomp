/* ov002 screen descriptors, 0x0207e880-0x0207e8a8.
 *
 * 2 records of the shape Ov002_OpenPanelScreen takes: a class id whose high half
 * selects the group and whose low half is the index, the pair of handlers, the work
 * size the screen needs, and a word that is zero in every record.
 */

typedef void (*Ov002ScreenFn)(void);

typedef struct {
    unsigned int nClassId;
    Ov002ScreenFn pfnOpen;
    Ov002ScreenFn pfnClose;
    int nWorkSize;
    int nReserved;
} Ov002ScreenDesc;

extern void Ov002_EnterListPairScene(void);
extern void Ov002_DrainLoadQueue(void);
extern void Ov002_CreateUiContext(void);
extern void Ov002_DestroyUiContext(void);

Ov002ScreenDesc data_ov002_0207e880 = {
    0x0e003e, Ov002_EnterListPairScene, Ov002_DrainLoadQueue, 24, 0,
};

Ov002ScreenDesc data_ov002_0207e894 = {
    0x0e003b, Ov002_CreateUiContext, Ov002_DestroyUiContext, 296, 0,
};
