/* (Codex) walks the NNS list at obj+0x18 from param2 via NNS_FndGetNextListObject, returning the
 * first object whose word at +0x10 is 0 (or 0 if none). */

extern void *NNS_FndGetNextListObject(void *list, void *object);

void *Ov302_FindListObjectWithField10Zero(int this_, void *object) {
    object = NNS_FndGetNextListObject((void *)(this_ + 0x18), object);

    while (object != 0) {
        if (*(int *)((char *)object + 0x10) == 0) break;
        object = NNS_FndGetNextListObject((void *)(this_ + 0x18), object);
    }

    return object;
}
