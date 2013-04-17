
char inChar = -1;
int led = 13;

void setup() {
  Mouse.begin();

  Serial.begin(9600);
  Serial.println("Hello world");

  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     

}

void loop() {

  delay(1000);
  
//  if (Serial.available() > 0) {
//    inChar = Serial.read();
//    if (inChar >= '0' && inChar <= '9') {
//      Serial.print(inChar);
//      int moveSize = -(inChar - '0');
//      Mouse.move(moveSize, 0, 0);
//    }
//
//    // move the mouse:
//  }
  
//  Mouse.move(-10, 0, 0);
  
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(200);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second


}
