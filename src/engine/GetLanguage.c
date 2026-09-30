/* Returns the game language (gLangPath.lang, 1-5), set from the boot profile; Msg_BuildLangPath
 * uses it to pick the language code of localized files. */

extern int gLangPath;

int GetLanguage(void) {
    return *(short *)&gLangPath;
}
