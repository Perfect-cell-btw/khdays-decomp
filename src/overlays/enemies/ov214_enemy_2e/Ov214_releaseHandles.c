extern void TaskList_FinishByTag(void *a, int b);
extern void Ov107_UnlinkNodeFromOwner(void *p);

void Ov214_releaseHandles(char *this) {
    if (*(int *)(this + 0x454) != 0) {
        TaskList_FinishByTag(*(void **)(this + 0x3c), *(int *)(this + 0x454));
        *(int *)(this + 0x454) = 0;
    }
    if (*(int *)(this + 0x464) != 0) {
        TaskList_FinishByTag(*(void **)(this + 0x3c), *(int *)(this + 0x464));
        *(int *)(this + 0x464) = 0;
    }
    {
        void *p = *(void **)(this + 0x43c);
        if (p != 0) {
            Ov107_UnlinkNodeFromOwner(p);
            *(int *)(this + 0x43c) = 0;
        }
    }
}
