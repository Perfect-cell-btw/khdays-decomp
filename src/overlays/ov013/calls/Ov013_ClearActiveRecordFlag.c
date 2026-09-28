typedef struct {
    char padding00[0x108];
    unsigned char flags;
    signed char state;
    char padding10a[2];
} Ov013Record;

typedef struct {
    char padding00[0x110];
    signed char count;
    char padding111[3];
    Ov013Record records[];
} Ov013RecordList;

extern char data_ov013_0207fec0[];
extern void Ov002_RebindGroupAnimations(void *data, int kind, int zero, int value);

void Ov013_ClearActiveRecordFlag(void *unused, int value, Ov013RecordList *list) {
    int i = 0;

    if (list->count > 0) {
        Ov013Record *record = list->records;
        do {
            if (record->state == 1) {
                record->flags &= ~1;
                break;
            }
            i++;
            record++;
        } while (i < list->count);
    }

    Ov002_RebindGroupAnimations(data_ov013_0207fec0, 5, 0, value);
}

