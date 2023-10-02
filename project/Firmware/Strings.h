#ifndef H_STRINGS
#define H_STRINGS
#define FS(x) (__FlashStringHelper*)(x)

const char _help[] PROGMEM = {"\r\nhelp           : Shows usable commands.\n\rinit           : Sets machine elements to initial conditions.\n\rrun             : Run the main program.\n\r\n\rpause         : Pause the main program.\n\rresume       : Resume the main program.\n\r"};
const char _unknown[] PROGMEM = {"Unknown command. Use help command.\n\r"};
const char _no_init_cond[] PROGMEM = {"Execution cancelled init conditions not match.\n\r"};
const char _paused[] PROGMEM = {"Paused.\n\r"};
const char _resumed[] PROGMEM = {"Resumed.\n\r"};
const char _stopped[] PROGMEM = {"Stopped.\n\r"};
const char _running[] PROGMEM = {"Running.\n\r"};


 /*
  * throws error
// Stage strings
const char SS_SPAB[] PROGMEM = {"SPAB"};
const char SS_SPAF[] PROGMEM = {"SPAF"};
const char SS_SPAHE[] PROGMEM = {"SPAHE"};
const char SS_SPAHD[] PROGMEM = {"SPAHD"};
const char SS_SPBB[] PROGMEM = {"SPBB"};
const char SS_SPBF[] PROGMEM = {"SPBF"};
const char SS_SPBHE[] PROGMEM = {"SPBHE"};
const char SS_SPBHD[] PROGMEM = {"SPBHD"};
const char SS_SFUC[] PROGMEM = {"SFUC"};
const char SS_SFUO[] PROGMEM = {"SFUO"};
const char SS_SFLC[] PROGMEM = {"SFLC"};
const char SS_SFLO[] PROGMEM = {"SFLO"};
const char SS_SFRM[] PROGMEM = {"SFRM"};
const char SS_SFRS[] PROGMEM = {"SFRS"};
const char SS_SMAM[] PROGMEM = {"SMAM"};
const char SS_SMAS[] PROGMEM = {"SMAS"};
const char SS_SMAN[] PROGMEM = {"SMAN"};

const char* const _ss[] PROGMEM = { SS_SPAB,SS_SPAF,SS_SPAHE,SS_SPAHD,SS_SPBB,SS_SPBF,SS_SPBHE,SS_SPBHD,SS_SFUC,SS_SFUO,SS_SFLC,SS_SFLO,SS_SFRM,SS_SFRS,SS_SMAM,SS_SMAS,SS_SMAN, };
 */

#endif
