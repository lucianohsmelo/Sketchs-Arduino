int led1 =  7;
 int led2 =  8;
 int led3 =  9;
 int led4 =  10;
 int led5 =  11;
 int led6 =  6;
 
 boolean warmUp = true;
 
// The setup() method runs once, when the sketch starts
 
void setup()   {
 // initialize the digital pins as outputs
 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
 pinMode(led6, OUTPUT);
 
for (int i=20; i>0; i--) {
       pulseCoilsMicro(10000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(9000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(8000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(7500);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(7000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(6500);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(6000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(5500);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(5000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(4500);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(4000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(3500);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(3100);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(3000);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(2900);
     }
 
     for (int i=20; i>0; i--) {
       pulseCoilsMicro(2800);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2750);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2700);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2650);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2600);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2550);
     }
 
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2500);
     }
     
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2450);
     }
     
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2400);
     }
     
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2350);
     }
   
    for (int i=40; i>0; i--) {
       pulseCoilsMicro(2300);
     }
   
    for (int i=40; i>0; i--) {
       pulseCoilsMicro(2250);
     }
   
    for (int i=40; i>0; i--) {
       pulseCoilsMicro(2200);
     }
   
    for (int i=40; i>0; i--) {
       pulseCoilsMicro(2150);
     }
   
    for (int i=40; i>0; i--) {
       pulseCoilsMicro(2100);
     }
     
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(2050);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(2000);
     }
     
     for (int i=40; i>0; i--) {
       pulseCoilsMicro(1950);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1900);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1850);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1800);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1750);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1700);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1650);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1600);
     }
     
     for (int i=80; i>0; i--) {
       pulseCoilsMicro(1550);
     }
     
     for (int i=120; i>0; i--) {
       pulseCoilsMicro(1500);
     }
     
     for (int i=200; i>0; i--) {
       pulseCoilsMicro(1450);
     }
 }
 
// the loop() method runs over and over again,
 // as long as the Arduino has power
 /*
 LESD1, LED3, and LED5 will be positive, LED2, LED4, and LED6 are negative.
 You will notice that two LEDs are on at the same time so that one of the
 three motor coils are energised at a time.
 */
 void loop()
 {
//   if (warmUp) {
     
     
//     for (int i=1000; i>0; i--) {
//       pulseCoilsMicro(1440);
//     }
//    
//     for (int i=1000; i>0; i--) {
//       pulseCoilsMicro(1430);
//     }
//    
//     for (int i=400; i>0; i--) {
//       pulseCoilsMicro(1400);
//     }
//    
//     for (int i=400; i>0; i--) {
//       pulseCoilsMicro(1395);
//     }
//    
//     for (int i=400; i>0; i--) {
//       pulseCoilsMicro(1390);
//     }
//    
//     for (int i=200; i>0; i--) {
//       pulseCoilsMicro(1380);
//     }
//    
//     for (int i=160; i>0; i--) {
//       pulseCoilsMicro(1300);
//     }
//    
//     for (int i=160; i>0; i--) {
//       pulseCoilsMicro(1250);
//     }
//    
//     for (int i=160; i>0; i--) {
//       pulseCoilsMicro(1200);
//     }
//    
//     for (int i=200; i>0; i--) {
//       pulseCoilsMicro(1150);
//     }
//    
//     for (int i=200; i>0; i--) {
//       pulseCoilsMicro(1100);
//     }
//    
//     for (int i=200; i>0; i--) {
//       pulseCoilsMicro(1050);
//     }
 
//       warmUp = false;
//   }
 
   pulseCoilsMicro(1450);
 }
 
 void pulseCoilsMicro(int delayMicroSeconds) {
   digitalWrite(led5, LOW);    // set the fifth LED off
   digitalWrite(led1, HIGH); // set the first LED on
 
   delayMicroseconds(delayMicroSeconds);                 // wait for a period of time
 
   digitalWrite(led6, LOW);    // set the sixth LED off
   digitalWrite(led2, HIGH);   // set the second LED on
 
   delayMicroseconds(delayMicroSeconds);                 // wait for a period of time
 
   digitalWrite(led1, LOW);    //repeat ect.
   digitalWrite(led3, HIGH);
 
   delayMicroseconds(delayMicroSeconds);
 
   digitalWrite(led2, LOW);
   digitalWrite(led4, HIGH);
 
   delayMicroseconds(delayMicroSeconds);
 
   digitalWrite(led3, LOW);
   digitalWrite(led5, HIGH);
 
   delayMicroseconds(delayMicroSeconds);
 
   digitalWrite(led4, LOW);
   digitalWrite(led6, HIGH);
 
   delayMicroseconds(delayMicroSeconds);
 }
 
 void pulseCoilsMilli(int delayMilliSeconds) {
   digitalWrite(led5, LOW);    // set the fifth LED off
   digitalWrite(led1, HIGH); // set the first LED on
 
   delay(delayMilliSeconds);                 // wait for a period of time
 
   digitalWrite(led6, LOW);    // set the sixth LED off
   digitalWrite(led2, HIGH);   // set the second LED on
 
   delay(delayMilliSeconds);                 // wait for a period of time
 
   digitalWrite(led1, LOW);    //repeat ect.
   digitalWrite(led3, HIGH);
 
   delay(delayMilliSeconds);
 
   digitalWrite(led2, LOW);
   digitalWrite(led4, HIGH);
 
   delay(delayMilliSeconds);
 
   digitalWrite(led3, LOW);
   digitalWrite(led5, HIGH);
 
   delay(delayMilliSeconds);
 
   digitalWrite(led4, LOW);
   digitalWrite(led6, HIGH);
 
   delay(delayMilliSeconds);
 }
