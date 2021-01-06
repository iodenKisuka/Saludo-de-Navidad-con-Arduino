#include <LiquidCrystal.h> // Libreria para que funcione el LCD
LiquidCrystal lcd(1, 0, A1, A2, 10, 9); // RS=1 , E=0, A1=D4, A2=D5, 10=D6, 9= D7 esta linea muestra en que pines debe ir conectado la pantalla LCD a nuestro Arduino

int pinLedR = 13; // pin Rojo del LED RGB
int pinLedV = A3; // pin verde
 
//frecuencias de las notas
#define DO4  262
#define RE4  294
#define MI4  330
#define FA4  349
#define FAS4  370
#define SOL4  392
#define LA4  440
#define LAS4  466
#define SI4  494
#define DO5  523
#define RE5  587

// Array de notas para We Wish You A Merry Christmas
int notes[54] = {
  DO4, FA4, FA4, SOL4, FA4, MI4, RE4, RE4, RE4, SOL4, SOL4, LA4, SOL4, FA4, MI4, DO4, DO4,
  LA4, LA4, LAS4, LA4, SOL4, FA4, RE4, DO4, DO4, RE4, SOL4, MI4, FA4, DO4, FA4, FA4, FA4,
  MI4, MI4, FA4, MI4, RE4, DO4, SOL4, LA4, SOL4, SOL4, FA4, FA4, DO5, DO4, DO4, DO4,
  RE4, SOL4, MI4, FA4
};

// Array de duracion de las notas, entre mas alto el valor mas corta la nota
int durations[54] = {
  2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 3, 3, 3, 3, 2, 2, 2,
  2, 3, 3, 3, 3, 2, 2, 3, 3, 2, 2, 2, 1, 2, 2, 2, 2,
  1, 2, 2, 2, 2, 1, 2, 2, 3, 3, 3, 3, 2, 2, 3, 3,
  2, 2, 2, 1
};

// Duracion inicial de la nota
int noteDuration = 900;
// Delay para tocar la siguiente nota
int noteDelay = noteDuration + 55;

// Variables para hacer transpose a las notas
int transposedNote;
int pinaltavoz = 3; //ubicacion del pin
int frecuencia;    // frecuencia correspondiente a la nota La

void setup()
{
  // inicializar el pin digital pinLedR como salida.
  pinMode(pinLedV, OUTPUT);
  pinMode(pinLedR, OUTPUT);
  
 
  
}

void loop()
{
  //Nota RE5
  frecuencia= 587 ;
  tone(pinaltavoz,frecuencia); // emite el tono
  lcd.begin(16, 2); // Con esta instrucción indicamos cual es la proporción de nuestro LCD
  lcd.print("25 de diciembre "); // Una instrucción muy importante ya que con esta imprimiremos el texto en nuestra pantalla
  delay(500);                 // lo mantiene medio segundos
  noTone(pinaltavoz);          // para el tono
  
  lcd.setCursor(0, 1); // con esta linea damos a entender que la primera fila de nuestro LCd ya esta siendo usada por lo cual queremos usar la segunda
  lcd.print(" Feliz Navidad");
  for (int i=0; i < sizeof(notes) / sizeof(int); i++) {
    digitalWrite(pinLedR, HIGH); // enciende el LED.
    analogWrite(pinLedV, 255);  // 255  pertenece a verde
    noteDelay = (noteDuration / durations[i]);
    tone(pinaltavoz, notes[i]);
    //si le pongo +500 anda mejor
    delay(noteDelay);
    lcd.clear (); // limpia la pantalla de LCd
    digitalWrite(pinLedR, LOW); // apaga el LED.
    digitalWrite(pinLedV, LOW); // apaga el LED.
    delay(500);
    noTone(pinaltavoz);
    lcd.print(" Feliz Navidad ");
    // Al ser colocadar debajo de la instrucción anterior, este mensaje se mostrara en la segunda fila del LCD
    
    }
  delay(noteDelay * 2);
    //}
}
