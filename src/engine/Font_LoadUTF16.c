/* Loads a font file from the archive into the font (+8) and initialises it for UTF-16 text
 * (StreamReader_InitU16); returns 1. */

extern int Archive_LoadFile();
extern void StreamReader_InitU16();

int Font_LoadUTF16(int *font, char *name, int arg2, int arg3) {
    font[2] = Archive_LoadFile(name, 0xe, arg2, arg3);
    StreamReader_InitU16(font, (int *)font[2]);
    return 1;
}
