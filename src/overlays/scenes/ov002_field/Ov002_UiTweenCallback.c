/* UI context callback: samples the blend tween unless the context is paused (+0xc). */

extern int Ov002_SampleBlendTween();
extern int data_ov002_0207f60c;

void Ov002_UiTweenCallback(void) {
    if (*(int *)(*(int *)&data_ov002_0207f60c + 0xc) != 0) {
        return;
    }
    Ov002_SampleBlendTween();
}
