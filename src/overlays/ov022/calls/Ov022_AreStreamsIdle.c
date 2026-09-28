/* Are all the loaded streams idle? A stream whose state byte at +2 is non-zero
 * is still busy. With nothing loaded the answer is yes.
 *
 * The loop guard is `i < count`, not `count > 0` -- see Ov022_CloseAllStreams. */
int Ov022_AreStreamsIdle(int self) {
    int idle = 1;
    int i;
    int e;

    if (*(unsigned char *)(self + 0x19) == 0) {
        return 1;
    }

    i = 0;

    if (i < *(unsigned char *)(self + 0x19)) {
        int *stream = (int *)(*(int *)(self + 0xc));

        do {
            if (*(signed char *)((char *)stream + 2) != 0) {
                idle = 0;
                break;
            }

            i++;
            stream = (int *)((char *)stream + 0x1c8);
        } while (i < *(unsigned char *)(self + 0x19));
    }

    return idle;
}
