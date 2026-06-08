#define A1 8
#define A2 9
#define ENA 10

void setup()
{
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop()
{
  // Forward
  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  analogWrite(ENA, 255);
  delay(3000);

  // Stop
  analogWrite(ENA, 0);
  delay(1000);

  // Reverse
  digitalWrite(A1, LOW);
  digitalWrite(A2, HIGH);
  analogWrite(ENA, 255);
  delay(3000);

  // Stop
  analogWrite(ENA, 0);
  delay(1000);
}