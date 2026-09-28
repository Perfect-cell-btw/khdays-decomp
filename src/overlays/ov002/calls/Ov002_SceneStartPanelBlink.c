/*
 * Ov002_SceneStartPanelBlink - start one blink of the panel's alert widget.
 *
 * The tint tween swings between the two shades and back, and the level tween
 * takes the widget from full down to nothing over a second.
 *
 * ARM.
 */

typedef struct {
    int nMode;
    int nDuration;
    int nFrom;
    int nTo;
    int aStart[2];
    unsigned int dwFlags;
} Ov002Tween;

typedef struct {
    char pad000[0xff0];
    Ov002Tween tweenLevel;
    Ov002Tween tweenTint;
} Ov002BlinkScene;

extern int data_ov002_0207f628;

extern void Tween_Configure(Ov002Tween *pTween, int nMode, int nFrom, int nTo,
                          int nDuration);
extern void Tween_Start(Ov002Tween *pTween);

void Ov002_SceneStartPanelBlink(void)
{
    Ov002BlinkScene *s;

    s = *(Ov002BlinkScene **)&data_ov002_0207f628;
    Tween_Configure(&s->tweenTint, 2, 0x2e1, 0x5ec, 200);
    Tween_Start(&s->tweenTint);
    Tween_Configure(&s->tweenLevel, 1, 0x1f000, 0, 1000);
    Tween_Start(&s->tweenLevel);
}
