extern void Ov107_AiState_PostTickBase();

void Ov239_MaybeForceSubState7ThenAdvance(int this_) {
    if ((*(unsigned char *)(this_ + 0x1c4) & 0xa) &&
        *(signed char *)(this_ + 0x1c6) != 0 &&
        *(signed char *)(this_ + 0x1c6) != 1 &&
        *(signed char *)(this_ + 0x1c6) != 3 &&
        *(signed char *)(this_ + 0x1c6) != 7) {
        *(signed char *)(this_ + 0x1c7) = 7;
    }
    Ov107_AiState_PostTickBase(this_);
}
