/* Sets the first word of the message queue context (data_0204c230), when there is one. Only the
 * opening movie and the MobiClip player write it: 1 while a movie plays, 0 afterwards; nothing in
 * the decompiled code reads it. */

extern int data_0204c230;

void MsgQueue_SetMoviePlaying(int playing) {
    int p = *(int *)&data_0204c230;
    if (p != 0) *(int *)p = playing;
}
