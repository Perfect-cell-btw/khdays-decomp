/* Release the sub-resource at +0x190, then tear down the object. */
extern void DestroyInstance(int arg);
extern void Ov107_DestroyNode(int arg);
void Ov211_Destroy_2(int param_1) {
    DestroyInstance(*(int *)(param_1 + 0x190));
    Ov107_DestroyNode(param_1);
}
