typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Ov002Entry Ov002Entry;
typedef int (*Ov002EntryCallback)(Ov002Entry *entry);

typedef struct {
    unsigned char pad0000[0x24];
    Ov002EntryCallback pOnActive;
} Ov002EntryOwner;

struct Ov002Entry {
    unsigned char pad0000[8];
    Ov002EntryOwner *pOwner;
    unsigned char pad000c[8];
    u16 wKey;
    u8 bKind;
};

extern int GameState_GetField(u16 key, u8 kind);

int Ov002_TriggerEntryActive(Ov002Entry *self)
{
    int eligible;

    if ((GameState_GetField(self->wKey, self->bKind) & 1) != 0) {
        eligible = 1;
    } else {
        eligible = 0;
    }

    if (eligible != 0 && self->pOwner->pOnActive != 0) {
        return self->pOwner->pOnActive(self);
    }

    return 0;
}
