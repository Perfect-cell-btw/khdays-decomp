/* Converts the node's rotation matrix to a normalised quaternion and clears its dirty bit. */

extern void Quat_FromMtx33(void *ptr, int);
extern void Vec4_Normalize(void *ptr1, void *ptr2);

void Node_SetRotationFromMtx(unsigned char *ptr, int arg1) {
    Quat_FromMtx33(ptr, arg1);
    Vec4_Normalize(ptr, ptr);
    ptr[0x28] &= ~1;
}
