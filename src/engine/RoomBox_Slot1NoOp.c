/* Empty slot 1 of the room-box collider function table (data_02042928). Like every empty function
 * it returns its first argument unchanged (the ROM is a bare `bx lr`); an object update reads that
 * as "stay in this state". */

void *RoomBox_Slot1NoOp(void *arg)
{
    return arg;
}
