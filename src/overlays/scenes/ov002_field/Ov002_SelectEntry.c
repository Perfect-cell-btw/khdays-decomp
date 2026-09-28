/* Raise the given entry's bit in the panel's selection mask at +0x52. The entry
 * id has to be resolved to a bit index first, and an id the panel does not hold
 * resolves to -1, which is dropped silently. */
extern int Ov002_ItemIdToSlot(int id);

typedef struct {
    char pad0000[0x52];
    unsigned char bSelectionMask;   /* +0x52, bit per resolved entry index */
} Ov002PanelSelection;

extern Ov002PanelSelection *data_ov002_0207f60c;

void Ov002_SelectEntry(int id) {
    Ov002PanelSelection *panel = data_ov002_0207f60c;
    int bit;

    if (panel == 0) {
        return;
    }

    bit = Ov002_ItemIdToSlot(id);
    if (bit == -1) {
        return;
    }

    panel->bSelectionMask |= 1 << bit;
}
