extern void *NNS_FndGetNextListObject(void *list, void *object);

void *Ov302_FindListObjectWithField10Zero(int this_, void *object) {
    object = NNS_FndGetNextListObject((void *)(this_ + 0x18), object);

    while (object != 0) {
        if (*(int *)((char *)object + 0x10) == 0) break;
        object = NNS_FndGetNextListObject((void *)(this_ + 0x18), object);
    }

    return object;
}
