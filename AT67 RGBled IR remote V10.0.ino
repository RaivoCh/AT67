/*AT67 RGBled IR remote V10.0*/
//začínám znovu
//nejprve namapovat IR remote a potvrdit v SerilaMonitor - namapováno



/*IR remote*/
#include <IRremote.h>
int IRpin = 10;

IRrecv IR(IRpin); //vytvoření objektu IR(název zvolen), příkaz IRrecv je dán
decode_results cmd;   // decode_results příkaz z knihovny IR, cmd je zvolený název
String myCom;

//RGB led

int redPin = 5;
int greenPin = 3;
int bluePin = 9;

int Rval;    //pro nastavení hodnot jasu
int Gval;
int Bval;


int step = 25; // o kolik se bude měnit jas při zmáčknutí tlačítka up down
int brightC = 100; //koeficient jasu, musí být vyplněn, 100 dává velké hodnoty o dva řády vyšší než max

int dt = 100; //delay


void setup()    {
    Serial.begin(9600);
    IR.enableIRIn();    //case sensitive
    //chybí nastavení pinu IRpin a já nevím, proč se tam nedává

    pinMode(redPin, OUTPUT);
    pinMode(greenPin, OUTPUT);
    pinMode(bluePin, OUTPUT);

}

void loop()
//R remote

    {
    while (IR.decode (& cmd) == 0)    {
    }
   
    delay(dt);
    IR.resume(); 

    if (cmd.value==0xFFA25D)    {    //hodnotu FFA25D jsme vyčetli dříve, že je přiřazena tlačítku power
        myCom="pwr";        
    }

    if (cmd.value==0xFF629D)    {    
        myCom="v+";
    }

    if (cmd.value==0xFFE21D)    {    
        myCom="func/stop";
    }

    if (cmd.value==0xFF22DD)    {    
        myCom="rw";
    }

    if (cmd.value==0xFF02FD)    {    
        myCom="play";
    }

    if (cmd.value==0xFFC23D)    {    
        myCom="ff";
    }

    if (cmd.value==0xFFE01F)    {    
        myCom="down";
    }

    if (cmd.value==0xFFA857)    {    
        myCom="v-";
    }

    if (cmd.value==0xFF906F)    {    
        myCom="up";
    }

    if (cmd.value==0xFF6897)    {    
        myCom="zero";
    }

    if (cmd.value==0xFF9867)    {    
        myCom="eq";
    }

    if (cmd.value==0xFFB04F)    {    
        myCom="st/rept";
    }

    if (cmd.value==0xFF30CF)    {    
        myCom="one";
    }

    if (cmd.value==0xFF18E7)    {    
        myCom="two";
    }

    if (cmd.value==0xFF7A85)    {    
        myCom="three";
    }

    if (cmd.value==0xFF10EF)    {    
        myCom="four";
    }

    if (cmd.value==0xFF38C7)    {    
        myCom="five";
    }

    if (cmd.value==0xFF5AA5)    {    
        myCom="six";
    }

    if (cmd.value==0xFF42BD)    {    
        myCom="seven";
    }

    if (cmd.value==0xFF4AB5)    {    
        myCom="eight";
    }

    if (cmd.value==0xFF52AD)    {    
        myCom="nine";
    }

    Serial.println(myCom);

    }    