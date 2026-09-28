typedef unsigned short u16;
typedef struct TileSurface TileSurface;
extern void Text_DrawDirectional_2(TileSurface *,int,int,int,unsigned int,const u16 *);
void Ov005_DrawShadowedText(TileSurface *surface,const u16 *text,int x,int y,int color,unsigned int flags,int shadow) {
    if(text==0)return;
    if(shadow)Text_DrawDirectional_2(surface,x+1,y+1,color+1,flags,text);
    Text_DrawDirectional_2(surface,x,y,color,flags,text);
}
