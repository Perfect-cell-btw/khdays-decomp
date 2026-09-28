/* Checks whether a tutorial topic's unlock flag is set. Returns whether the topic's flag is set. */

extern int Ov025_GetSlideTableValue();
extern int GameState_IsFlagSet();

int Ov025_Tutorial_IsTopicUnlocked(int arg0) {
    return GameState_IsFlagSet(Ov025_GetSlideTableValue(arg0) + 0x3c2b);
}
