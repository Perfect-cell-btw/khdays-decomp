extern int Ov302_AppendRecordsInRange(int this_, int list, int arg);
extern int Ov302_SelectAndSpawnEncounter(int this_, int list, int arg);
extern int Ov302_AppendRecordsBelowMax(int this_, int list, int arg);
extern int Ov302_AppendEligibleRecords(int this_, int list, int arg);
extern int Ov302_AppendTriggerableInRange(int this_, int list, int arg);
extern int Ov302_AppendRecordsKindZero(int this_, int list, int arg);
extern int Ov302_AppendRecordsKindNonZero(int this_, int list, int arg);
extern int Ov302_AppendRecordsKind4Id10(int this_, int list, int arg);

void Ov302_QueryFieldBySelector(int this_, unsigned int mode, int arg) {
    switch (mode) {
        case 0:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendRecordsInRange(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 1:
            *(unsigned short *)(this_ + 0x10) = Ov302_SelectAndSpawnEncounter(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 2:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendRecordsBelowMax(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 3:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendEligibleRecords(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 4:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendTriggerableInRange(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 5:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendRecordsKindZero(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 6:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendRecordsKindNonZero(this_, *(int *)(this_ + 0x14), arg);
            break;
        case 7:
            *(unsigned short *)(this_ + 0x10) = Ov302_AppendRecordsKind4Id10(this_, *(int *)(this_ + 0x14), arg);
            break;
    }
}
