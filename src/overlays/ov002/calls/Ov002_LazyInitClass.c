extern int InstantiateClass(int desc, int arg);
extern char data_ov002_0207fa18[];
extern char data_ov002_0207f40c[];
/* Lazily instantiate the subsystem's class (descriptor data_0207f40c) into the slot at
 * data_0207fa18+4. */
void Ov002_LazyInitClass(void) {
    if (*(int *)(data_ov002_0207fa18 + 4) == 0) {
        *(int *)(data_ov002_0207fa18 + 4) = InstantiateClass((int)data_ov002_0207f40c, 0);
    }
}
