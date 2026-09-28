/* Sub-scene state after 020829b4: stays put while bit 0 of the root flags is set; otherwise, when
 * 0208cc58 reports a pending request, 02082b10(0) handles it, and once bit 2 is set the game-state
 * field 0x2080 (5 bits) becomes 0x1b and the scene moves on to 02082a3c. */
extern unsigned int *NNSi_FndGetCurrentRootHeap(void);
extern int Ov026_Shop_IsClosed(void);
extern void Ov026_SetMenuFlag4(int a);
extern void GameState_SetField(int field, int width, int value);
extern void Ov026_SubSceneIdleHandler(void);

int Ov026_SubSceneWait(void)
{
    unsigned int *h = NNSi_FndGetCurrentRootHeap();

    if ((*h & 1) != 0) {
        return 0;
    }
    if (Ov026_Shop_IsClosed() != 0) {
        Ov026_SetMenuFlag4(0);
    }
    if ((*h & 4) == 0) {
        return 0;
    }
    GameState_SetField(0x2080, 5, 0x1b);
    return (int)Ov026_SubSceneIdleHandler;
}
