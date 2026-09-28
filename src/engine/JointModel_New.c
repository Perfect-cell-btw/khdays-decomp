extern void *CallocInstance(int size);
extern void JointModel_Construct(void *p, int a1, int a2);

void *JointModel_New(int arg0, int arg1)
{
    void *p = CallocInstance(0x94);
    JointModel_Construct(p, arg0, arg1);
    return p;
}
