/* Ov006_MissionDrawTextRunFwd -- thin forwarder to Ov006_MissionDrawTextRun (7 args, stack tail passed through). */
extern void Ov006_MissionDrawTextRun(int a, int b, int c, int d, int e, int f, int g);

void Ov006_MissionDrawTextRunFwd(int a, int b, int c, int d, int e, int f, int g) {
    Ov006_MissionDrawTextRun(a, b, c, d, e, f, g);
}
