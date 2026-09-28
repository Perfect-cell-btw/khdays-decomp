extern int QueryActiveStateOrDelegate();
extern int Ov022_GetEntryField66();
extern int Ov002_PostCrawlScoreLine();

int Ov002_ScriptCmd_PostCrawlScoreLine(int arg0) {
    QueryActiveStateOrDelegate(arg0);
    Ov022_GetEntryField66();
    Ov002_PostCrawlScoreLine();
    return 1;
}
