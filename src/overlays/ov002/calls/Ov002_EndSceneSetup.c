/* Scene screen close handler (pair of Ov002_BeginSceneSetup): frees the scene buffer and clears its
 * status. */

extern int data_ov002_0207f600;
extern int Ov002_FreeBufferAndClearStatus();

int Ov002_EndSceneSetup(void) {
    return Ov002_FreeBufferAndClearStatus(*(int *)&data_ov002_0207f600 + 0x10);
}
