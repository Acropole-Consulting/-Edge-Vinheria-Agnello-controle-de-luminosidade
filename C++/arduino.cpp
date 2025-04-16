//====================================
//Project to monitor and alert high luminosity
//====================================
// Hardware Mapping
	// digitals pins
    #define ledVerde      13
    #define ledAmarelo    12
    #define ledVermelho   11
    #define buzzer 		   2
  // analog pin
    #define ldr  A0

// defining safe and moderate states
#define safeMode  740
#define moderateMode  940

// config cases with enum
enum Alarm {OFF, ALARM, PAUSE, EMERGENCE}; //alarm states
Alarm alarmState = OFF; //default alarm state 

// variebles of time
unsigned long alarmStart = 0; //counter relative

// time counter
#define FIRST_ALARM  3000
#define PAUSE_DURATION  5000
#define BIP  200

void setup(){
// Defining IO (input/output) pins
pinMode(ledVerde, OUTPUT);  
pinMode(ledVermelho, OUTPUT);
pinMode(ledAmarelo, OUTPUT);
pinMode(buzzer, OUTPUT);
Serial.begin(9600);
}

void loop(){

// Initializing and storing  millis(); counter
unsigned long now = millis();

// Storing analog read value from ldr
unsigned int ldrValue = analogRead(ldr);

//Printing ldrValue
//Serial.println(ldrValue);

standart();


if (ldrValue <= safeMode){
  
digitalWrite(ledVerde, HIGH);
    alarmState = OFF;
  
} else if (ldrValue <= moderateMode) {
  digitalWrite(ledAmarelo, HIGH);
    alarmState = OFF;
  
} else {
  
  digitalWrite(ledVermelho, HIGH);
  
  if (alarmState == OFF){
      alarmState = ALARM;
    // restart relative counter
        alarmStart = now; 
  }
    
}
 
//State machine: OFF -> ALARM -> PAUSE -> EMERGENCE
switch(alarmState){
    case ALARM:
  
    tone(buzzer, 2000);
    if (now - alarmStart >= FIRST_ALARM){
      noTone(buzzer);
      alarmStart = now;
      alarmState = PAUSE;
    }
  
    break;
  case PAUSE:
  
      if (now - alarmStart >= PAUSE_DURATION){
      alarmStart = now;
      alarmState = EMERGENCE;
    }
    //Serial.print("Tempo decorrido: ");
    //Serial.println(now - alarmStart);
  
    break;
  case EMERGENCE:
  
    if ((now - alarmStart) / BIP % 2 == 0){
        tone(buzzer, 2000);
    } else {
        tone(buzzer, 1500);
    }
  
    //Serial.print("Tempo decorrido: ");
    //Serial.print(now - alarmStart);
    //Serial.print(" | Cálculo: ");
    //Serial.print((now - alarmStart) / BIP);
    //Serial.print(" | Resto: ");
    //Serial.println((now - alarmStart) / BIP % 2);
  
    break;
  case OFF:
    
    noTone(buzzer);
  
    break;
}


}

void ledState(int pin, int state, char alarmState){
  digitalWrite(pin, state);
    alarmState = alarmState;
}

void standart(){
digitalWrite(ledVerde, LOW);
digitalWrite(ledVermelho, LOW);
digitalWrite(ledAmarelo, LOW);
}