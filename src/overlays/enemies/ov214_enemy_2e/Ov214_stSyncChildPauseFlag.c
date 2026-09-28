/* Post-tick: outside action 5 releases the held handles; in action 5 mirrors the actor's pause bit
 * into the two held effect objects; then runs the base post-tick. */

extern void Ov214_releaseHandles(void *this);
extern void Ov107_AiState_PostTickBase(void *this);

void Ov214_stSyncChildPauseFlag(char *this) {
    if (*(signed char *)(this + 0x1c6) != 5) {
        Ov214_releaseHandles(this);
    } else {
        if (*(int *)(this + 0x454) != 0) {
            int *p = *(int **)(this + 0x450);
            *(int *)((char *)p + 0x5c) = (*(int *)((char *)p + 0x5c) & ~2) |
                (((unsigned)(*(unsigned char *)(this + 0x1c4) & 2) << 0x1f) >> 0x1e);
        }
        if (*(int *)(this + 0x464) != 0) {
            int *p = *(int **)(this + 0x460);
            *(int *)((char *)p + 0x5c) = (*(int *)((char *)p + 0x5c) & ~2) |
                (((unsigned)(*(unsigned char *)(this + 0x1c4) & 2) << 0x1f) >> 0x1e);
        }
    }
    Ov107_AiState_PostTickBase(this);
}
