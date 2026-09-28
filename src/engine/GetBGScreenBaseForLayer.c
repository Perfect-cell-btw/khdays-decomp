/* Returns the screen base of a background layer through the layer's callback in the table, or 0
 * when it has none. */

extern char data_02041fd4[];

int GetBGScreenBaseForLayer(int index) {
    int (*callback)(void) = *(int (**)(void))(data_02041fd4 + index * 0x18);

    if (callback == 0) {
        return 0;
    }

    return callback();
}
