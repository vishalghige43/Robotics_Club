volatile signed temp, counter = 0;
#define dir 7
#define pwm 6
int motorspeed;
int kp=1.77;//maxspeed=kp*error;
int kd=1;
int error;
int target=144;
int prverror;

void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);//>>ENCODER--PIN
  pinMode(3,INPUT_PULLUP);//>>ENCODER--PIN
  pinMode(pwm,OUTPUT);
  pinMode(dir,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), ai0, RISING);//>>ENCODER--PIN_INTERRUPT
  attachInterrupt(digitalPinToInterrupt(3), ai1, RISING);//>>ENCODER--PIN_INTERRUPT
}
void loop() {
  digitalWrite(dir,LOW);
  error=target-counter;
  error=map(error,0,144,0,255);
  prverror=error
   if(error<=0){
    while(true);}
//  motorspeed=kp*error;
  motorspeed=kp*error+kd*(prverror-error);
  if(motorspeed<0)motorspeed=0; //MINRange of speed
  if(motorspeed>=100)motorspeed=100;//MAXRange of speed
  
 
  analogWrite(pwm,motorspeed);
  
  
  //ENCODER---SERIALPRINT
  if(counter>1000 ||counter<-1000)
    counter=0;
  if( counter != temp ){
    Serial.println (counter);
    temp = counter;
  }
}
//<<ENCODER--COUNT>>
void ai0() {
  if(digitalRead(3)==LOW) counter++;
  
  else counter--;
}
void ai1() {
  if(digitalRead(2)==HIGH) counter++;
  
  else counter--;
}
//----------//
