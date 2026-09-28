/* Swallows a queued message or lets it through. A message repeating the page's current id is
 * dropped, and so are the four terminal ids 0x13, 0x14, 0x15 and 0x1b; dropping clears the caller's
 * slot and reports handled. Everything else goes to the shared dispatcher and returns whatever it
 * says. */

#pragma opt_propagation off

#include "nitro/types.h"

typedef struct {
    u16 type;
    u16 id;
} Ov025Message;

typedef struct {
    u8 pad_0000[0x209c];
    u32 currentMessageId;
} Ov025Page;

extern Ov025Page *Ov008_GetMenuContext(void);
extern int DispatchByNodeKind(Ov025Message **messageSlot);

int Ov008_FilterIncomingMessage(Ov025Message **messageSlot) {
    Ov025Page *page = Ov008_GetMenuContext();
    unsigned int id = (*messageSlot)->id;
    int handled = 1;

    if (id == page->currentMessageId) {
        *messageSlot = 0;
        return handled;
    }

    switch (id) {
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1b:
        *messageSlot = 0;
        return handled;
    }

    return DispatchByNodeKind(messageSlot);
}

