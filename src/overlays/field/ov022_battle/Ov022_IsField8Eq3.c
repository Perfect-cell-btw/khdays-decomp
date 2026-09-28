/* Whether the byte at +8 is 3. */

int Ov022_IsField8Eq3(int arg0) { return *(unsigned char *)(arg0 + 8) == 3; }
