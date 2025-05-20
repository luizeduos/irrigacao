// ##       ##  ##    ####    ######   ######   ####     ##  ##    ####     ####
// ##       ##  ##     ##         ##   ##       ## ##    ##  ##   ##  ##   ##  ##
// ##       ##  ##     ##        ##    ##       ##  ##   ##  ##   ##  ##   ##
// ##       ##  ##     ##       ##     ####     ##  ##   ##  ##   ##  ##    ####
// ##       ##  ##     ##      ##      ##       ##  ##   ##  ##   ##  ##       ##
// ##       ##  ##     ##     ##       ##       ## ##    ##  ##   ##  ##   ##  ##
// ######    ####     ####    ######   ######   ####      ####     ####     ####
//                            feito por luizeduos

#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN A1
#define DHTTYPE DHT22

const int sensorSolo = A0;
const int bombaAgua = 7;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);

unsigned long tempoAnterior = 0;
const unsigned long intervalo = 5000;
bool mostrarSolo = true;

void setup() {
  pinMode(bombaAgua, OUTPUT);
  digitalWrite(bombaAgua, LOW);

  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("  Bem-vindo a");
  lcd.setCursor(0, 1);
  lcd.print(" Mata Atlantica");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Elaborado por");
  lcd.setCursor(0, 1);
  lcd.print("Alunos do 1");
  lcd.print((char)223);
  lcd.print(" GA");
  delay(2000);
  lcd.clear();
}

void loop() {
  unsigned long tempoAtual = millis();

  int leituraSolo = analogRead(sensorSolo);
  int umidadeSolo = map(leituraSolo, 765, 425, 0, 100);
  umidadeSolo = constrain(umidadeSolo, 0, 100);

  float umidadeAr = dht.readHumidity();
  float temperatura = dht.readTemperature();

  if (isnan(umidadeAr) || isnan(temperatura)) {
    umidadeAr = 0;
    temperatura = 0;
  }

  bool irrigar = false;
  if (umidadeSolo < 50) {
    irrigar = true;
  } else if (umidadeSolo < 60 && umidadeAr < 70) {
    irrigar = true;
  }

  if (irrigar) {
    digitalWrite(bombaAgua, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("    Regando...");
    lcd.setCursor(0, 1);
    if(umidadeSolo < 10) {
      lcd.print("Solo:");
      lcd.print(umidadeSolo);
      lcd.print("%   Ar:");
      lcd.print((int)umidadeAr);
      lcd.print("%");
    } else {
      lcd.print("Solo:");
      lcd.print(umidadeSolo);
      lcd.print("%  Ar:");
      lcd.print((int)umidadeAr);
      lcd.print("%");
    }
  } else {
    digitalWrite(bombaAgua, LOW);

    if (tempoAtual - tempoAnterior >= intervalo) {
      tempoAnterior = tempoAtual;
      mostrarSolo = !mostrarSolo;
    }

    lcd.setCursor(0, 0);
    lcd.print(" Mata Atlantica");

    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);

    if (mostrarSolo) {
      if(umidadeSolo < 10) {
        lcd.print("Solo:");
        lcd.print(umidadeSolo);
        lcd.print("%   Ar:");
        lcd.print((int)umidadeAr);
        lcd.print("%");
      } else {
        lcd.print("Solo:");
        lcd.print(umidadeSolo);
        lcd.print("%  Ar:");
        lcd.print((int)umidadeAr);
        lcd.print("%");
      }
    } else {
      lcd.print("  Temp: ");
      lcd.print(temperatura, 1);
      lcd.print((char)223);
      lcd.print("C");
    }
  }

  Serial.print("Solo: ");
  Serial.print(umidadeSolo);
  Serial.print("% | Ar: ");
  Serial.print(umidadeAr);
  Serial.print("% | Temp: ");
  Serial.print(temperatura);
  Serial.println("C");

  delay(1000);
}
