/* Sets the first word of the session context (data_0204c22c), when there is one. Only the
 * opening movie and the MobiClip player write it: 1 while a movie plays, 0 afterwards; nothing in
 * the decompiled code reads it. */

extern int data_0204c22c;

void Session_SetMoviePlaying(int playing) {
    int p = *(int *)&data_0204c22c;
    if (p != 0) *(int *)p = playing;
}
