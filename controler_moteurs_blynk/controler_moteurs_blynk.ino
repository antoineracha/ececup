/*
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

//moteur A = droit; moteur B = gauche
const int vitesseMoteurDroit = 1      // D1 pas pwm mais la datasheet du shield dit que oui
const int directionMoteurDroit = 3    // D3 pas pwm
const int vitesseMoteurGauche = 2     // D2 PWM
const int directionMoteurGauche = 4   // D4 pas pwm 

char auth[] = "584LStD2pW-jhLoJeUzIHIMAZYTEIPiW";
char ssid[] = "ececup";
char pass[] = "ececup";

int rangMin = 312;
int rangMax = 712;

int vitesseMin = 450;
int vitesseMax = 1020;
int vitesseNulle = 0;


void moveControl(int x, int y)
{
    if(y >= rangMax && x >= rangMin && x<= rangMax)
    {
        digitalWrite(directionMoteurDroit,HIGH);
        digitalWrite(directionMoteurGauche,HIGH);
        analogWrite(vitesseMoteurDroit, vitesseMax);
        analogWrite(vitesseMoteurGauche, vitesseMax);
    }


    else if(x >= rangMax && y >= rangMax)
    {
        digitalWrite(directionMoteurDroit, HIGH);
        digitalWrite(directionMoteurGauche,HIGH);
        analogWrite(vitesseMoteurDroit,vitesseMin);
        analogWrite(vitesseMoteurGauche,vitesseMax);
    }


    else if(x <= rangMin && y >= rangMax)
    {
        digitalWrite(directionMoteurDroit,HIGH);
        digitalWrite(directionMoteurGauche,HIGH);
        analogWrite(vitesseMoteurDroit,vitesseMax);
        analogWrite(vitesseMoteurGauche,vitesseMin);
    }


    else if(y < rangMax && y > rangMin && x < rangMax && x > rangMin)
    {
        analogWrite(vitesseMoteurDroit,vitesseNulle);
        analogWrite(vitesseMoteurGauche, vitesseNulle);
    }


    else if(y <= rangMin && x >= rangMin && x <= rangMax)
    {
        digitalWrite(directionMoteurDroit,LOW);
        digitalWrite(directionMoteurGauche,LOW);
        analogWrite(vitesseMoteurDroit,vitesseMax);
        analogWrite(vitesseMoteurGauche,vitesseMax);
    }


    else if(y <= rangMin && x <= rangMin)
    {
        digitalWrite(directionMoteurDroit,LOW);
        digitalWrite(directionMoteurGauche,LOW);
        analogWrite(vitesseMoteurDroit,vitesseMin);
        analogWrite(vitesseMoteurGauche,vitesseMax);
    }


    else if(y <= rangMin && x >= rangMax)
    {
        digitalWrite(directionMoteurDroit,LOW);
        digitalWrite(directionMoteurGauche,LOW);
        analogWrite(vitesseMoteurDroit,vitesseMax);
        analogWrite(vitesseMoteurGauche,vitesseMin);
    }
}


void setup()
{
    Serial.begin(9600);
    Blynk.begin(outh, ssid, pass);


    pinMode(vitesseMoteurDroit, OUTPUT);
    pinMode(vitesseMoteurGauche, OUTPUT);
    pinMode(directionMoteurDroit, OUTPUT);
    pinMode(directionMoteurGauche, OUTPUT);

    digitalWrite(vitesseMoteurDroit, LOW);
    digitalWrite(vitesseMoteurGauche, LOW);
    digitalWrite(directionMoteurDroit, HIGH);
    digitalWrite(directionMoteurGauche, HIGH);
}


void loop()
{

    Blynk.run();
}


BLYNK_WRITE(V1)
{
    int x = param[0].asInt();
    int y = param[1].asInt();
    moveControl(x,y);
}
*/


#define BLYNK_PRINT Serial 
#include  <ESP8266WiFi.h>
#include  <BlynkSimpleEsp8266.h>

char auth[] = "584LStD2pW-jhLoJeUzIHIMAZYTEIPiW"; 
char ssid[] = "Freebox-0AC800"; 
char pass[] = "oculeum-trieres@*-lutitant-sentante"; 

int PWMA=5;//Right side
int PWMB=4;//Left side
int DA=0;//Right reverse
int DB=2;//Left reverse

void setup()
{ 
 // Debug console
 Serial.begin(9600); 
 Blynk.begin(auth, ssid, pass); 
 pinMode(PWMA, OUTPUT); 
 pinMode(PWMB, OUTPUT); 
 pinMode(DA, OUTPUT); 
 pinMode(DB, OUTPUT); 
} 

void loop()
{ 
  
Blynk.run(); 

} 

BLYNK_WRITE(V1)
{

int x = param[0].asInt(); 
int y = param[1].asInt();  

if(x==0 && y==1) //avant
  { 
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
  }

else if(x==0 && y==-1) //arriere
  {   
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH);
  }

else if(x==-1 && y==0) //toune a gauche
  {
     digitalWrite(PWMA, 450); //450
     digitalWrite(DA, HIGH); 
    
     digitalWrite(PWMB, 450); //450
     digitalWrite(DB, LOW); 
  }

else if(x==1 && y==0) //tourne a droite
    {
     digitalWrite(PWMA, 450); //450
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, 450); //450
     digitalWrite(DB, HIGH); 
    }
/*  
else if(x==-1 && y==-1) //arriere et gauche
  {
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, HIGH); 
  }

else if(x==-1 && y==1) //avant et gauche
  {
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
    
     digitalWrite(PWMB, HIGH); 
     digitalWrite(DB, LOW); 
  }

else if(x==1 && y==-1) //arriere et droite
  {
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, HIGH); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
  }
  
else if(x==1 && y==1) //avant et droite
    {
     digitalWrite(PWMA, HIGH); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW);
    }
*/
else if(x==0 && y==0) //pas bouger
  {
     digitalWrite(PWMA, LOW); 
     digitalWrite(DA, LOW); 
     
     digitalWrite(PWMB, LOW); 
     digitalWrite(DB, LOW); 
  }
} 
