unsigned long matriz_general[30];                         //matriz de almacenamiento hasta 30 números enteros positivos
int final_matriz;                                         //nº total real de números a almacenar
String data = "Altura,67,98,34,20000,225000";       // Cadena de 7 caracteres numéricos de prueba (30 max)

 
void setup() {
 
  Serial.begin(9600);                                     // Iniciar comunicación serial
   
 
}


void loop() {
    conversion_cadena();                                  //llama el procedimiento                       
    delay (100000);

                                                          //resto de comandos

   
}


void conversion_cadena() {                                //procedimiento que convierte las cadenas y almacena en la matriz numérica
   
  unsigned long values[30];                               // Una forma más "compacta" de crear 30 variables.
  byte prevPos = data.indexOf(',');                       // Buscar la posición de la primera coma en la cadena
  String first = data.substring(0, prevPos);              // Extraer la primera cadena de caracteres (sin coma)
  prevPos++;                                              // Desplazar el índice de la primera coma. Sin esto, la próxima búsqueda resultará
                                                          // en la misma posición.
  byte currPos = data.indexOf(',', prevPos);              // La siguente subcadena ya no empezará desde el principio; por lo tanto, hay que
                                                          // almacenar dos posiciones.
 
  for (byte i = 0; i < 30; i++) {
    values[i] = data.substring(prevPos, currPos).toInt(); // Extrae la subcadena que contiene un número, luego se convierte en un valor
                                                          // númerico de variable.
    prevPos = currPos + 1;                                // Como ahora trabajamos con dos posiciones y necesitamos pasar a la siguiente
                                                          // subcadena, la "posición actual" ahora es la anterior. No olvidemos el
                                                          // desplazamiento de índice.
    currPos = data.indexOf(',', prevPos);                 // La "posición actual" ahora es la próxima ocurrencia del "caracter separador"
                                                          // (en este caso, una coma).
  }                                                       // Y todo esto se repite 5 veces más.

  Serial.println("Cadena: " + first);                     // Imprime, al monitor serie, la primera subcadena extraída.
 
  for (byte i = 0; i < 30; i++) {                         // Imprime el valor de las seis variables extraídas del texto de prueba.
   
    Serial.println("Valor " + String(i + 1) + ": " + String(values[i]));

    char a_[33];                                          //define variable char
    unsigned long b_;                                     //define variable numeros enteros positivos long
    String(values[i]).toCharArray(a_, 32);                //convierte strig a char
    b_  = atoi(a_);                                       //convierte char a int
    //Serial.println( b_);

    matriz_general[i]=b_;                                 //almacena los valores numéricos en la matriz
    //Serial.println( matriz_general[i]);
 
    
                                                          //el bucle de hasta 30 termina cuando ya no detecta mas números
                                                          //y en Serial.println... imprime el nº 0
   
    if (b_==0){                                           //si detecta valor 0 pone el contador i a 30 y fuerza la salida del for
      final_matriz=i;                                     //al salir de for queda almacenado el nº total
                                                          //de números válidos (max 30 según String data)
     
      //Serial.println( final_matriz );
      i=30;                                               //al asignar el valor 30 fuerza la salida del bucle for
      }


   }
    for (byte J = 0; J < 6; J++) {                         // Imprime el valor de las seis variables extraídas del texto de prueba.
    Serial.println("valor de variable valor " + String(J) + ":");
      Serial.println(values[J]);}
  
  }
