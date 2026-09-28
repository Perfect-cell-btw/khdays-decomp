extern int Ov002_LoadObjectRecordsAndDrops();

int Ov002_ScriptCmd_LoadObjectRecords(int arg0) {
    Ov002_LoadObjectRecordsAndDrops(arg0);
    return 1;
}
