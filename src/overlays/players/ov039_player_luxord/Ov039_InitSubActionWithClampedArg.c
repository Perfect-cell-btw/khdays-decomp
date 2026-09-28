extern void BindAnimTrack();
extern void Anim_SetFrameWrapped();

void Ov039_InitSubActionWithClampedArg(int this_, int arg1) {
    *(unsigned char *)(this_ + 1) = 1;
    BindAnimTrack(this_ + 4, 2, this_ + 0xe4, (short)arg1);
    Anim_SetFrameWrapped(this_ + 4, 2, 0);
}
