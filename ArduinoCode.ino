#define Rp 2
#define Lp 4
#define Rm 3
#define Lm 5

int TP1 = 13, EP1 = 12, TP2 = 11, EP2 = 10;
long echo;
float LDist, RDist;


void Forward() {
  digitalWrite(Rp, HIGH);
  digitalWrite(Lp, HIGH);
  digitalWrite(Rm, LOW);
  digitalWrite(Lm, LOW);
  Serial.println("Forward");
}
void Backward() {
  digitalWrite(Rp, LOW);
  digitalWrite(Lp, LOW);
  digitalWrite(Rm, HIGH);
  digitalWrite(Lm, HIGH);
  Serial.println("Backward");
}
void Right() {
  digitalWrite(Rp, LOW);
  digitalWrite(Lp, HIGH);
  digitalWrite(Rm, HIGH);
  digitalWrite(Lm, LOW);
  Serial.println("Right");
}
void Left() {
  digitalWrite(Rp, HIGH);
  digitalWrite(Lp, LOW);
  digitalWrite(Rm, LOW);
  digitalWrite(Lm, HIGH );
  Serial.println("Left");
}

void Stop() {
  digitalWrite(Rp, LOW);
  digitalWrite(Lp, LOW);
  digitalWrite(Rm, LOW);
  digitalWrite(Lm, LOW);


}

void setup() {
  Serial.begin(9600);
  pinMode(Rp, OUTPUT);
  pinMode(Lp, OUTPUT);
  pinMode(Rm, OUTPUT);
  pinMode(Lm, OUTPUT);

  pinMode(TP1, OUTPUT);
  pinMode(TP2, OUTPUT);
  pinMode(EP1, INPUT);
  pinMode(EP2, INPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char a = Serial.read();
    switch (a) {
      case 'F':
        Forward();
        break;
      case 'B':
        Backward();
        break;
      case 'R':
        Right();
        break;
      case 'L':
        Left();
        break;
      case 'S':
        Stop();
        break;
    }
  }
  Serial.println(">");
}

void SONARL() {
  digitalWrite(TP1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP1, LOW);
  echo = pulseIn(EP1, HIGH);
  LDist = 0.0001 * ((float)echo * 340.0) / 2.0);
  Serial.print("L" + String(LDist));

}


void SONARR() {
  digitalWrite(TP2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TP2, LOW);
  echo = pulseIn(EP2, HIGH);

  LDist = 0.0001 * ((float)echo * 340.0) / 2.0);

}
