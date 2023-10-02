#ifndef H_SYSTEM
#define H_SYSTEM

// PA AND PB MOTORS 
A4988 PA(PAP,PAD,1.8,280);
A4988 PB(PBP,PBD,1.8,280);
  

uint16_t getEUint16(uint8_t start){ return EEPROM.read(start+1)*256 + EEPROM.read(start); }

// ui
void uiOutput(uint8_t state){
  if(state ==RUNNING){ 
      digitalWrite(LRUN,HIGH);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_running));
    }else  if(state ==RUNNING){ 
      digitalWrite(LRUN,HIGH);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_resumed));
    }
    else if(state==PAUSED ){ 
      digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,HIGH);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_paused));
    }else if(  state ==STOPPED){ 
      digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,HIGH);
      digitalWrite(LERR,LOW);
       Serial.print(FS(_stopped));
    }else if(state==ERROR){
       digitalWrite(LRUN,LOW);
      digitalWrite(LPAU,LOW);
      digitalWrite(LERR,HIGH);
     }
  }

void stop(){EXDI=0;  EXTC=0; uiOutput(STOPPED); }
void pause(){ EXDI=0;  uiOutput(PAUSED); }
void resume(){EXDI=1; uiOutput(RESUMED);}
void run(){EXDI=1; uiOutput(RUNNING);}
 
// after stage operation 
void aso(){ 
  if(EXMO==1){pause();}
  }
// after unit operation 
void auo(){
Serial.print("Completed "); Serial.print(EXTC); Serial.print(" of ");Serial.println(EXTM);
 if(EXMO==2){pause();} 
 } 

bool check_init_cond(){

 /*
  MAA Black mark sensor a   1
  PAF PA forward position   0
  PAB PA backward position    1
  PAH PA heat element sensor    0
  PBF PB forward position   0
  PBB PB backward position    1
  PBH PB heat element sensor    0 
  FLO FL open   0
  FLC FL closed   1
  FUO FU open   0
  FUC FU closed   1  
 */

if(digitalRead(MAA)!=1){Serial.println("MAA not 1");return false;}
if(digitalRead(MAB)!=1){Serial.println("MAB not 1");return false;}
if(digitalRead(PAF)!=0){Serial.println("PAF not 0");return false;}
if(digitalRead(PAB)!=1){Serial.println("PAB not 1");return false;}
if(digitalRead(PAH)!=0){Serial.println("PAH not 0");return false;}
if(digitalRead(PBF)!=0){Serial.println("PBF not 0");return false;}
if(digitalRead(PBB)!=1){Serial.println("PBB not 1");return false;}
if(digitalRead(PBH)!=0){Serial.println("PBH not 0");return false;}
if(digitalRead(FLO)!=0){Serial.println("FLO not 0");return false;}
if(digitalRead(FLC)!=1){Serial.println("FLC not 1");return false;}
if(digitalRead(FUO)!=0){Serial.println("FUO not 0");return false;}
if(digitalRead(FUC)!=1){Serial.println("FUC not 1");return false;} 
return true;  
  }

void set_init_cond(){
  // load init condition sequence in EXSL
  // Generate execution list 
  EXSL[0]=SPAB; // move PA to B
  EXSL[1]=SPBB; // move PB to B
  EXSL[2]=SFLC; // close FL 
  EXSL[3]=SFUC; // close FU
  EXSL[4]=SPAHD; // disable PA Heat
  EXSL[5]=SPBHD; // disable PB Heat
  EXSL[6]=SMAM; // Find mark 
 
  EXSC=7; // Set execution stage count
  PSPO=-1;// Set previous Stage pointer
  EXPO=0; // set execution pointer to zero

   EXTY = 0 ; // running initial conditions sequence
  }

