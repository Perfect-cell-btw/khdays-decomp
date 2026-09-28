/* Empties the actor's point list at +0x394 and refills it from the caller's table: nBytes / 12
 * entries of three words each, appended one at a time. The ov287, ov288 and ov289 siblings are the
 * same routine at +0x398, and they skip a leading word that this one does not have. One source fact
 * is load-bearing: the quotient is written back over the size parameter rather than into a new
 * local, which is what puts it in the same register and forces the copy the umull's operand
 * constraint needs. */

struct v3 { int a, b, c; };
extern void NNSi_FndDestroyDoubleList(void *p);
extern void List_Init(void *p);
extern void *List_InsertSorted(int a, int b, int c);
void Ov292_ReloadPointList(int obj, int size, int *entries) {
    struct v3 *src;
    int i;
    src = (struct v3 *)entries;
    NNSi_FndDestroyDoubleList((void *)(obj + 0x394));
    List_Init((void *)(obj + 0x394));
    size = (int)((unsigned int)size / 12);
    for (i = 0; i < size; i++) {
        struct v3 *slot = (struct v3 *)List_InsertSorted(obj + 0x394, 0xc, 0x64);
        *slot = *src;
        src++;
    }
}
