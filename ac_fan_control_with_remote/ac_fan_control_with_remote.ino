#include "Adafruit_NECremote.h"

#include <atmega8_16mhz_ac_phase_control.h>

#include <EEPROM.h>

int spd[14]={600,500,480,450,400,380,350,300,250,180,150,80,50,1};//our good stage's values

#define A 6 
#define B 5 
#define C 12 
#define D 11 
#define E 10 
#define F 7 
#define G 8 
#define H 13
#define segment_on 0
#define segment_off 1
 
// Connect a 38KHz remote control sensor to the pin below

#define IRpin         3

#define up_key 6

#define down_key 5

int value = 0; 

Adafruit_NECremote remote(IRpin);

void setup(void) {
  value = EEPROM.read(0);
  atmega8_16mhz_ac_phase_control.init();
  atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400
  
  init_7seg();
  //Serial.begin(115200);
  //Serial.println("Ready to decode IR!");
  }

int lastcode = -1;

void loop(void) {
  //Serial.println(value);
  // You can set the listen() time out to 'n' seconds
  int c = remote.listen(5);  // seconds to wait before timing out!
  // Or you can wait 'forever' for a valid code
  //int c = remote.listen();  // Without a #, it means wait forever

  if (c >= 0) {
    //Serial.print("Received code #"); 
    //Serial.println(c, DEC);
    lastcode = c;
    if(c == up_key && value < 13)
    {
      value+=1;
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
      EEPROM.write(0, value);
    }
        if(c == down_key && value > 0)
    {
      value-=1;
      EEPROM.write(0, value);
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
    }
  } /*else if (c == -3) {
    //Serial.print("Repeat (");
    //Serial.print(lastcode);
    if(lastcode == up_key && value < 18)
    {
      value+=1;
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
    }
      if(lastcode == down_key && value > 0)
    {
      value-=1;
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
    }

    //Serial.println(")");
  } else if (c == -2) {
    //Serial.println("Data error");
  } else {
    //Serial.println("Timed out waiting!");
  }*/

  if(value == 0)
  print_0();
  if(value == 1)
  print_1();
  if(value == 2)
  print_2();
  if(value == 3)
  print_3();
  if(value == 4)
  print_4();
  if(value == 5)
  print_5();
  if(value == 6)
  print_6();
  if(value == 7)
  print_7();
  if(value == 8)
  print_8();
  if(value == 9)
  print_9();
  if(value == 10)
  print_A();
  if(value == 11)
  print_B();
  if(value == 12)
  print_C();
  if(value == 13)
  print_D();
  if(value == 14)
  print_E();
  if(value == 15)
  print_F();
  if(value == 16)
  print_G();
  if(value == 17)
  print_H();
  
}

void print_9()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_8()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_7()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_on);
}

void print_6()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_5()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_4()
{
  clear_7seg();
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_3()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_2()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_on);
}

void print_1()
{
  clear_7seg();
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_on);
}


void print_0()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_on);
}

void print_H()
{
  clear_7seg();
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_G()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_F()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_E()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_D()
{
  clear_7seg();
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_C()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_off);
}

void print_B()
{
  clear_7seg();
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_on);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}

void print_A()
{
  clear_7seg();
  digitalWrite(A,segment_on);
  digitalWrite(B,segment_on);
  digitalWrite(C,segment_on);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_on);
  digitalWrite(F,segment_on);
  digitalWrite(G,segment_on);
  digitalWrite(H,segment_off);
}
/*#####################################################################################################################*/
void clear_7seg()
{
  digitalWrite(A,segment_off);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_off);  
}

void init_7seg()
{
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(E,OUTPUT);
  pinMode(F,OUTPUT);
  pinMode(G,OUTPUT);
  pinMode(H,OUTPUT);

  digitalWrite(A,segment_off);
  digitalWrite(B,segment_off);
  digitalWrite(C,segment_off);
  digitalWrite(D,segment_off);
  digitalWrite(E,segment_off);
  digitalWrite(F,segment_off);
  digitalWrite(G,segment_off);
  digitalWrite(H,segment_off);
}
