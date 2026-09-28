/* Applies the message by its mode (store params mode 0-3) or marks none pending; clears the timer.
 */

extern int InitNodeAndStoreParamsMode1(int, int, int, int, int);
extern int InitNodeAndStoreParamsMode2(int, int, int, int, int);
extern int Record_InitMode2(int, int, int, int);
extern int InitNodeAndStoreParams(int, int, int, int, int, int, int);

typedef struct {
    unsigned short field_00;
    unsigned short field_02;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
} Msg;

typedef struct {
    int field_00;
    char pad_04[0x10c];
    char sub_110[0x48];
    int field_158;
} Obj;

int Actor_ApplyMessage(Obj *this_, Msg *msg) {
    if (msg != 0) {
        this_->field_00 |= msg->field_00;
        switch (msg->field_00 & 3) {
        case 0:
            InitNodeAndStoreParamsMode1((int)this_->sub_110, msg->field_02, (int)this_, msg->field_08, msg->field_04);
            break;
        case 1:
            InitNodeAndStoreParamsMode2((int)this_->sub_110, msg->field_02, (int)this_, msg->field_08, msg->field_04);
            break;
        case 2:
            Record_InitMode2((int)this_->sub_110, msg->field_02, (int)this_, msg->field_08);
            break;
        case 3:
            InitNodeAndStoreParams((int)this_->sub_110, msg->field_02, (int)this_, msg->field_08, msg->field_04, msg->field_0c, msg->field_10);
            break;
        }
        this_->field_00 &= ~0x10;
    } else {
        this_->field_00 |= 0x10;
    }
    this_->field_158 = 0;
    return 1;
}
