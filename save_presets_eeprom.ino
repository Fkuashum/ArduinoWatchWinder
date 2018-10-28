#include <EEPROM.h>

int     w1TPD                =              650; //Turns per day (loaded from EEPROM at start)
int     w1DIR                =                0;
boolean DST                  =                0;
int     w1CYCLE_TIME         =               15;

void setup() 
{
saveSettings();
savePresets();
}

///////////////////////////////////
//    SAVE CURRENT SETTINGS      //
///////////////////////////////////
// Bytes 0 - 5 are used
void saveSettings()
{
  //WRITE INDICATION INFO IS SAVED
  EEPROM.write(0,1);
  
  //SPLIT w1TPD INTO BYTE SIZED VARS
  int a = w1TPD/256;
  int b = w1TPD%256;
  EEPROM.write(3,a);
  EEPROM.write(4,b);
  
  //STORE w1DIR
  EEPROM.write(5,w1DIR);
  
  //STORE FREQUENCY
  EEPROM.write(1,w1CYCLE_TIME);

  //STORE DST
  EEPROM.write(2,DST);
}

// Save watch presets (two watches); presets hard-coded below
// Function stores presets only once when sketch is first run on a new Arduino board
// Bytes 6-12 are used
void savePresets()
{
  //WRITE INDICATION that both presets are saved
  EEPROM.write(12,1);

// IWC Pilot (Valjoux 7750): TPD 800, CW
// Bytes 6-8

  //SPLIT w1TPD INTO BYTE SIZED VARS
  int a = 800/256;
  int b = 800%256;
  EEPROM.write(6,a);
  EEPROM.write(7,b);

  //STORE w1DIR (CW)
  EEPROM.write(8,0);

// Glycine Airman (ETA 2893-2): TPD 650, Both
// Bytes 9-11

  //SPLIT w1TPD INTO BYTE SIZED VARS
  int c = 650/256;
  int d = 650%256;
  EEPROM.write(9,c);
  EEPROM.write(10,d);
  
  //STORE w1DIR (Both)
  EEPROM.write(11,2);
}


void loop() {
  // put your main code here, to run repeatedly:

}
