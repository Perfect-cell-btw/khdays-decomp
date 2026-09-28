/* Reference-count a message database: if slot `id` is not yet loaded, load it (font 0xe); on any
 * success bump the slot's ref count. Returns the load result (1 when already resident). */
extern int MsgDb_LoadDb(unsigned int id, int font, int one, int arg);  /* MsgDb_LoadDb */

struct MsgDbHost {
    char _pad[0x96bc];
    int aRefCount[1];                   /* +0x96bc, indexed by id */
};
extern struct MsgDbHost *data_ov025_020b5744[2];

int Ov025_AcquireMsgDb(unsigned int id, int p2, int p3, int arg) {
    int result = 1;
    if (data_ov025_020b5744[1]->aRefCount[id] == 0) {
        result = MsgDb_LoadDb(id, 0xe, 1, arg);
    }
    if (result != 0) {
        data_ov025_020b5744[1]->aRefCount[id] += 1;
    }
    return result;
}
