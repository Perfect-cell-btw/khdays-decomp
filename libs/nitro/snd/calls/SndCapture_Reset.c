/* Clears the sound capture work. */

extern int data_0204a2fc[3];

void SndCapture_Reset(void)
{
    data_0204a2fc[2] = 0;
    data_0204a2fc[0] = 0;
    data_0204a2fc[1] = 0;
}
