/* Starts the status banner tween for a step (slide in, hold, slide out). */

typedef struct Tween {
    int mode,duration,from,to;
    long long startTick;
    unsigned int flags;
} Tween;
typedef struct Ov005Context { char opaque00[0x4c70]; Tween statusTween; } Ov005Context;
extern Ov005Context *data_ov005_0205b80c;
extern void Tween_Configure(Tween *,int,int,int,int);
extern void Tween_Start(Tween *);
void Ov005_StartStatusTween(int step) {
    int from,duration,to;
    switch(step) {
    case 1: from=115;to=115;duration=1000;break;
    case 2: from=115;to=0;duration=200;break;
    case 3: from=0;to=0;duration=2000;break;
    case 4: from=0;to=-115;duration=200;break;
    case 0:default:return;
    }
    Tween_Configure(&data_ov005_0205b80c->statusTween,0,from*4096,to*4096,duration);
    Tween_Start(&data_ov005_0205b80c->statusTween);
}
