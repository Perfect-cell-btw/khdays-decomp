extern void Text_UploadTileBuffer();

void Ov012_ReleaseField50IfSet(int this_) {
    if (*(int *)(this_ + 0x50) == 0) {
        return;
    }
    Text_UploadTileBuffer(this_, *(int *)(this_ + 0x50));
    *(int *)(this_ + 0x50) = 0;
}
