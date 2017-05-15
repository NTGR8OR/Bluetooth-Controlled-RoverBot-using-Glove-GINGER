int F[4] = {A0, A1, A2, A3};
int val = 0;

void setup()
{
  Serial.begin(115200);
  for (int i = 0; i < 4; i++)
  {
    pinMode(F[i], INPUT);
  }
}

void loop()
{
  for (int i = 0; i < 4; i++)
  {
    val = analogRead(F[i]);
    Serial.print(val);
    Serial.print("  ");
  }
  Serial.println("");
  delay(100);
}
