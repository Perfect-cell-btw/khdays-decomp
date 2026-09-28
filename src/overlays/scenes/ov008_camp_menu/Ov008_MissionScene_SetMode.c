/* Sets the mission scene's mode (1-4); returns whether it did. */

extern char *data_ov008_02090fa4[];

int Ov008_MissionScene_SetMode(unsigned int value)
{
    char *data = data_ov008_02090fa4[0];

    if (data == 0) {
        return 0;
    }

    if (value != 0 && value <= 4) {
        *(int *)(data + 0x9508) = value;
        return 1;
    }

    return 0;
}
