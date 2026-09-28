/* Returns the number of objects in the object's list. */

extern void *NNS_FndGetNextListObject(void *list, void *object);

int Ov008_CountListNodes(void *object)
{
    int count = 0;
    void *entry = NNS_FndGetNextListObject((char *)object + 0x20, 0);

    while (entry != 0) {
        count++;
        entry = NNS_FndGetNextListObject((char *)object + 0x20, entry);
    }

    return count;
}
