/* Drops a model's texture image from main memory: the archive block of the model's resource
 * (+0x74) is shrunk to end where its texture image starts (ForwardType7RecordSpan). */

extern int ForwardType7RecordSpan();

int Model_DropTextureImage(int model) {
    int p = *(int *)(model + 0x74);
    return ForwardType7RecordSpan(*(int *)(p + 0xc), *(int *)(p + 8), *(unsigned short *)(p + 6));
}
