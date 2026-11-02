#include <Servo.h>

Servo horizontal;        // Horizontal Servo Motor
int servohori = 180;
int servohoriLimitHigh = 175;
int servohoriLimitLow  = 5;

Servo vertical;          // Vertical Servo Motor
int servovert = 45;
int servovertLimitHigh = 100;
int servovertLimitLow  = 1;

// LDR pin connections
int ldrlt = A0;  // Bottom Left  LDR
int ldrrt = A3;  // Bottom Right LDR
int ldrld = A1;  // Top Left     LDR
int ldrrd = A2;  // Top Right    LDR

int servohori1 = 1500; 
int servovert1 = 1500; 

void setup() {
  horizontal.attach(2);
  horizontal.write(90);
 // vertical.write(90);

   // horizontal.writeMicroseconds(servohori1); 
 // vertical.writeMicroseconds(servovert1);   
  delay(1000);
      Serial.begin(9600);


}

void loop2()
{
  horizontal.write(30);

}



void loop1() {
  // 1. Fast Sweep forward from 0 to 300 degrees (jumping 5 degrees at a time)
  for (int angle = 0; angle <= 360; angle += 5) {
    // Map degrees (0-300) to raw pulse width timing (500-2500 microseconds)
    int pulse = map(angle, 0, 300, 500, 2500); 
    
    //horizontal.writeMicroseconds(pulse);
    vertical.writeMicroseconds(pulse); 
    delay(15); // Reduced from 15 to 5 for much faster speed
  }
  
  delay(500); // Shorter pause at the end

  // 2. Fast Sweep back from 300 to 0 degrees
  for (int angle = 360; angle >= 0; angle -= 5) {
    int pulse = map(angle, 0, 300, 500, 2500); 
    
   // horizontal.writeMicroseconds(pulse);
    vertical.writeMicroseconds(pulse); 
    delay(15); 
  }
  
  delay(500); 
}

void loop() {


  /*int lt = analogRead(ldrlt);
  int rt = analogRead(ldrrt);
  int ld = analogRead(ldrld);
  int rd = analogRead(ldrrd);
  
  /*printValues(lt);
  printValues(rt);
  printValues(ld);
  printValues(rd);*/

    for (int angle = 0; angle <= 180; angle += 1) {
    horizontal.write(angle);
    //vertical.write(map(angle, 0, 180, 1, 100)); // Keeps vertical within 1-100 limits
    delay(10); // Adjust this number to change the movement speed
  }
  
  delay(1000); // Pause for 1 second at the end

  // 2. Sweep back from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 1) {
    horizontal.write(angle);
   // vertical.write(map(angle, 0, 180, 1, 100)); 
    delay(10); 
  }
  delay(100);

  /*int dtime = 10;
  int tol   = 90;  // Tolerance — adjust for sensitivity

  int avt = (lt + rt) / 2;  // Average top
  int avd = (ld + rd) / 2;  // Average bottom
  int avl = (lt + ld) / 2;  // Average left
  int avr = (rt + rd) / 2;  // Average right

 

  int dvert  = avt - avd;
  int dhoriz = avl - avr;

  if (abs(dvert) > tol) {
    if (avt > avd) {
      servovert = ++servovert;
      if (servovert > servovertLimitHigh) servovert = servovertLimitHigh;
    } else {
      servovert = --servovert;
      if (servovert < servovertLimitLow) servovert = servovertLimitLow;
    }
    vertical.write(servovert);
  }

  if (abs(dhoriz) > tol) {
    if (avl > avr) {
      servohori = --servohori;
      if (servohori < servohoriLimitLow) servohori = servohoriLimitLow;
    } else {
      servohori = ++servohori;
      if (servohori > servohoriLimitHigh) servohori = servohoriLimitHigh;
    }
    horizontal.write(servohori);
  }

  delay(dtime);*/
}

void printValues(int l) {
  Serial.print("ppm: ");
  Serial.println(l);
}