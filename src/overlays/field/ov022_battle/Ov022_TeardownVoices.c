/* Tear down the four voice slots -- the 0x108-byte streams from +0x20 and the
 * 0x24-byte mixers from +0x440 -- then clear the loaded flag. The flag is
 * cleared whether or not the slots were live. */

#include "game/engine.h"

void Ov022_TeardownVoices(unsigned char *self) {
    char *stream;
    char *mixer;
    int i;

    if ((*self & 1) != 0) {
        i = 0;
        stream = (char *)self + 0x20;
        mixer = (char *)self + 0x440;

        for (; i < 4; i++) {
            ReleaseField74AndCleanup(stream);
            FreeAllResourceTables(mixer);
            stream += 0x108;
            mixer += 0x24;
        }
    }

    *self = 0;
}
