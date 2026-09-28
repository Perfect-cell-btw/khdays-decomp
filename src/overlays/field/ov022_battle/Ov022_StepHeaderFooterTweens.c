/* Steps the header and footer tweens, copies their values into the four rows' scales and advances
 * the fade state when they end. */

typedef unsigned int u32;

typedef struct Ov022TweenFlags {
    u32 unknown0 : 2;
    u32 finished : 1;
    u32 unknown3 : 29;
} Ov022TweenFlags;

typedef struct Ov022Tween {
    int values[6];
    Ov022TweenFlags flags;
} Ov022Tween;

typedef struct Ov022Row {
    char padding000[0x18];
    volatile int scaleA;
    volatile int scaleB;
    char padding020[0x10];
} Ov022Row;

typedef struct Ov022Pair {
    int a;
    int b;
} Ov022Pair;

typedef struct Ov022RootContext {
    Ov022Row rows[4];
    signed char state;
    char padding0c1[7];
    Ov022Tween tweenHeader;
    Ov022Tween tweenFooter;
} Ov022RootContext;

extern Ov022RootContext *NNSi_FndGetCurrentRootHeap(void);
extern void Tween_Sample(Ov022Tween *tween, int *value);
extern void func_ov022_02086e80(int count);
extern int Ov022_AdvanceFadeStateThenNextStep(void);
extern int data_0204be04;

int Ov022_StepHeaderFooterTweens(void)
{
    Ov022RootContext *context = NNSi_FndGetCurrentRootHeap();
    int result = 0;
    Ov022Pair value;
    Ov022Pair copy;

    if (*(unsigned char *)&data_0204be04 != 0) {
        return result;
    }

    Tween_Sample(&context->tweenHeader, &value.b);
    Tween_Sample(&context->tweenFooter, &value.a);
    if (context->tweenHeader.flags.finished) {
        context->state = 6;
        result = (int)Ov022_AdvanceFadeStateThenNextStep;
    }

    {
        Ov022Row *row = context->rows;
        int sampledB;
        int valueA;
        int i;

        valueA = value.b;
        sampledB = value.a;
        *(volatile int *)&copy.a = valueA;
        *(volatile int *)&copy.b = sampledB;
        i = 0;
        do {
            row->scaleA = valueA;
            row->scaleB = sampledB;
            i++;
            row++;
        } while (i < 4);
    }
    func_ov022_02086e80(4);
    return result;
}
