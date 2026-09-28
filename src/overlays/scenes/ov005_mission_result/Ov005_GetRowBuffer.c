/* Returns the row buffer for a buffer handle (and its index), or NULL. */

typedef struct Ov005Context {char pad0[0x4be4];void *rowBuffers[3];} Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern int Ov005_GetRowBufferIndex(int);
void *Ov005_GetRowBuffer(int entryId,int *outIndex) {
    int index=Ov005_GetRowBufferIndex(entryId);
    void *buffer=0;
    if(index!=-1)buffer=data_ov005_0205b80c->rowBuffers[index];
    if(outIndex)*outIndex=index;
    return buffer;
}
