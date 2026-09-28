/* Parks the element as a spare entry. */

extern void Ov002_ParkSpareEntry(void *obj);

void Ov017_ForwardToHandler(void *obj) {
    Ov002_ParkSpareEntry(obj);
}
