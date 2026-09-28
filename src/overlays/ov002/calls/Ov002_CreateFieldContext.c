extern void LoadActorOverlay(void);
extern int Ov107_InstantiateFieldClass(int size, int a);
extern char *func_ov107_020c9848(void);
extern void Ov002_SetCurrentSlotFlag1(int a);
extern int Ov002_GetRootField8d94(void);
extern void Ov002_Camera_SetMode(void);
extern void Ov002_SetValueAndDerive(void);
extern char *data_ov002_0207fa14;

/* Creates the field's render context the first time round -- a negative size means "use the
 * default 0x57800" -- wires its two callbacks and republishes the camera and the active map.
 * `self` is advanced to the camera field on purpose: that is the ROM's `adds r4, #0x98`. */
void Ov002_CreateFieldContext(int size) {
    char *self = data_ov002_0207fa14;
    if (size < 0) {
        size = 0x57800;
    }
    if (*(int *)(self + 0x18) == -1) {
        char *scene;
        int map;
        LoadActorOverlay();
        *(int *)(self + 0x18) = Ov107_InstantiateFieldClass(size, 0);
        *(void **)(func_ov107_020c9848() + 0x74) = (void *)&Ov002_Camera_SetMode;
        *(void **)(func_ov107_020c9848() + 0x78) = (void *)&Ov002_SetValueAndDerive;
        Ov002_SetCurrentSlotFlag1(0);
        scene = *(char **)func_ov107_020c9848();
        self += 0x98;
        *(int *)(scene + 0xa8) = *(int *)self;
        map = Ov002_GetRootField8d94();
        *(int *)(func_ov107_020c9848() + 0x8c) = map;
    }
}
