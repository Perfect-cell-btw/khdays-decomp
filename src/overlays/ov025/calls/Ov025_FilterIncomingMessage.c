#pragma opt_propagation off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 type;
    u16 id;
} Ov025Message;

typedef struct {
    u8 pad_0000[0x209c];
    u32 currentMessageId;
} Ov025Page;

extern Ov025Page *Ov025_GetPageA(void);
extern int DispatchByNodeKind(Ov025Message **messageSlot);

int Ov025_FilterIncomingMessage(Ov025Message **messageSlot) {
    Ov025Page *page = Ov025_GetPageA();
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

