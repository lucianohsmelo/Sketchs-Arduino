#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
#define INTERNAL INTERNAL1V1
#endif

#define pinBtn 2
#define pinYawCCW 3
#define pinYawCW 5
#define pinPitch 6
#define pinLedGreen 9
#define pinLedRed 10
int startStop;

void setup() {
  Serial.begin(115200);
   pinMode(pinBtn, INPUT);
  pinMode(pinPitch,OUTPUT);
  pinMode(pinYawCW,OUTPUT);
  pinMode(pinYawCCW,OUTPUT);
  pinMode(pinLedGreen, OUTPUT);
  pinMode(pinLedRed, OUTPUT);
  startStop = 1;
  digitalWrite(pinLedGreen, 1);
  digitalWrite(pinLedRed, 0);
}
void loop() {
  static int  s   = -1;
  static int  pin = 13;
  int  val =  0;
  int  agv =  0;
  int  dgv =  0;

  if (digitalRead(pinBtn) == 1) {
    if (startStop == 0) {
      startStop = 1;
      digitalWrite(pinLedGreen, 1);
      digitalWrite(pinLedRed, 0);
    } else {
      startStop = 0;
      digitalWrite(pinLedGreen, 0);
      digitalWrite(pinLedRed, 1);
      analogWrite(pinPitch,  0);
      analogWrite(pinYawCW,  0);
      analogWrite(pinYawCCW,  0);
    }
    delay(250);
  }


  if (Serial.available() > 0) {
    val = Serial.read();
    switch (s) {
      case -1:
        if (val > 47 && val < 90) {
          s = 10 * (val - 48);
        }
        if ((s > 40 && s < 90) || (s > 90 && s != 340 && s != 400)) {
          s = -1;
        }
        break;
      case 0:
        if (val > 98 && val < 167) {
          pin = val - 97;
          s = 1;
        }
        else {
          s = -1;
        }
        break;
      case 1:
        if (val > 47 && val < 50) {
          if (val == 48) {
            pinMode(pin, INPUT);
          }
          else {
            pinMode(pin, OUTPUT);
          }
        }
        s = -1;
        break;
      case 10:
        if (val > 98 && val < 167) {
          pin = val - 97;
          dgv = digitalRead(pin);
          Serial.println(dgv);
        }
        s = -1;
        break;
      case 20:
        if (val > 98 && val < 167) {
          pin = val - 97;
          s = 21;
        }
        else {
          s = -1;
        }
        break;
      case 21:
        if (val > 47 && val < 50) {
          dgv = val - 48;
          digitalWrite(pin, dgv);
        }
        s = -1;
        break;
      case 30:
        if (val > 96 && val < 113) {
          pin = val - 97;
          agv = analogRead(pin);
          Serial.println(agv);
        }
        s = -1;
        break;
      case 40:
        if (val > 98 && val < 167) {
          pin = val - 97;
          s = 41;
        }
        else {
          s = -1;
        }
        break;
      case 41:
        analogWrite(pin, val);
        s = -1;
        break;
      case 90:
        if (val == 57) {
          Serial.println(0);
        }
        s = -1;
        break;
      case 340:
#if defined(__AVR__) || defined(__PIC32MX__)
        switch (val) {
          case 48:
            analogReference(DEFAULT);
            break;
          case 49:
            analogReference(INTERNAL);
            break;
          case 50:
            analogReference(EXTERNAL);
            break;
          default:
            break;
        }
#endif

        s = -1;
        break;
      case 400:
        Serial.println(val);
        s = -1;
        break;
      default:
        s = -1;
    }
  }
}

