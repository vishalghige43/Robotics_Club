volatile signed temp, counter = 0; //This variable will increase or decrease depending on the rotation of encoder
    
void setup() {
  Serial.begin (9600);
  
  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  pinMode(3, INPUT_PULLUP); // internalเป็น pullup input pin 3
   //Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(2), ai0, RISING);
//  attachInterrupt(digitalPinToInterrupt(2), ai00, FALLING);
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(3), ai1, RISING);
//  attachInterrupt(digitalPinToInterrupt(3), ai01, FALLING);

  }
   
  void loop() {
  // Send the value of counter
  if(counter>1000 ||counter<-1000){
    counter=0;
  }
  if( counter != temp ){
  Serial.println (counter);
  temp = counter;

  }
  
  }
  
   
  void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW){
  counter++;
  }
 
  else{
  counter--;
  }
  
  }
//  void ai00(){
//    if(digitalRead(3)==HIGH){
//  counter++;
//  }
// 
//  else{
//  counter--;
//  }
//  }
//   
  void ai1() {
  // ai0 is activated if DigitalPin nr 3 is going from LOW to HIGH
  // Check pin 2 to determine the direction
  if(digitalRead(2)==HIGH) {
  counter++;
  }
  
  else{
  counter--;
  }
  }
  //void ai01(){
//    if(digitalRead(2)==LOW) {
//  counter++;
//  }
//  
//  else{
//  counter--;
//  }
//  }
