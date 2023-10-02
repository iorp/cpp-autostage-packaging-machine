#ifndef H_STAGECOLLECTION
#define H_STAGECOLLECTION

typedef void (*StageCollection) ();







 // move PA to B
 void _SPAB (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAB"); PA.setDirection(0); PSPO = EXPO;}
  
  if(digitalRead(PAB)!=HIGH){
    // During stage
    PA.move();
    }else{
      // On stage completed 
      EXPO++; aso();
      }  
     
}
// move PA to F
 void _SPAF (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAF"); PA.setDirection(1); PSPO = EXPO;}
  
  if(digitalRead(PAF)!=HIGH){
    // During stage
    PA.move();
    }else{
      // On stage completed 
      EXPO++; aso();
      }  
     
}
 
// enable PA  Heat
 void _SPAHE (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAHE");digitalWrite(PAHO,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(PAH)==HIGH){ digitalWrite(PAHO,LOW);  EXPO++;aso();}  
}
// disable PA  Heat
 void _SPAHD (){ 
 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPAHD"); digitalWrite(PAHO,LOW); PSPO = EXPO;}
  // On stage completed
  if(true){   EXPO++;aso(); }  
 
}


 // move PB to B
 void _SPBB (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBB"); PB.setDirection(0); PSPO = EXPO;}
  
  if(digitalRead(PBB)!=HIGH){
    // During stage
    PB.move();
    }else{
      // On stage completed 
      EXPO++; aso();
      }  
     
}
// move PB to F
 void _SPBF (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBF"); PB.setDirection(1); PSPO = EXPO;}
  
  if(digitalRead(PBF)!=HIGH){
    // During stage
    PB.move();
    }else{
      // On stage completed 
      EXPO++; aso();
      }  
     
}
 

/*
 // move PB to B
 void _SPBB (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBB"); PB.move(0);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(PBB)==HIGH){ PB.stop();  EXPO++;aso(); }  
}
 // move PB to F
 void _SPBF (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBF"); PB.move(1);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(PBF)==HIGH){ PB.stop();  EXPO++;aso(); }  
}

*/

// enable PB  Heat
 void _SPBHE (){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBHE");digitalWrite(PBHO,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(PBH)==HIGH){ digitalWrite(PBHO,LOW);  EXPO++;aso(); }  
}
// disable PB  Heat
 void _SPBHD (){ 
 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SPBHD"); digitalWrite(PBHO,LOW); PSPO = EXPO;}
  // On stage completed
  if(true){   EXPO++;aso();}  
 
}



// close FU
void _SFUC(){
   // On stage load
  //if(PSPO!=EXPO && digitalRead(FAE)==HIGH){  Serial.println("SFUC"); digitalWrite(FUM,HIGH);PSPO = EXPO;}
  if(PSPO!=EXPO ){  Serial.println("SFUC"); digitalWrite(FUM,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(FUC)==HIGH){ digitalWrite(FUM,LOW);  EXPO++;aso();}  
  }

// open FU
void _SFUO(){
   // On stage load
  if(PSPO!=EXPO){  Serial.println("SFUO"); digitalWrite(FUM,HIGH);PSPO = EXPO;}
  
  if(digitalRead(FUO)==HIGH ){ digitalWrite(FUM,LOW);  } 
  // wait till empty 
  if( digitalRead(FAE)==HIGH){ EXPO++;aso();}
 
  
 
  }


// close FL
void _SFLC(){
   // On stage load
  if(PSPO!=EXPO){  Serial.println("SFLC"); digitalWrite(FLM,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(FLC)==HIGH){ digitalWrite(FLM,LOW);  EXPO++;aso(); }  
  }

// open FL
void _SFLO(){
   // On stage load
  if(PSPO!=EXPO){  Serial.println("SFLO"); digitalWrite(FLM,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(FLO)==HIGH){ digitalWrite(FLM,LOW);  EXPO++;aso();}  
  }

// Enable FR
void _SFRM(){
   // On stage load
  if(PSPO!=EXPO){  Serial.println("SFRM"); digitalWrite(FRM,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(FAF)==HIGH){ digitalWrite(FRM,LOW);  EXPO++;aso();}  

  }

 
// Disable FR
void _SFRS(){
   // On stage load
  if(PSPO!=EXPO){  Serial.println("SFRS"); digitalWrite(FRM,LOW);PSPO = EXPO;}
  // On stage completed
   if(true){  EXPO++;aso();}  
  }



// Move MA and BA  till mark found used in initcond (NU)
void _SMAM(){ 
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SMAM"); digitalWrite(MAM,HIGH); PSPO = EXPO;}
  // On stage completed
  if(digitalRead(MAA)==HIGH){ digitalWrite(MAM,LOW);  EXPO++;aso(); }  
  }
// Stop MA  (NU)
void _SMAS(){
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SMAM"); digitalWrite(MAM,LOW);digitalWrite(BAM,LOW);PSPO = EXPO;}
  // On stage completed
  if(true){ EXPO++;aso(); }  
  } 

  // Move MA til next mark  and check if matches with MAB !! 
void _SMAN(){
  // On stage load
  if(PSPO!=EXPO){  Serial.println("SMAN"); digitalWrite(MAM,HIGH);digitalWrite(BAM,HIGH);PSPO = EXPO;}
  // On stage completed
  if(digitalRead(MAA)==LOW){ FNMAA=true; }  
  if(digitalRead(MAA)==HIGH && FNMAA){ 
    // roll not aligned error
    if(digitalRead(MAA)==LOW){EXDI=0;uiOutput(ERROR);Serial.write("ROLL NOT ALIGNED");return; }
    digitalWrite(MAM,LOW);digitalWrite(BAM,LOW);FNMAA = false;  EXPO++;aso(); 
    }  
  }

StageCollection STCO [] =  {
 _SPAB,
 _SPAF,
 _SPAHE,
 _SPAHD,
 _SPBB,
 _SPBF,
 _SPBHE,
 _SPBHD,
 _SFUC,
 _SFUO,
 _SFLC,
 _SFLO,
 _SFRM,
 _SFRS,
 _SMAM,
 _SMAS,
 _SMAN

 };
 
void Stage(uint8_t index){
EXPO = index;
STCO[EXSL[EXPO]]();  
}
#endif
