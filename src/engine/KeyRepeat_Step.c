/* Updates key auto-repeat (KeyRepeat_Update) and returns 1. */
extern void KeyRepeat_Update(void *p);

int KeyRepeat_Step(void *p) {
    KeyRepeat_Update(p);
    return 1;
}
