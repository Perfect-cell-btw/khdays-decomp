extern int Ov025_BlitTileRect();

int Ov025_ResourceEntryCallback(int arg0) {
    return Ov025_BlitTileRect(arg0, 1);
}
