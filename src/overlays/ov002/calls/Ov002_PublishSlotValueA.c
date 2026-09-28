/* Publish the value into the active slot of the 0x14-stride table, notifying
 * Ov002_SwapActivePairIfActive first when the caller asks for it. The slot index lives at
 * +4 of the context at data_ov002_0207f99c. */
typedef struct {
    int nValue;
    char pad04[0x10];
} Ov002TableSlot;

extern void Ov002_SwapActivePairIfActive(int value, int notify);

extern int data_ov002_0207f99c;
extern Ov002TableSlot data_ov002_0207f9a8[];

void Ov002_PublishSlotValueA(int value, int notify) {
    int ctx = data_ov002_0207f99c;

    if (notify != 0) {
        Ov002_SwapActivePairIfActive(value, notify);
    }

    data_ov002_0207f9a8[*(int *)(ctx + 4)].nValue = value;
}
