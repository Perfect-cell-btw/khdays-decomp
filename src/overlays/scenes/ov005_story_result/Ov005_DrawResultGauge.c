/* Draw the filled part of the result gauge in tiles of up to eight pixels. */
typedef unsigned char u8;
typedef struct Ov005ResultGaugeRequest {
    int firstTileId;
    short column;
    short row;
    int maximum, value, widthPixels;
} Ov005ResultGaugeRequest;
extern int func_02020400(int, int);
extern void Ov005_DrawResultTile(int, u8, u8);
void Ov005_DrawResultGauge(Ov005ResultGaugeRequest *request) {
    int remainingPixels;
    int column = 0;
    int percent = func_02020400(request->value * 100, request->maximum);
    remainingPixels = request->widthPixels * percent / 100;
    int fullTiles;
    if (remainingPixels <= 0) return;
    fullTiles = remainingPixels / 8;
    do {
        int tilePixels = fullTiles > 0 ? 8 : remainingPixels % 8;
        Ov005_DrawResultTile(request->firstTileId + (tilePixels - 1),
                          (u8)(request->column + column), (u8)request->row);
        remainingPixels -= 8;
        fullTiles--;
        column++;
    } while (remainingPixels > 0);
}
