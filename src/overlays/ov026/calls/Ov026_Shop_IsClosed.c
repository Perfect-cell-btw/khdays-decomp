/* Report whether the ov026 global pointer is null. */
extern int data_ov026_02091368;
int Ov026_Shop_IsClosed(void) {
    return data_ov026_02091368 == 0;
}
