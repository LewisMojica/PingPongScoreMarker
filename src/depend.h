#include <Arduino.h>

#include <Timer.h>
/*Instanciaciones de Timer*/
Timer l(1250);
Timer bl(50);


/*Definiciones*/
#define led 13
#define on 4
#define tim_blink on*2 //numero par

/*Declaraciones de funciones*/

//void
void caracterVoid();
void blink();
