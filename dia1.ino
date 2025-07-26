const char* morseTable[26] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
  "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
  "..-", "...-", ".--", "-..-", "-.--", "--.."
};



void setup() {
  // put your setup code here, to run once:
pinMode(8, OUTPUT);
}

void punto() {
  digitalWrite(8, HIGH);
    delay(200);
  digitalWrite(8, LOW);
    delay(300);
}


void raya() {
  digitalWrite(8, HIGH);
    delay(1000);
  digitalWrite(8, LOW);
    delay(300);
}



void espacioLetra(){
  delay(2000);
}

void espacioPalabra() {
  delay(5000);
}

//void loop() {
  
void letraAMorse(char letra) {
  if (letra >= 'A' && letra <= 'Z') {
    const char* codigo = morseTable[letra - 'A'];
    for (int i = 0; codigo[i] != '\0'; i++) {
      if (codigo[i] == '.') {
        punto();
      } else if (codigo[i] == '-') {
        raya();
      }
    }
    delay(1000); //pausa entre letras
  } else if (letra == ' ') {
    delay(2000); //pausa entre palabras
  }
}

void loop() {
  char palabra[] = "lf";

  // Recorre la palabra y traduce
  for (int i = 0; palabra[i] != '\0'; i++) {
    char letra = toupper(palabra[i]); //convierte a mayúscula
    letraAMorse(letra);
  }
  delay(4000);
}

