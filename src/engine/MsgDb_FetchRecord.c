/* MsgDb dispatcher: route by database id (db) to the per-database record decoder.
 * db 0..0x12 share one generic decoder (MsgDb_DecodeGenericRecord handles that whole range
 * itself, keyed on db). db 0x17 and 0x18 share a decoder that also needs the
 * raw db value as a fourth argument. Every other db in range 0..0x20 has its
 * own one-database decoder taking just (rec_out, index, keep). Any db above
 * 0x20 fails outright. Case-body order (0x15,0x16,0x13,0x19,0x1a,0x1b,0x1c,
 * 0x14,0x1d,0x1e,0x1f,0x20,0x17/0x18,0..0x12) is the ROM's own source order,
 * confirmed against the jump table's raw offsets, not value-sorted. */
extern int MsgDb_LoadRecord15(int *rec_out, unsigned int index, int keep);
extern int MsgDb_DecodeDb16(int *rec_out, int value, int keep);
extern int MsgDb_DecodeDb13(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb19(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb1A(int *rec_out, int index, int keep);
extern int MsgDb_FetchEntryPair0x1b(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb1C(int *rec_out, unsigned int index, int keep);
extern int MsgDb_DecodeDb14(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb1D(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb1E(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb1F(int *rec_out, int index, int keep);
extern int MsgDb_DecodeDb20(int *rec_out, int index, int keep);
extern int MsgDb_BuildEntryRecord(int *rec_out, unsigned int index, int keep, int db);
extern int MsgDb_DecodeGenericRecord(int *param_1, int param_2, unsigned int param_3, int param_4);

int MsgDb_FetchRecord(void *pRec_out, int db, unsigned int index, int keep) {
    int *rec_out = (int *)pRec_out;
    switch (db) {
    case 0x15:
        return MsgDb_LoadRecord15(rec_out, index, keep);
    case 0x16:
        return MsgDb_DecodeDb16(rec_out, index, keep);
    case 0x13:
        return MsgDb_DecodeDb13(rec_out, index, keep);
    case 0x19:
        return MsgDb_DecodeDb19(rec_out, index, keep);
    case 0x1a:
        return MsgDb_DecodeDb1A(rec_out, index, keep);
    case 0x1b:
        return MsgDb_FetchEntryPair0x1b(rec_out, index, keep);
    case 0x1c:
        return MsgDb_DecodeDb1C(rec_out, index, keep);
    case 0x14:
        return MsgDb_DecodeDb14(rec_out, index, keep);
    case 0x1d:
        return MsgDb_DecodeDb1D(rec_out, index, keep);
    case 0x1e:
        return MsgDb_DecodeDb1E(rec_out, index, keep);
    case 0x1f:
        return MsgDb_DecodeDb1F(rec_out, index, keep);
    case 0x20:
        return MsgDb_DecodeDb20(rec_out, index, keep);
    case 0x17:
    case 0x18:
        return MsgDb_BuildEntryRecord(rec_out, index, keep, db);
    case 0x0: case 0x1: case 0x2: case 0x3: case 0x4: case 0x5: case 0x6: case 0x7:
    case 0x8: case 0x9: case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf:
    case 0x10: case 0x11: case 0x12:
        return MsgDb_DecodeGenericRecord(rec_out, db, index, keep);
    default:
        return 0;
    }
}
