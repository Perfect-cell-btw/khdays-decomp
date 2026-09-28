/* Ov008_LayoutMissionCounter -- Ov008_LayoutMissionCounter: lay out the mission number
 * counter on the 954c tracker: the frame (tag 0x44 at x 1), then the hundreds,
 * tens and ones digit tags (0x45 + digit at x 5/6/7; leading zeros skipped) and
 * the "not last" marker (tag 0x4f at x 8) when the current mission differs from
 * the highest one or is 0x163, but never for 0x166.  All at y 2.
 */
#define TAG_FRAME  0x44
#define TAG_DIGIT0 0x45
#define TAG_MARKER 0x4f
#define ROW_Y      2
#define MISSION_FORCE_MARK 0x163
#define MISSION_NO_MARK    0x166

extern int  Ov008_GetCtxBlock954c(void);                                    /* Ov008_GetCtxBlock954c */
extern int  Ov008_GetCtxField9638(void);                                    /* Ov008_GetCtxField9638: current mission */
extern int  Ov008_GetCtxField963a(void);                                    /* Ov008_GetCtxField963a: highest mission */
extern void Ov008_SetTagValueDup(int nOwner, unsigned int nTag, short nX, short nY); /* Ov008_SetTagValueDup */

void Ov008_LayoutMissionCounter(void)
{
    int nOwner;
    int nMission;
    int nHighest;
    int nHundreds;
    int nRest;
    int nTens;
    int nOnes;
    int bMark;

    nOwner = Ov008_GetCtxBlock954c();
    nMission = Ov008_GetCtxField9638();
    nHighest = Ov008_GetCtxField963a();
    nHundreds = nMission / 100;
    nRest = nMission % 100;
    nTens = nRest / 10;
    nOnes = nRest % 10;
    Ov008_SetTagValueDup(nOwner, TAG_FRAME, 1, ROW_Y);
    if (nMission >= 100) {
        Ov008_SetTagValueDup(nOwner, TAG_DIGIT0 + nHundreds, 5, ROW_Y);
    }
    if (nMission >= 10) {
        Ov008_SetTagValueDup(nOwner, TAG_DIGIT0 + nTens, 6, ROW_Y);
    }
    Ov008_SetTagValueDup(nOwner, TAG_DIGIT0 + nOnes, 7, ROW_Y);
    bMark = 0;
    if (nMission != nHighest) {
        bMark = 1;
    }
    if (nMission == MISSION_FORCE_MARK) {
        bMark = 1;
    }
    if (nMission == MISSION_NO_MARK) {
        bMark = 0;
    }
    if (bMark != 0) {
        Ov008_SetTagValueDup(nOwner, TAG_MARKER, 8, ROW_Y);
    }
}
