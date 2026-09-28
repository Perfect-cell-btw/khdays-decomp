/* Whether the point lies inside the box (x, y, width, height bytes). */

int Ov000_PointInBox(unsigned short *pos, unsigned char *box) {
    if ((unsigned short)(pos[0] - box[0]) < box[2]) {
        if ((unsigned short)(pos[1] - box[1]) < box[3]) return 1;
    }
    return 0;
}
