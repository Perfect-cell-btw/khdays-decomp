/* Look up `i` in the table at +0x859c of the context at data_ov002_0207fa00, via
 * ParseSlotQuantityId. */

extern int data_ov002_0207fa00;
extern int ParseSlotQuantityId();

int Ov002_LookupChannelEntry(int arg0) {
    return ParseSlotQuantityId(*(int *)&data_ov002_0207fa00 + 0x859c, arg0);
}
