/* Returns the session's link mode (*data_0204c228): 1 = local (sent messages are copied into the
 * local slots), 2 and 3 = the two wireless modes. It sizes the packet slots and picks how messages
 * are sent. */

extern int *data_0204c228;

int Session_GetLinkMode(void) {
    return *data_0204c228;
}
