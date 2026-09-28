/* When the party is active and valid, syncs the network state and updates each live member's
 * movement, collision and pose. */

typedef struct Ov022RootBits {
    unsigned char bit0 : 1;
    unsigned char bit1 : 1;
    unsigned char bit2 : 1;
    unsigned char bit3 : 1;
    unsigned char rest : 4;
} Ov022RootBits;

typedef struct Ov022Root {
    unsigned int flags;
    char padding004[0x30];
    unsigned char entryCount34;
    char padding035[7];
    Ov022RootBits stateBits3c;
} Ov022Root;

extern char data_ov022_020b2e78[];

extern int func_ov022_02087344(void);
extern int Ov022_Party_ApplyNetState(void);
extern int Ov022_GetEntryField66(int index);
extern void Ov022_RunPendingHitCallback(int node);
extern void Ov022_ActorUpdate(int node);
extern void Ov022_TickSubObjectChain(int node);
extern int Ov022_GetGlobalPlus14_2(void);

void Ov022_Party_SyncAndUpdate(int unused)
{
    Ov022Root *root;
    char *entryCursor;
    int node;
    int index;

    entryCursor = *(char **)(data_ov022_020b2e78 + 4);
    root = (Ov022Root *)entryCursor;

    if ((*(unsigned int *)entryCursor & 2) == 0 ||
        func_ov022_02087344() == 0) {
        ((Ov022Root *)entryCursor)->stateBits3c.bit3 = 0;
        return;
    }

    ((Ov022Root *)entryCursor)->stateBits3c.bit3 = Ov022_Party_ApplyNetState();
    index = 0;
    if (index < ((Ov022Root *)entryCursor)->entryCount34) {
        do {
            if (Ov022_GetEntryField66(index) >= 0) {
                node = *(int *)(*(int *)(entryCursor + 4) + 0x20);

                Ov022_RunPendingHitCallback(node);
                Ov022_ActorUpdate(node);
                Ov022_TickSubObjectChain(node);
            }
            index++;
            entryCursor += 0xc;
        } while (index < root->entryCount34);
    }
    *(unsigned char *)(Ov022_GetGlobalPlus14_2() + 0xc0) = 0;
}

