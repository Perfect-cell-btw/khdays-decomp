/* D-pad focus navigation. Walks the focused node's neighbour links until it finds one that is
 * neither disabled nor unfocusable, then moves focus there and records which direction was used.
 * The key bits are the NitroSDK d-pad set and the links are in that order: 0x40 up -> +0x88, 0x80
 * down -> +0x8c, 0x20 left -> +0x90, 0x10 right -> +0x94. A candidate is rejected when its group id
 * at +0xc equals the current node's or the focused node's, which is what stops the walk wrapping
 * within a group. The direction mask at +0x4a78 gates all four: it is reset to 0xf0 whenever it no
 * longer intersects data_0204c18c, and then narrowed to the single direction actually taken -- so a
 * held d-pad keeps repeating in one axis instead of drifting. */

typedef struct {
    unsigned disabled : 1;
    unsigned focusable : 1;
} NodeFlags;

typedef struct {
    char reserved[0x4a50];
    void (*handler)(int, int);   /* +0x4a50 */
    char reserved2[0x1c];
    int focused;                 /* +0x4a70 */
    char reserved3[0x4];
    unsigned short dirs;         /* +0x4a78 */
} Root;

extern void Ov008_SwapParamOverrides(Root *self, int node);
extern unsigned short data_0204c18c;

void Ov008_MoveFocusByDpad(Root *self, int keys)
{
    int cur;
    int n;
    unsigned short dirs;
    void (*cb)(int);

    cur = self->focused;

    if (cur == 0) {
        return;
    }

    if ((data_0204c18c & self->dirs) == 0) {
        self->dirs = 0xf0;
    }

    dirs = self->dirs;

    if ((keys & 0x40) & dirs) {
        n = *(int *)(cur + 0x88);

        if (n == 0) {
            goto tail;
        }

        for (;;) {
            if (*(int *)(n + 0xc) == *(int *)(cur + 0xc) ||
                *(int *)(n + 0xc) == *(int *)(self->focused + 0xc)) {
                goto tail;
            }

            if (!((NodeFlags *)(n + 0x84))->disabled &&
                ((NodeFlags *)(n + 0x84))->focusable) {
                Ov008_SwapParamOverrides(self, n);
                self->dirs = 0x40;
                goto tail;
            }

            cur = n;
            n = *(int *)(n + 0x88);

            if (n == 0) {
                goto tail;
            }
        }
    }

    if ((keys & 0x80) & dirs) {
        n = *(int *)(cur + 0x8c);

        if (n == 0) {
            goto tail;
        }

        for (;;) {
            if (*(int *)(n + 0xc) == *(int *)(cur + 0xc) ||
                *(int *)(n + 0xc) == *(int *)(self->focused + 0xc)) {
                goto tail;
            }

            if (!((NodeFlags *)(n + 0x84))->disabled &&
                ((NodeFlags *)(n + 0x84))->focusable) {
                Ov008_SwapParamOverrides(self, n);
                self->dirs = 0x80;
                goto tail;
            }

            cur = n;
            n = *(int *)(n + 0x8c);

            if (n == 0) {
                goto tail;
            }
        }
    }

    if ((keys & 0x20) & dirs) {
        n = *(int *)(cur + 0x90);

        if (n == 0) {
            goto tail;
        }

        for (;;) {
            if (*(int *)(n + 0xc) == *(int *)(cur + 0xc) ||
                *(int *)(n + 0xc) == *(int *)(self->focused + 0xc)) {
                goto tail;
            }

            if (!((NodeFlags *)(n + 0x84))->disabled &&
                ((NodeFlags *)(n + 0x84))->focusable) {
                Ov008_SwapParamOverrides(self, n);
                self->dirs = 0x20;
                goto tail;
            }

            cur = n;
            n = *(int *)(n + 0x90);

            if (n == 0) {
                goto tail;
            }
        }
    }

    if ((keys & 0x10) & dirs) {
        n = *(int *)(cur + 0x94);

        if (n == 0) {
            goto tail;
        }

        for (;;) {
            if (*(int *)(n + 0xc) == *(int *)(cur + 0xc) ||
                *(int *)(n + 0xc) == *(int *)(self->focused + 0xc)) {
                goto tail;
            }

            if (!((NodeFlags *)(n + 0x84))->disabled &&
                ((NodeFlags *)(n + 0x84))->focusable) {
                Ov008_SwapParamOverrides(self, n);
                self->dirs = 0x10;
                goto tail;
            }

            cur = n;
            n = *(int *)(n + 0x94);

            if (n == 0) {
                goto tail;
            }
        }
    }

    if ((keys & 1) && (cb = *(void (**)(int))(cur + 0x98)) != 0) {
        cb(self->focused);
    }

tail:
    if (self->handler == 0) {
        return;
    }

    if ((keys & 0x2fff) == 0) {
        return;
    }

    self->handler(self->focused, keys);
}
