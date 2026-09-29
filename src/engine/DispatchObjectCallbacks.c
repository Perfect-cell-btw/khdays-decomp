/* Runs an object's draw callbacks: the render callback (+0x6c) and the per-owner callback (+0x74)
 * with its owner, unless the object is hidden (bit 1 of +0x5c). */

struct flags_5c { int b0:1; int b1:1; };

void DispatchObjectCallbacks(void *pThis_, int arg1) {
    int this_ = (int)pThis_;
    if (((struct flags_5c *)(this_ + 0x5c))->b1) {
        return;
    }
    {
        void (*cb6c)(int, int) = *(void (**)(int, int))(this_ + 0x6c);
        if (cb6c != 0) {
            cb6c(this_, arg1);
        }
    }
    {
        void (*cb74)(int, int) = *(void (**)(int, int))(this_ + 0x74);
        if (cb74 == 0) {
            return;
        }
        cb74(this_, *(int *)(this_ + 0x84));
    }
}
