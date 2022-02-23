void setup() {
  pinMode(0,INPUT);
  pinMode(3,OUTPUT);
  pinMode(1,INPUT);
  pinMode(2,INPUT);
 }

void NRZL()
{
  if(digitalRead(0)==0)
  {
    digitalWrite(3,1);  // 1 means HIGH   0 means LOW  
  }
  else
  {
    digitalWrite(3,0);
  }
}

void MANCHESTER(){
  if(digitalRead(0)==0)
  {
    // high to low transition on the center of pulse
    digitalWrite(3,1);
    delay(500); // this means 500 milliseconds
    digitalWrite(3,0);
    delay(500);
  }
  else    /// this is 1
  {
     // low to high transition on the center of pulse
    digitalWrite(3,0);
    delay(500); // this means 500 milliseconds
    digitalWrite(3,1);
    delay(500);
  }
  
  }

 //0 = no transition; 1 = have transition
void NRZI(){
  digitalWrite(3,0);  //set first value to high
  
  if(digitalRead(0) == 0)
  {
    //no transition
    if(digitalRead(3) == 0)
      digitalWrite(3, 1); 
    else
      digitalWrite(3, 0);
  } 
  else
  {
    if(digitalRead(3)==0)
      digitalWrite(3, 0); //transition to high
    else
      digitalWrite(3, 1);
  }
}

//0 = no inversion; 1 = inversion
void DIFFMAN(){
  digitalWrite(3,1);  //assume first value is high
  
  if(digitalRead(0)==0)
  {
    if(digitalRead(3) == 0)
    {
      //no transition
      digitalWrite(3,1);
      delay(500);
      digitalWrite(3,0);
      delay(500);
    }
    else
    {
      //transition high to low in the middle
      digitalWrite(3,0);  //no inversion
      delay(500);
      digitalWrite(3,1);
      delay(500);
    }
  }
  else
  {
    if(digitalRead(3) == 0)
    {
      //no transition
      digitalWrite(3,0);
      delay(500);
      digitalWrite(3,1);
      delay(500);
    }
    else
    {
      //transition high to low in the middle
      digitalWrite(3,1);  //no inversion
      delay(500);
      digitalWrite(3,0);
      delay(500);
    }
  }
} 

void loop() {
  //00 --> NRZL
  if(digitalRead(1)==0 && digitalRead(2)==0)
      NRZL();
  
  //10 -->MANCHESTER
  if(digitalRead(1)==0 && digitalRead(2)==1)
     MANCHESTER();

  //01 -->NRZI
  if(digitalRead(1)==1 && digitalRead(2)==0)
     NRZI();

  //11  --> DIFFMAN
  if(digitalRead(1)==1 && digitalRead(2)==1)
     DIFFMAN();


 // additional points for BIPOLAR AMI and PSEUDOTERNARY. If you wish to do this, // you need to add 1 3rd bit in the protocol selection pins… 
}
