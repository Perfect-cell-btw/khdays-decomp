/* Whether the point lies inside the element's box (x, y, width, height bytes at +0x1c). */

struct Box {
    unsigned char pad[0x1c];
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
};

int Ov006_IsPointInBox(int px, int py, struct Box *b) {
    int r = 0;
    if (b->x <= px && px <= b->x + b->w && b->y <= py && py <= b->y + b->h) {
        r = 1;
    }
    return r;
}
