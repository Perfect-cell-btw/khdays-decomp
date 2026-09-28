/* Append one option's entries to the caller's list, optionally after the shared defaults.
 *
 * The record comes from the table at 0x1b4 of the scene context, selected by index. The defaults
 * are a fixed halfword table passed by address, and they only go in when the caller asks. The
 * limit is handed to both appends unchanged.
 *
 * The context is bound before the guard, not inside it, which is what the original does.
 */

extern char *data_ov002_0207f62c[];
extern short data_ov002_0207ed1c[];
extern void Ov002_AppendU16List(short *out, short *source, int limit);
extern short *Ov002_GetVarRecordByIndex(char *table, unsigned int index);

void Ov002_AppendOptionEntries(short *out, unsigned int index, int withDefaults, int limit) {
    char *ctx = data_ov002_0207f62c[1];

    if (withDefaults != 0) {
        Ov002_AppendU16List(out, data_ov002_0207ed1c, limit);
    }
    Ov002_AppendU16List(out, Ov002_GetVarRecordByIndex(ctx + 0x1b4, index), limit);
}
