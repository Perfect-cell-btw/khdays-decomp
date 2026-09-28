typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

/* The question the board is showing and who has answered it. */
typedef struct Ov002Board {
    char pad000[0x48];
    s16 nTopic;                 /* 0x48 */
    char pad04a[2];
    int nAnswered;              /* 0x4c, one bit per seat */
} Ov002Board;

/* The stage the board belongs to. */
typedef struct Ov002Stage {
    char pad000[4];
    u16 hMarks;                 /* 0x04, one bit per marker */
    s8 nStage;                  /* 0x06, negative while there is none */
} Ov002Stage;

extern char *data_ov002_0207fa00;
/* Boot mode flags; bit 0 marks a run that came up through the front end and
   bit 1 one that is only replaying. */
extern u8 data_0204c240;

extern void Ov002_AddMissionTally(void *pWho, int nKind, int nCount);
extern int Ov002_GetModuleSlot(int nStage);
extern int Ov002_LookupValueByKey(int nStage, int nSeat);

/* Note that one seat answered the question currently on the board.
 *
 * A seat only counts once, and only while the board is still showing the
 * question it answered.  The first answer from that seat is passed on, and
 * then, unless the run is one that skips it, the stage the board belongs to
 * turns the seat into a marker bit on the stage's own set.
 */
void Ov002_NoteSeatAnswer(void *pWho, int nSeat, int nUnused, int nTopic)
{
    char *pCtx;
    Ov002Board *pBoard;
    Ov002Stage *pStage;
    int nMarker;

    pCtx = data_ov002_0207fa00;
    pBoard = (Ov002Board *)(pCtx + 0x8d14);
    if (pBoard->nTopic == (s16)nTopic
        && (pBoard->nAnswered & (1 << nSeat)) == 0) {
        pBoard->nAnswered |= 1 << nSeat;
        Ov002_AddMissionTally(pWho, 3, 1);
    }

    if (data_0204c240 != 0) {
        if ((data_0204c240 & 1) == 0) {
            return;
        }
        if ((data_0204c240 & 2) != 0) {
            return;
        }
    }

    pStage = (Ov002Stage *)(pCtx + 0x8d7c);
    if (pStage->nStage < 0) {
        return;
    }

    nMarker = Ov002_LookupValueByKey(Ov002_GetModuleSlot(pStage->nStage), nSeat);
    if (nMarker < 0) {
        return;
    }

    pStage->hMarks |= 1 << nMarker;
}
