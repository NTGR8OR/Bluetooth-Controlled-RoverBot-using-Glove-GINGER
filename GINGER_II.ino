#define arm 10
#define grip 11

#define En_b 3
#define In_4 4
#define In_3 5
#define In_2 6
#define In_1 7
#define En_a 9

char val = 0;
int speed = 0;
const int vel = 200;

void setup()
{
  pinMode(En_b, OUTPUT);
  pinMode(In_1, OUTPUT);
  pinMode(In_2, OUTPUT);
  pinMode(In_3, OUTPUT);
  pinMode(In_4, OUTPUT);
  pinMode(En_a, OUTPUT);
  Serial.begin(115200);
}

void loop()
{
  if (Serial.available())
  {
    val = Serial.read();
    Serial.println(val);
    switch (val)
    {
      case '+':
        if (speed <= 250)
        {
          speed = speed + 10;
          digitalWrite(In_1, 1);
          digitalWrite(In_2, 0);
          digitalWrite(In_3, 0);
          digitalWrite(In_4, 1);
          analogWrite(En_a, speed);
          analogWrite(En_b, speed);
          break;
        }

      case '-':
        if (speed >= 10)
        {
          speed = speed - 10;
          digitalWrite(In_1, 0);
          digitalWrite(In_2, 1);
          digitalWrite(In_3, 1);
          digitalWrite(In_4, 0);
          analogWrite(En_a, speed);
          analogWrite(En_b, speed);
          break;
        }
    }
    delay(20);
  }
}
