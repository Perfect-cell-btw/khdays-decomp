/* The stream's current 64-bit timestamp, or 0 when there is no stream. Both
 * halves are read separately and both are zeroed on the null path, which is what
 * a predicated long long return looks like. */

#include "game/engine.h"

typedef struct {
    char pad0000[0x464];
    unsigned long long qwTimestamp; /* +0x464 */
} Ov022Stream;

unsigned long long Ov022_GetStreamTimestamp(int idx) {
    Ov022Stream *stream = (Ov022Stream *)GetEntryField20ByIndex(idx);

    if (stream == 0) {
        return 0;
    }

    return stream->qwTimestamp;
}
