/* Ov025_AddListEntry -- Ov008_AddListEntry (188 B, 4 relocs).
 * Adds or merges one entry into the menu list. Looks up the node with matching (kind=param_3,
 * id=param_2) via Ov025_FindNodeIndexed; if none exists it draws a fresh entry through
 * Ov025_InsertListEntry (forwarding params 2..9). If the node already exists it merges extents into
 * it: field 0xc is raised to at least param_4 (signed max) and field 0x10 accumulates param_5.
 * When param_10 is set it then refreshes the layout: Ov025_UpdateScrollGauge(self) followed by
 * Ov025_SetScrollGaugePos(self, self->field_0x48). */
extern int *Ov025_FindNodeIndexed(int a, int b, int c, int *d);
extern void Ov025_InsertListEntry(int p1, int p2, int p3, int p4, int p5, int p6, int p7, int p8, short *p9);
extern void Ov025_UpdateScrollGauge(int p);
extern void Ov025_SetScrollGaugePos(int p, int a);

void Ov025_AddListEntry(int param_1, int param_2, int param_3, int param_4, int param_5,
                         int param_6, int param_7, int param_8, short *param_9, int param_10)
{
    int *node = Ov025_FindNodeIndexed(param_1, param_3, param_2, 0);
    if (node == 0) {
        Ov025_InsertListEntry(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
    } else {
        if (param_4 < node[3])
            param_4 = node[3];
        node[3] = param_4;
        node[4] += param_5;
    }
    if (param_10 != 0) {
        Ov025_UpdateScrollGauge(param_1);
        Ov025_SetScrollGaugePos(param_1, *(int *)(param_1 + 0x48));
    }
}
