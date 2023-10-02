#ifndef _DEFINITIONS_H
#define _DEFINITIONS_H 
 
// SRAM DECLARATIONS 
uint8_t EXPO = 0;   // Execution Stage pointer 
uint8_t EXDI =0;    // Execution directive
uint8_t EXSL[32]={};// Execution stage list  (EXSL[EXPO])
uint8_t EXSC =0;    // Execution stage count
int PSPO =-1; // previous started pointer, used to cal onstageLoad on each stage
uint16_t EXTM = 0 ; // Execution times multiplier loads from eeprom address 0, length 2  
uint16_t EXTC = 0 ; // Execution times counter
uint8_t EXMO = 0 ; // Execution mode loads from eeprom addres 2, length 1 
uint8_t EXTY = 0; // Execution sequence 0 is init conditions 1 is main program sequence 
bool FNMAA =false; // Flag next maa

bool FBRUN=false; // Flag BRUN button
bool FBINI=false; // Flag BINI button
bool FBPAU=false; // Flag BPAU button
bool FBRES=false; // Flag BRES button

 // Inputs   

#define MAA 22  // Main black mark 
#define MAB 23  // Main black mark 
#define PAF 24  // PA forward
#define PAB 25  // PA backward
#define PAH 26  // PA heat
#define PBF 27  // PB forward
#define PBB 28  // PB backward
#define PBH 29  // PB heat
#define FLO 30  // FL open
#define FLC 31  // FL closed
#define FUO 32  // FU open
#define FUC 33  // FU closed
#define FAF 34  // FA full
#define FAE 35  // FA empty

 // Outputs
// Using steppers as pull elements
#define SAA 54  // SA pin A
#define SAB 55  // SA pin B
#define SAC 56  // SA pin C
#define SAD 57  // SA pin D

#define SBA 58  // SB pin A
#define SBB 59  // SB pin B
#define SBC 60  // SB pin C
#define SBD 61  // SB pin D 

// Using motors as pull elements
#define PAD 53  // PA direction  
#define PAP 52  // PA pulse
#define PAHO 51 // PA heat on
#define PBD 50  // PB direction  
#define PBP 49  // PB pulse
#define PBHO 48  // PB heat on
 
#define FLM 47  // FA load move
#define FUM 46  // FA unload move
#define FRM 45  // FA rotor move
#define MAM 44  // MA   move
#define BAM 43  // BA   move
  
// Input buttons
#define BINI      2// Button run initial sequence
#define BRUN      3// Button run main sequence
#define BPAU      4// Button run initial sequence
#define BRES      5// Button resume sequence EXDI  = 1

// Output indicators
#define LRUN      11// LED running main sequence
#define LPAU      12// LED running initial sequence
#define LERR      13// LED error indicator


// Stages index
#define SPAB      0 // Move PA to B
#define SPAF      1 // Move PA to F
#define SPAHE     2 // Enable pa heat
#define SPAHD     3 // Disable pa heat
#define SPBB      4 // Move PB to B
#define SPBF      5 // Move PB to F  
#define SPBHE     6 // Enable pb heat
#define SPBHD     7 // Disable pb heat
#define SFUC      8 // Close FU
#define SFUO      9 // Open FU
#define SFLC      10// Close FL  
#define SFLO      11// Open FL
#define SFRM      12// Enable FR
#define SFRS      13// Disable FR 
#define SMAM      14// Move MA  
#define SMAS      15// Stop MA
#define SMAN      16// Move MA until next mark 



// Compiler defines 
#define RUNNING 0
#define PAUSED 1
#define STOPPED 2
#define RESUMED 3
#define ERROR 4
 
 
#endif
