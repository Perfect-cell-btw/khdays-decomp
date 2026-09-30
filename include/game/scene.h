#ifndef GAME_SCENE_H
#define GAME_SCENE_H

/* Scene ids: the index of the scene table (data_02042548, {overlay, class descriptor} per id),
 * what Scene_RequestPending takes and the scene controller (data_0204bda8) holds as current and
 * pending. Named where the scene has been seen running; 3 (ov003), 8 (ov011), 9 (ov009) and 13
 * (no overlay) are not identified yet. */

#define SCENE_TITLE             1   /* logos, the title, its menus and the save-file list (ov000) */
#define SCENE_FIELD             2   /* the field, story and missions alike (ov002) */
#define SCENE_CALENDAR          5   /* the day's calendar card (ov004) */
#define SCENE_MISSION_RESULT    6   /* a mission's results (ov005) */
#define SCENE_MISSION_SELECT    7   /* Mission Mode's character select (ov006) */
#define SCENE_MONOLOGUE         10  /* Roxas's monologue after the clock-tower scene (ov007) */
#define SCENE_OPENING           11  /* the opening movie (ov012 with ov024) */
#define SCENE_CONNECTION_ERROR  12  /* the connection-error screen, A back to the title (ov010) */
#define SCENE_MISSION_CAMP      19  /* Mission Mode's camp (ov008) */

#endif /* GAME_SCENE_H */
