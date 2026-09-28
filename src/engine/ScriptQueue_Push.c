/* Pushes a record (kind, arg, value) at the tail of the 4-slot ring buffer at base+0xb47a2 (head
 * byte +0xb47b2, count byte +0xb47b3); the counterpart of SoundMgr_PopQueued. */
extern char *data_0204c234;

typedef struct {
    unsigned char kind;
    unsigned char arg;
    unsigned short value;
} QueueRec;

void ScriptQueue_Push(unsigned char kind, unsigned char arg, unsigned short value)
{
    char *base = data_0204c234;
    int slot = (*(unsigned char *)(base + 0xb47b2) + *(unsigned char *)(base + 0xb47b3)) % 4;
    QueueRec *rec = (QueueRec *)(base + 0xb47a2) + slot;

    rec->kind = kind;
    rec->arg = arg;
    rec->value = value;
    *(unsigned char *)(base + 0xb47b3) = *(unsigned char *)(base + 0xb47b3) + 1;
}
