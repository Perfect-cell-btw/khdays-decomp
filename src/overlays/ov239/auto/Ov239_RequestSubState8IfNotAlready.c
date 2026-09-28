struct actor_substate { signed char _pad[0x1c6]; signed char cur; signed char req; };

int Ov239_RequestSubState8IfNotAlready(int this_) {
    int state = **(int **)(this_ + 0x214);
    if (((struct actor_substate *)state)->cur != 8) {
        ((struct actor_substate *)state)->req = 8;
        return 1;
    }
    return 0;
}
