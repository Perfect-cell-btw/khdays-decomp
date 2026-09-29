/* Returns the session setup block (data_020429b8: state, player slot count, key, member mask),
 * stored by Session_StoreSetup. */

extern int data_020429b8;

int Session_GetSetup(void) {
    return (int)&data_020429b8;
}
