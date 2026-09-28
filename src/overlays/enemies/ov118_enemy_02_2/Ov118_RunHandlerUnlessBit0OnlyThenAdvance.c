extern void Ov118_UnlinkHeldNode();
extern void Ov107_AiState_PostTickBase();

struct hw60 { unsigned short lo : 8, hi : 8; };

void Ov118_RunHandlerUnlessBit0OnlyThenAdvance(int this_) {
    unsigned int lo = ((struct hw60 *)(this_ + 0x60))->lo;
    if ((lo & 0x80) || !(lo & 1)) {
        Ov118_UnlinkHeldNode(this_);
    }
    Ov107_AiState_PostTickBase(this_);
}
