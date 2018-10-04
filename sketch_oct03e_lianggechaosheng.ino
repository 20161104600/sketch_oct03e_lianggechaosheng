#include <Servo.h>
Servo myservo;
#define TrigPin1 A0
#define EchoPin1 A1
#define TrigPin2 A2
#define EchoPin2 A3
#define TrigPin3 A4
#define EchoPin3 A5
#define TrigPin4 A6
#define EchoPin4 A7
float cm;
float cm1;
void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  pinMode(TrigPin2, OUTPUT);
  pinMode(EchoPin2, INPUT);
  pinMode(TrigPin3, OUTPUT);
  pinMode(EchoPin3, INPUT);
  pinMode(TrigPin4, OUTPUT);
  pinMode(EchoPin4, INPUT);
  myservo.attach(30);
}
void chaosheng1()
{
  digitalWrite(TrigPin1, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin1, LOW);

  cm1 = pulseIn(EchoPin1, HIGH) / 58.0; //将回波时间换算成cm
  cm1 = (int(cm1 * 100.0)) / 100.0; //保留两位小数
  Serial.print(cm1);
  Serial.print("cm1");
  Serial.println("     ");
}
void loop()
{
  chaosheng1();
  delay(100);
}
