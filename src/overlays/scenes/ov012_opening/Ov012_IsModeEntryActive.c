int Ov012_IsModeEntryActive(int this_) {
    switch (*(int *)(this_ + 0x6c)) {
    case 0:
        return *(signed char *)(*(int *)(this_ + 0x74) + *(int *)(this_ + 0x64)) != 0;
    case 1:
    case 2:
    case 3:
    case 4:
        return 1;
    default:
        return 0;
    }
}
