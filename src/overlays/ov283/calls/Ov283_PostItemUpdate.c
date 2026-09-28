extern int Ov107_BuildAndSendUpdate();

void Ov283_PostItemUpdate(int param1, int param2, int param3, int param4)
{
    int type;

    if (*(int *)(param1 + 0x3e4) != 0) {
        switch (param3) {
        case 0: type = 0; break;
        case 1: type = 1; break;
        case 2: type = 2; break;
        case 3: type = 3; break;
        case 4: type = 4; break;
        case 5: type = 5; break;
        case 6: type = 6; break;
        case 12: type = 7; break;
        default: return;
        }
        Ov107_BuildAndSendUpdate(param1, 0x17e, type, param4);
    } else {
        Ov107_BuildAndSendUpdate(param1, 0x173, param3, param4);
    }
}
