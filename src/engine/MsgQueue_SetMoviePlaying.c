/* Sets the first word of the message queue context (gMsgQueue), when there is one. Only the
 * opening movie and the MobiClip player write it: 1 while a movie plays, 0 afterwards; nothing in
 * the decompiled code reads it. */

extern int gMsgQueue;

void MsgQueue_SetMoviePlaying(int playing) {
    int p = *(int *)&gMsgQueue;
    if (p != 0) *(int *)p = playing;
}
