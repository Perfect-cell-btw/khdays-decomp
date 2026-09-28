typedef unsigned char u8;
typedef signed short s16;

typedef struct Ov002ReqPair {
    int n00;
    int n04;
} Ov002ReqPair;

typedef struct Ov002ReqQuad {
    int n00;
    int n04;
    int n08;
    int n0c;
} Ov002ReqQuad;

typedef struct Ov002TaskArgsPath {
    int n00;
    int n04;
    int n08;
    char blk0c[0xc];        /* handed on by address */
    int n18;
    int n1c;
    int n20;
    int n24;
    int n28;
} Ov002TaskArgsPath;

typedef struct Ov002TaskArgsGlyph {
    int n00;
    u8 b04;
    char pad05[1];
    s16 h06;
    char blk08[0x20];       /* handed on by address */
    char blk28[0x20];       /* handed on by address */
    s16 h48;
    u8 b4a;
    char pad4b[1];
    int n4c;
} Ov002TaskArgsGlyph;

typedef struct Ov002ReqFlags {
    u8 b00;
    u8 b01;
    char pad02[2];
    int n04;
    int n08;
} Ov002ReqFlags;

typedef struct Ov002ReqTriple {
    int n00;
    int n04;
    int n08;
} Ov002ReqTriple;

extern int Session_IsReady(void);         /* session ready */
extern int Ov002_CreateTaskNodeWW(int a, int b);
extern int Ov002_AllocScriptCallback(int a, int b, int c, int d);
extern int Ov002_CreateTaskNodePath(int a, int b, int c, void *pBlock,
                               int e, int f, int g, int h, int i);
extern int Ov002_CreatePairCompareNode(int a, int b, int c, void *pBlock,
                               void *pTail, int f, int g, int h);
extern int Ov002_CreateTaskNodeBB(int a, int b, int c, int d);
extern int Ov002_CreateTaskNodeHH(int a, int b, int c);
extern int Ov013_CreateTaskNode(int a, int b, int c);
extern void Ov002_RegisterTaskNode(unsigned int nSlot, int hNode);

/* Builds one task node from pArgs and registers it under nSlot.  Does nothing at
   all until the session is ready; a bOwned of zero sets bit 12 of the slot
   first.  nKind picks both the builder and the shape of pArgs. */
void Ov002_SubmitTaskNode(int bOwned, unsigned int nSlot, int nKind, void *pArgs)
{
    int hNode;

    hNode = 0;
    if (Session_IsReady() == 0) {
        return;
    }
    if (bOwned == 0) {
        nSlot |= 1 << 12;
    }

    switch ((unsigned int)nKind) {
    case 0:
        hNode = Ov002_CreateTaskNodeWW(((Ov002ReqPair *)pArgs)->n00,
                                    ((Ov002ReqPair *)pArgs)->n04);
        break;

    case 1:
        hNode = Ov002_AllocScriptCallback(((Ov002ReqQuad *)pArgs)->n00,
                                    ((Ov002ReqQuad *)pArgs)->n04,
                                    ((Ov002ReqQuad *)pArgs)->n08,
                                    ((Ov002ReqQuad *)pArgs)->n0c);
        break;

    case 2:
        hNode = Ov002_CreateTaskNodePath(((Ov002TaskArgsPath *)pArgs)->n00,
                                    ((Ov002TaskArgsPath *)pArgs)->n04,
                                    ((Ov002TaskArgsPath *)pArgs)->n08,
                                    ((Ov002TaskArgsPath *)pArgs)->blk0c,
                                    ((Ov002TaskArgsPath *)pArgs)->n18,
                                    ((Ov002TaskArgsPath *)pArgs)->n1c,
                                    ((Ov002TaskArgsPath *)pArgs)->n20,
                                    ((Ov002TaskArgsPath *)pArgs)->n24,
                                    ((Ov002TaskArgsPath *)pArgs)->n28);
        break;

    case 3:
        hNode = Ov002_CreatePairCompareNode(((Ov002TaskArgsGlyph *)pArgs)->n00,
                                    ((Ov002TaskArgsGlyph *)pArgs)->b04,
                                    ((Ov002TaskArgsGlyph *)pArgs)->h06,
                                    ((Ov002TaskArgsGlyph *)pArgs)->blk08,
                                    ((Ov002TaskArgsGlyph *)pArgs)->blk28,
                                    ((Ov002TaskArgsGlyph *)pArgs)->b4a,
                                    ((Ov002TaskArgsGlyph *)pArgs)->h48,
                                    ((Ov002TaskArgsGlyph *)pArgs)->n4c);
        break;

    case 4:
        hNode = Ov002_CreateTaskNodeBB(((Ov002ReqFlags *)pArgs)->b00,
                                    ((Ov002ReqFlags *)pArgs)->b01,
                                    ((Ov002ReqFlags *)pArgs)->n04,
                                    ((Ov002ReqFlags *)pArgs)->n08);
        break;

    case 5:
        hNode = Ov002_CreateTaskNodeHH(((Ov002ReqTriple *)pArgs)->n00,
                                    ((Ov002ReqTriple *)pArgs)->n04,
                                    ((Ov002ReqTriple *)pArgs)->n08);
        break;

    case 6:
        hNode = Ov013_CreateTaskNode(((Ov002ReqTriple *)pArgs)->n00,
                                    ((Ov002ReqTriple *)pArgs)->n04,
                                    ((Ov002ReqTriple *)pArgs)->n08);
        break;
    }

    if (hNode != 0) {
        Ov002_RegisterTaskNode(nSlot, hNode);
    }
}
