int rolePin = 2;
int nemPin = A0;

int nemdegeri;
int nemEsikdegeri = 15;

//Toprak nem değeri yüzde 15'in altına düştüğünde su pompası çalışmaya başlayacak
//nem oranı degiştirilebilir
void setup()
{
  pinMode(rolePin, OUTPUT);
  pinMode(nemPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  nemdegeri = map(analogRead(nemPin),1023,0,0,100);
  Serial.print("Nem Değeri: %"); //seri monitörde nem oranı gözükmekte
  Serial.println(nemdegeri);

  if(nemdegeri > nemEsikdegeri)
  {
    digitalWrite(rolePin, HIGH);
  }
  else
  {
    digitalWrite(rolePin, LOW);
  }
  
  delay(100);
}
