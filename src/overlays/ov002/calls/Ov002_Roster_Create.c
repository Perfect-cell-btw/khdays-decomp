extern int InstantiateClass();
extern int Ov002_Roster_Reset();
extern int data_ov002_0207f010;
extern int data_ov002_0207f00c;

void Ov002_Roster_Create(void) {
    data_ov002_0207f00c = InstantiateClass(&data_ov002_0207f010, 0);
    Ov002_Roster_Reset();
}
