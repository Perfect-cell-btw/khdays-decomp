/* Twin of Ov008_FindListObjectByKey_2 for the linked list at param_1+0x548. */
extern void *Ov008_FindNextMissionEntry(void *list, void *obj);

void *Ov008_MissionMenu_FindEntry(int param_1, int param_2) {
    void *obj = Ov008_FindNextMissionEntry((void *)(param_1 + 0x548), 0);
    while (obj != 0) {
        if (*(unsigned short *)obj == param_2) {
            return obj;
        }
        obj = Ov008_FindNextMissionEntry((void *)(param_1 + 0x548), obj);
    }
    return obj;
}
