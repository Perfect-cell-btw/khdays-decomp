/* Returns the game language (data_0204c1ec.lang, 1-5), set from the boot profile; Msg_BuildLangPath
 * uses it to pick the language code of localized files. */

extern int data_0204c1ec;

int GetLanguage(void) {
    return *(short *)&data_0204c1ec;
}
