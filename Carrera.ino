//**************************** VARIABLES GLOBALES ****************************
int start = 2; // Boton para iniciar
int push = 31; // Botones para avanzar
int push2 = 17;
int red = 30; // Led rojo
int blue = 40; // Led azul
int green = 39; // Led verde
int bandera = 0; // Bandera que indica si se empezó el juego
int cont1 = 0; // Contadores a incrementar
int cont2 = 0;
void Inc_cont(int jugador); // Funciones
void LEDS(int jugador, int contador);
void Comparador(int contjugador1, int contjugador2);

//*********************************** SETUP ***********************************
void setup() {
  pinMode(start, INPUT_PULLUP); // Botones
  pinMode(push, INPUT_PULLUP); // Pull up para usar boton integrado
  pinMode(push2, INPUT_PULLUP); // Pull up para usar boton integrado
  pinMode(red, OUTPUT); // Leds del RGB integrado
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);  
  pinMode(19, OUTPUT); // Pines de LEDs jugador 1
  pinMode(18, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(15, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(3, OUTPUT); // Pines de LEDs jugador 2
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

//*********************************** LOOP ***********************************
void loop() {

  // Esperar a que empiece el juego
  if (bandera == 0){
    if(digitalRead(start) == 0){ // Boton presionado
      bandera = 1;
    }
  }

  // Empezar juego
  if (bandera == 1){ 
    // Secuencia de inicio
    digitalWrite(red, 1); // Color rojo
    delay(1000);
    digitalWrite(green, 1); // Color amarillo
    delay(1000);
    digitalWrite(red, 0);
    digitalWrite(green, 1); // Color verde
    delay(1000);
    digitalWrite(green, 0);
    bandera = 2;
  }

  // Aumentar contador de jugadores
  if (bandera == 2){ 
    // Incrementar jugador 2
    if (digitalRead(push) == 0){
      while(digitalRead(push) == 0){
      }
      Inc_cont(2);
    }
    // Incrementar jugador 1
    if (digitalRead(push2) == 0){
      while(digitalRead(push2) == 0){
      }
      Inc_cont(1);
    }
    bandera = 3;
  }

  // Encender LEDs
  if (bandera == 3){
    // Leds jugador 1
    LEDS(1, cont1);
    
    // Leds jugador 2
    LEDS(2, cont2);
    bandera = 2;
  }

  // Compara y termina el juego
  Comparador(cont1, cont2);
}

//********************************* FUNCIONES *********************************
// Funcion para incrementar contadores
void Inc_cont(int jugador){
  if (jugador == 1){
    cont1 = cont1 + 1;
    if (cont1 == 9){ // Limite para el contador 1
      cont1 = 0;
    }
  }
  if (jugador == 2){
    cont2 = cont2 + 1;
    if (cont2 == 9){ // Limites para el contador 2
      cont2 = 0;
    }
  }
}

 // Funcion para endender LEDs
void LEDS(int jugador, int contador){
  // Leds jugador 1
  if (jugador == 1){
    switch (contador) {
      case 0:
        digitalWrite(12, 0);
        digitalWrite(13, 0);
        digitalWrite(14, 0);
        digitalWrite(15, 0);
        digitalWrite(11, 0);
        digitalWrite(32, 0);
        digitalWrite(18, 0);
        digitalWrite(19, 0);
        break;
      case 1:
        digitalWrite(11, 1);
        break;
      case 2:
        digitalWrite(12, 1);
        break;
      case 3:
        digitalWrite(13, 1);
        break;
      case 4:
        digitalWrite(14, 1);
        break;
      case 5:
        digitalWrite(15, 1);
        break;
      case 6:
        digitalWrite(32, 1);
        break;
      case 7:
        digitalWrite(18, 1);
        break;
      case 8:
        digitalWrite(19, 1);
        break;
      default:
        digitalWrite(12, 0);
        digitalWrite(13, 0);
        digitalWrite(14, 0);
        digitalWrite(15, 0);
        digitalWrite(11, 0);
        digitalWrite(32, 0);
        digitalWrite(18, 0);
        digitalWrite(19, 0);
    }
  }
  
    // Case con pines de leds de jugador 2 
  if (jugador == 2){
    switch (contador) {
      case 0:
        digitalWrite(3, 0);
        digitalWrite(4, 0);
        digitalWrite(5, 0);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
        digitalWrite(10, 0);
        break;
      case 1:
        digitalWrite(3, 1);
        break;
      case 2:
        digitalWrite(4, 1);
        break;
      case 3:
        digitalWrite(5, 1);
        break;
      case 4:
        digitalWrite(6, 1);
        break;
      case 5:
        digitalWrite(7, 1);
        break;
      case 6:
        digitalWrite(8, 1);
        break;
      case 7:
        digitalWrite(9, 1);
        break;
      case 8:
        digitalWrite(10, 1);
        break;
      default:
        digitalWrite(3, 0);
        digitalWrite(4, 0);
        digitalWrite(5, 0);
        digitalWrite(6, 0);
        digitalWrite(7, 0);
        digitalWrite(8, 0);
        digitalWrite(9, 0);
        digitalWrite(10, 0);
    }
  }
}

// Funcion de comparación de contadores
void Comparador(int contjugador1, int contjugador2){
  if (contjugador1 == 8){{ // Si gana el jugador 1
    digitalWrite(blue, 1); // Color verde azulado
    digitalWrite(green, 1);
    bandera = 4; // Se acaba el juego
  }
  if (contjugador2 == 8){  // Si gana el jugador 2
    digitalWrite(red, 1); // Color morado
    digitalWrite(blue, 1);
    bandera = 4; // Se acaba el juego
  }
}
