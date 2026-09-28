/*
 * Ov002_SetStateRecordStage - set the three stage/status bytes at +5/+6/+7 of the state
 * record at root-context + 0x8c94 to 0, 1, 2. Leaf helper chained from
 * Ov002_InitStateRecord (Ov002_InitStateRecord) at the end of that record's reset.
 *
 * THUMB leaf (bx lr).
 */

extern int data_ov002_0207fa00;

void Ov002_SetStateRecordStage(void)
{
    char *rec = (char *)(data_ov002_0207fa00 + 0x8c94);

    rec[5] = 0;
    rec[6] = 1;
    rec[7] = 2;
}
