extern int Session_GetLocalPlayerIndex(void);
extern int Ov022_ActorSetState(int *self, int state);
extern int data_ov096_020bc0c0;

int Ov096_PublishAndEnterState21(int *self, int v) {
    int *slot = (int *)(*(int *)&data_ov096_020bc0c0 + 0xc50 + 0x2000);
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x464) |= 0x10000;
    }
    if (Session_GetLocalPlayerIndex() == 0) {
        *(long long *)((char *)self + 0x46c) |= 0x10000;
    }
    *slot = v;
    return Ov022_ActorSetState(self, 0x21);
}
