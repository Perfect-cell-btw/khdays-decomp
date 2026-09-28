extern void QuadTree_RemoveObject();

void ClearFlag8HandleIfNot10(int this_) {
    if ((*(int *)this_ & 8) == 0) return;
    if ((*(int *)this_ & 0x10) == 0) {
        QuadTree_RemoveObject(*(int *)(*(int *)(*(int *)(this_ + 0x10c) + 4)), this_ + 0x110);
    }
    *(int *)this_ &= ~8;
}
