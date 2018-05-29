#include "Adafruit_NECremote.h"

#include <atmega8_16mhz_ac_phase_control.h>

int spd[14]={600,500,480,450,400,380,350,300,250,180,150,80,50,1};//our good stage's values
 
// Connect a 38KHz remote control sensor to the pin below

#define IRpin         3

#define up_key 6

#define down_key 5

int value = 0; 

Adafruit_NECremote remote(IRpin);

void setup(void) {
  atmega8_16mhz_ac_phase_control.init();
  Serial.begin(115200);
  Serial.println("Ready to decode IR!");
  }

int lastcode = -1;

void loop(void) 
{
  Serial.println(value);
  // You can set the listen() time out to 'n' seconds
  int c = remote.listen(5);  // seconds to wait before timing out!
  // Or you can wait 'forever' for a valid code
  //int c = remote.listen();  // Without a #, it means wait forever

  if (c >= 0) 
  {
    Serial.print("Received code #"); 
    Serial.println(c, DEC);
    lastcode = c;
    if(c == up_key && value < 18)
    {
      value+=1;
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
    }
        if(c == down_key && value > 0)
    {
      value-=1;
      atmega8_16mhz_ac_phase_control.set_ac_power(spd[value]);//speed[0 to 19] or 0 to 360 through 400 
    }
  }
}
