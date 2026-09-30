/* Formats the world's path string from its index. */

extern int OS_SPrintf();
extern int gOv002StrIntFmt;
extern int gOv002PentName;

void Ov002_FormatWorldPath(int arg0, int arg1) {
    OS_SPrintf(arg1, &gOv002StrIntFmt, &gOv002PentName, *(signed char *)(arg0 + 1));
}
