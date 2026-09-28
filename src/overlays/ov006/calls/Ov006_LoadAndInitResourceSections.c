/* Load resource buffer (Archive_LoadFile(param2, 0xe)); its 3-word header holds byte
 * offsets to three sub-sections. Dispatch each section (buf + offset) to its init
 * handler, then free the buffer. Offsets read up front (captured before the calls
 * can touch the buffer). */
extern int Archive_LoadFile(int param2, int type);
extern void Ov006_LoadLayoutResources(int ctx, int section);
extern void Ov006_LoadElemsFromLayout(int ctx, int section);
extern void Ov006_BuildLayoutFromTagTable(int ctx, int section);
extern void NNSi_FndFreeFromDefaultHeap(int ptr);
void Ov006_LoadAndInitResourceSections(int ctx, int param2) {
    int *buf = (int *)Archive_LoadFile(param2, 0xe);
    int a = buf[0], c = buf[2], b = buf[1];
    Ov006_LoadLayoutResources(ctx, (int)buf + a);
    Ov006_LoadElemsFromLayout(ctx, (int)buf + b);
    Ov006_BuildLayoutFromTagTable(ctx, (int)buf + c);
    if (buf != 0) {
        NNSi_FndFreeFromDefaultHeap((int)buf);
    }
}
