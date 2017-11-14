/*  WEMOS D1 Mini                            
                     ______________________________                
                    |   L T L T L T L T L T L T    |
                    |                              |
                 RST|                             1|TX
                  A0|                             3|RX
                  D0|16                           5|D1
                  D5|14                           4|D2
                  D6|12                    10kPUP_0|D3
RX SSer/HSer swap D7|13                LED_10kPUP_2|D4
TX_SSer/HSer swap D8|15                            |GND
                 3V3|__                            |5V
                       |                           |
                       |___________________________|
*/

#include <SDM.h>                                                                //import SDM template library

#define ASCII_ESC 27

char bufout[10];

SDM<2400, 8, 9, 10> sdm;                                                        //SDM120T	baud, rx pin, tx pin, dere pin(optional for max485)
//SDM<4800, 13, 15> sdm;                                                        //SDM220T	baud, rx pin, tx pin, dere pin(optional for max485)
//SDM<9600, 13, 15> sdm;                                                        //SDM630	baud, rx pin, tx pin, dere pin(optional for max485)
//or without parameters (default from SDM.h will be used): 
//SDM<> sdm;

void setup() {
  Serial.begin(9600);                                                         //initialize serial
  sdm.begin();                                                                  //initialize SDM220 communication baudrate
}

void loop() {

  //sprintf(bufout,"%c[1;0H",ASCII_ESC);
  //Serial.print(bufout);

  Serial.print("Voltage:   ");
  Serial.print(sdm.readVal(SDM120C_VOLTAGE), 2);                                //display voltage
  Serial.println("V");
  
  delay(50);

  Serial.print("Current:   ");
  Serial.print(sdm.readVal(SDM120C_CURRENT), 2);                                //display current  
  Serial.println("A");

  delay(50);

  Serial.print("Power:     ");
  Serial.print(sdm.readVal(SDM120C_POWER), 2);                                  //display power
  Serial.println("W");

  delay(50);

  Serial.print("Active Apparent Power: ");
  Serial.print(sdm.readVal(SDM120C_ACTIVE_APPARENT_POWER), 2);                      
  Serial.println("VA"); 

  delay(50);

  Serial.print("Reactive Apparent Power: ");
  Serial.print(sdm.readVal(SDM120C_REACTIVE_APPARENT_POWER), 2);                           
  Serial.println("VAR"); 

  delay(50);
  
  Serial.print("Power Factor: ");
  Serial.print(sdm.readVal(SDM120C_POWER_FACTOR), 2);                      
  Serial.println("");  

  delay(50);

  Serial.print("Frequency: ");
  Serial.print(sdm.readVal(SDM120C_FREQUENCY), 2);                              //display frequency
  Serial.println("Hz");   

  delay(50);
  
  Serial.print("Import Active Energy: ");
  Serial.print(sdm.readVal(SDM120C_IMPORT_ACTIVE_ENERGY), 2);                      
  Serial.println("kWh"); 

   delay(50);
  
  Serial.print("Export Active Energy: ");
  Serial.print(sdm.readVal(SDM120C_EXPORT_ACTIVE_ENERGY), 2);                      
  Serial.println("kWh");

  delay(50);
  
  Serial.print("Total Active Energy: ");
  Serial.print(sdm.readVal(SDM120C_TOTAL_ACTIVE_ENERGY), 2);                      
  Serial.println("kWh");

  delay(1000);                                                                  //wait a while before next loop
}
