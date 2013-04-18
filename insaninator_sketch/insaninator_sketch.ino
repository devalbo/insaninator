
bool firstPass = true;
int led = 13;
unsigned long nextTwitchTime = 0;

void setup() {
  Mouse.begin();

  Serial.begin(9600);
//  Serial.println("Engaging the insaninator. Prepare for insanination!");

  Mouse.move(-100, 0, 0);
  Mouse.move(0, 50, 0);

  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);   
  randomSeed(analogRead(0));  

}

void loop() {
  if (firstPass) {
    delay(1000);
    Mouse.move(-100, 0, 0);
    delay(1000);
    Mouse.move(0, -50, 0);
    delay(1000);
    
    calculateAndSetActionDelay();
    digitalWrite(led, HIGH);
//    Serial.println("First pass complete.");

    firstPass = false;
  }

  if (shouldDoTwitch()) {
    digitalWrite(led, LOW);
    Serial.println("TWITCHING");
    doTwitchyBehaviors();
    calculateAndSetActionDelay();
    digitalWrite(led, HIGH);
  }

}

boolean shouldDoTwitch() {
  unsigned long currentTime = millis();
  if (currentTime > nextTwitchTime) {
    return true;
  }
  delay(1000);
  return false;
}

void calculateAndSetActionDelay() {
  const unsigned long DELAY_TIME_MS_MIN = 60000;    // 1 minute
  const unsigned long DELAY_TIME_MS_MAX = 1800000;  // 1/2 hour
  const unsigned long WAIT_RANGE = DELAY_TIME_MS_MAX - DELAY_TIME_MS_MIN;
  unsigned long delay_time_ms = random(0, WAIT_RANGE);

  unsigned long currentTime = millis();
  nextTwitchTime = currentTime + delay_time_ms;
//  Serial.println("CURRENT TIME: " + String(currentTime));
//  Serial.println("ACTION DELAY: " + String(delay_time_ms));
//  Serial.println("NEXT TWITCH TIME: " + String(nextTwitchTime));
}

void doTwitchyBehaviors() {
  int twitchy_behavior_count = random(2, 10);
//  Serial.println("DOING " + String(twitchy_behavior_count) + " TWITCHES");
  for (int i = 0; i < twitchy_behavior_count; i++) {
//    Serial.println("TWITCH #" + String(i + 1));
    doMouseMotion();
    doTwitchDelay();
  }
}

void doMouseMotion() {
  int xMove = random(-50, 50);
  int yMove = random(-50, 50);
  Mouse.move(xMove, yMove, 0);
}

void doMouseMotion2() {
  bool horizontalMove = random(0, 2);
  bool verticalMove = random(0, 2);

  int xMove = 0;
  int yMove = 0;
  if (horizontalMove) {
    xMove = random(-50, 50);
  }
  if (verticalMove) {
    yMove = random(-50, 50);
  }

  Mouse.move(xMove, yMove, 0);
}

void doTwitchDelay() {
  unsigned long DELAY_TIME_MS_MIN = 50;
  unsigned long DELAY_TIME_MS_MAX = 750;
  unsigned long delay_time_ms = random(DELAY_TIME_MS_MIN, DELAY_TIME_MS_MAX + 1);
  
//  Serial.println("TWITCH DELAY: " + String(delay_time_ms));
  delay(delay_time_ms);
}