void set_program_sequence(){



 EXSL[0]=SMAN;  //Move MA to next mark
 EXSL[1]=SMAS;  //Stop MA
 EXSL[2]=SPBF;  //Move PB to F
 EXSL[3]=SPBHE; //Enable PB heat
 EXSL[4]=SPBHD; //Disable PB heat
 EXSL[5]=SPBB;  //Move PB to B
 EXSL[6]=SPAF;  //Move PA to F
 EXSL[7]=SPAHE; //Enable PA heat
 EXSL[8]=SPAHD; //Disable PA heat
 EXSL[9]=SPAB;  //Move PA to B
 EXSL[10]=SFLO; //Open FL
 EXSL[11]=SFRM; //Enable FR
 EXSL[12]=SFRS; //Disable FR
 EXSL[13]=SFLC; //Close FL
 EXSL[14]=SFUO; //Open FU
 EXSL[15]=SFUC; //Close FU
 EXSL[16]=SMAN; //Move MA to next mark
 EXSL[17]=SPBF; //Move PB to F
 EXSL[18]=SPBHE;  //Enable PB heat
 EXSL[19]=SPBHD;  //Disable PB heat
 EXSL[20]=SPBB; //Move PB to B

  EXSC=21; // Set execution stage count
  PSPO=-1;// Set previous Stage pointer
  EXPO=0; // set execution pointer to zero

 EXTY = 1 ; // running program sequence
  }


void run_init_cond(){
set_init_cond();
  run();
  }

void run_program_sequence(){
  EXTM = getEUint16(0); // retrieve execution times 
  if(EXTM==0xFFFF){EXTM=1; EEPROM.put(0,EXTM);} // set default EXTM if not set 

  EXTC = 0 ; // Reset execution times counter

  EXMO = EEPROM.read(2); // retrieve execution mode  
  if(EXMO==0xFF) {EXMO = 0; EEPROM.write(2,EXMO);}  // set default EXMO if  not set 
  
 
  if(!check_init_cond()){Serial.print(FS(_no_init_cond));return;}
  set_program_sequence();
  run();
  }

void inputs_listen(){  
  if(digitalRead(BINI)==HIGH && FBINI==false){ FBINI=true;}  if(digitalRead(BINI)==LOW && FBINI==true){   run_init_cond(); FBINI=false; }
  if(digitalRead(BRUN)==HIGH && FBRUN==false){ FBRUN=true;}  if(digitalRead(BRUN)==LOW && FBRUN==true){   run_program_sequence(); FBRUN=false; }
  if(digitalRead(BPAU)==HIGH && FBPAU==false){ FBPAU=true;}  if(digitalRead(BPAU)==LOW && FBPAU==true){   pause(); FBPAU=false; }
  if(digitalRead(BRES)==HIGH && FBRES==false){ FBRES=true;}  if(digitalRead(BRES)==LOW && FBRES==true){   resume(); FBRES=false; }
 
  }

void init_pinout(){
  
 
// inputs 
pinMode(MAA,INPUT);
pinMode(MAB,INPUT);

pinMode(PAF,INPUT);
pinMode(PAB,INPUT);
pinMode(PAH,INPUT);

pinMode(PBF,INPUT);
pinMode(PBB,INPUT);
pinMode(PBH,INPUT);

pinMode(FLO,INPUT);
pinMode(FLC,INPUT);
pinMode(FUO,INPUT);
pinMode(FUC,INPUT);
pinMode(FAF,INPUT);
pinMode(FAE,INPUT);
  


// Outputs 

/*
DONE AT CONSTRUCTOR

// stepper
pinMode(SAA,OUTPUT);
pinMode(SAB,OUTPUT);
pinMode(SAC,OUTPUT);
pinMode(SAD,OUTPUT);

pinMode(SBA,OUTPUT);
pinMode(SBB,OUTPUT);
pinMode(SBC,OUTPUT);
pinMode(SBD,OUTPUT);

// motors
 
pinMode(PAE,OUTPUT);  digitalWrite(PAE,LOW); // disable driver
pinMode(PA0,OUTPUT);
pinMode(PA1,OUTPUT);
 
pinMode(PBE,OUTPUT);  digitalWrite(PBE,LOW); // disable driver
pinMode(PB0,OUTPUT);
pinMode(PB1,OUTPUT);
*/

// MA and BA
pinMode(MAM,OUTPUT);
pinMode(BAM,OUTPUT);
// Filler

pinMode(FLM,OUTPUT);
pinMode(FUM,OUTPUT);

// Input buttons
pinMode(BINI,INPUT);
pinMode(BRUN,INPUT);
pinMode(BPAU,INPUT);
pinMode(BRES,INPUT);
//Output indicators
pinMode(LRUN,OUTPUT);
pinMode(LPAU,OUTPUT);
pinMode(LERR,OUTPUT);


  }
  
#endif
