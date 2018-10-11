#include <Servo.h>
Servo myservo;
#define TrigPin1 2
#define EchoPin1 3
#define TrigPin2 4
#define EchoPin2 5
#define TrigPin3 6
#define EchoPin3 7
float cm;
float cm1,cm2,cm3;
void setup()
{
  Serial.begin(9600);
  pinMode(TrigPin1, OUTPUT);
  pinMode(EchoPin1, INPUT);
  pinMode(TrigPin2, OUTPUT);
  pinMode(EchoPin2, INPUT);
  pinMode(TrigPin3, OUTPUT);
  pinMode(EchoPin3, INPUT);
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
void chaosheng2()
{
  digitalWrite(TrigPin2, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin2, LOW);
  cm2 = pulseIn(EchoPin2, HIGH) / 58.0; //将回波时间换算成cm
  cm2 = (int(cm2 * 100.0)) / 100.0; //保留两位小数
  Serial.print(cm2);
  Serial.print("cm2");
  Serial.println("     ");
}
void chaosheng3()
{
  digitalWrite(TrigPin3, LOW); //低高低电平发一个短时间脉冲去TrigPin
  delayMicroseconds(2);
  digitalWrite(TrigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin3, LOW);
  cm3 = pulseIn(EchoPin3, HIGH) / 58.0; //将回波时间换算成cm
  cm3 = (int(cm3 * 100.0)) / 100.0; //保留两位小数
  Serial.print(cm3);
  Serial.print("cm3");
  Serial.println("     ");
}
void loop()
{
  chaosheng1();
  chaosheng2();
  chaosheng3(); 
  Serial.println("==================");
  delay(200);
}
