/* Sample active result tweens and refresh the gauge from the current reward counter. */

#include "nitro/types.h"

typedef struct TweenFlags { unsigned int started:1, paused:1, finished:1, reserved:29; } TweenFlags;
typedef struct Tween { char unknown00[24]; TweenFlags flags; } Tween;
typedef struct Ov005ResultTween { Tween tween; int duration, currentValue, fromValue, toValue; } Ov005ResultTween;
typedef struct Ov005GaugeRange { int maximum, value; } Ov005GaugeRange;
typedef struct Ov005ResultContext {
    char unknown00[0x4b84];
    Ov005ResultTween resultTweens[4];
    char unknown4c34[24];
    Ov005GaugeRange gauge, previousGauge;
} Ov005ResultContext;
typedef struct Ov005Config {
    char unknown00[12];
    unsigned short rewardMode;
    char unknown0e[58];
    int gaugeScore;
    char unknown4c[8];
    int rewardScale04;
} Ov005Config;
extern Ov005ResultContext *data_ov005_0205b810;
extern Ov005Config data_ov005_0205b85c;
extern void Tween_Sample(Tween *, int *);
extern int Ov005_ScaleByPercent(int, int);
extern void Ov005_CalculateGaugeRange(Ov005GaugeRange *, int);
int Ov005_SampleResultCounters(void) {
    u8 index;
    int sampled = 0;
    Ov005ResultTween *entry;
    Ov005Config *config = &data_ov005_0205b85c;
    int sample;
    for (index = 0; index < 4; index++) {
        entry = &data_ov005_0205b810->resultTweens[index];
        if (entry->tween.flags.started && !entry->tween.flags.finished) {
            Tween_Sample(&entry->tween, &sample);
            sampled = 1;
            entry->currentValue = index == 0 && config->rewardMode == 0 ? sample : sample >> 12;
        }
    }
    {
        Ov005ResultContext *context = data_ov005_0205b810;
        context->previousGauge = context->gauge;
        Ov005_CalculateGaugeRange(&data_ov005_0205b810->gauge,
            config->gaugeScore + Ov005_ScaleByPercent(context->resultTweens[3].currentValue, config->rewardScale04));
    }
    return sampled;
}
