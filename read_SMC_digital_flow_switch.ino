int blackWire = 0;//3;
int blackValue = 0;

int blackWire_DFS = 2; //0 is RED 1 is BLUE 2 is GREEN 3 is YELLOW
int blackValue_DFS; 
float DFS_on_threshold = 2.5, max_blackWire_Volt = 4.0;

#define pin_relay_DFS1 0 

#define IN1 12

void setup() {
  Serial.begin(9600);
  //pinMode(whiteWire, INPUT);
  //pinMode(blackWire, INPUT);
  //pinMode(pin_relay_DFS1,OUTPUT);
  pinMode(IN1, OUTPUT);
  digitalWrite(IN1,LOW);
  digitalWrite(pin_relay_DFS1,LOW);
}

void loop() {
  //blackValue = digitalRead(blackWire);
//  blackValue = analogRead(blackWire);
//  delay(100);
//  Serial.println(blackValue);
//  delay(100);
  blackValue_DFS = analogRead(blackWire_DFS);
  blackValue_DFS = map(blackValue_DFS,0,1023,0.0,max_blackWire_Volt);
  Serial.print(DFS_on_threshold);
  Serial.print(",");
  Serial.println(blackValue_DFS);
  if (blackValue_DFS >= DFS_on_threshold){
    Serial.println("EE: Suction cups on DFS ON.");
  }
  else{
    Serial.println("EE: Suction cups on DFS are not ON yet. Try again.");
  }
  delay(250);
}
