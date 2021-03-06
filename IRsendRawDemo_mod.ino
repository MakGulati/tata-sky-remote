

#include <IRremote.h>

IRsend irsend;
char data;
void setup()
{
Serial.begin(9600);
Serial.println("your response: ");
}

void loop() {
  int khz = 38; // 38kHz carrier frequency of 1838
  //unsigned int irSignal[] = {9000, 4500, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 560, 560, 560, 560, 560, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 560, 560, 1690, 560, 1690, 560, 1690, 560, 1690, 560, 39416, 9000, 2210, 560}; //AnalysIR Batch Export (IRremote) - RAW
unsigned int  rawData[49] = {2600,950, 400,450, 400,500, 400,900, 400,900, 900,450, 400,450, 400,500, 400,450, 450,450, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,500, 400,450, 400,500, 400,450, 400,500, 800,450, 450,900, 400,500, 500};  // UNKNOWN 499B750A
unsigned int  rawData1[47] = {2550,950, 400,450, 400,500, 400,900, 400,900, 850,450, 400,500, 400,500, 350,500, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 850,450, 400,900, 850};  // UNKNOWN A2B4FD50//mute
unsigned int  rawData2[47] = {2600,900, 400,500, 400,450, 450,900, 400,900, 850,450, 400,500, 400,450, 400,500, 400,500, 350,500, 400,500, 350,500, 400,500, 350,500, 400,500, 400,450, 850,450, 450,900, 400,450, 850,450, 450,900, 400,450, 400};  // UNKNOWN B5509A8//guide
unsigned int  rawData3[49] = {2550,950, 400,450, 400,500, 400,900, 400,950, 800,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,500, 350,500, 400,500, 350,500, 400,500, 400,450, 400,500, 350,500, 850,900, 400,500, 350,500, 400,500, 400};  // UNKNOWN C31D712E//vol+
unsigned int  rawData4[47] = {2600,950, 400,450, 400,500, 400,900, 400,900, 850,450, 450,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,450, 450,450, 450,450, 400,450, 450,450, 400,450, 400,500, 850,900, 400,450, 400,500, 850};  // UNKNOWN 49F4E73F//vol-
unsigned int  rawData6[47] = {2550,950, 400,500, 400,450, 400,950, 350,950, 850,450, 400,500, 400,450, 400,450, 450,450, 400,500, 400,450, 400,500, 400,450, 400,450, 450,450, 400,500, 850,900, 400,450, 400,500, 400,500, 350,500, 850,450, 400};  // UNKNOWN 798DECFE //back
//unsigned int  rawData7[45] = {2550,950, 400,500, 400,450, 450,850, 400,950, 800,500, 400,500, 350,500, 400,500, 350,500, 400,500, 400,450, 400,500, 400,450, 400,500, 450,400, 400,500, 400,450, 850,900, 850,500, 350,950, 800,950, 400};  // UNKNOWN CF7095CD //left
//unsigned int  rawData8[45] = {2550,950, 400,500, 350,500, 400,900, 400,950, 800,500, 400,500, 350,500, 400,500, 350,500, 400,500, 350,500, 400,500, 350,500, 400,500, 350,500, 400,500, 400,450, 850,900, 850,450, 400,950, 800,500, 400};  // UNKNOWN CE70943A //right
//unsigned int  rawData9[47] = {2550,950, 400,500, 400,450, 400,950, 400,900, 850,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,500, 800,950, 800,500, 400,900, 400,450, 400,500, 400};  // UNKNOWN A215B7E2 //up
//unsigned int  rawData10[45] = {2550,950, 400,450, 400,500, 400,900, 400,950, 800,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,500, 350,500, 850,900, 850,450, 400,950, 350,500, 850};  // UNKNOWN A86E19D3 //down
//unsigned int  rawData11[47] = {2550,950, 400,500, 400,450, 400,950, 350,950, 850,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 400,500, 400,450, 850,900, 850,500, 400,450, 400,900, 400,500, 400};  // UNKNOWN 9E856ADE //select
//


while (Serial.available())
{
 data = Serial.read();
 switch(data)
{case '5':
 { irsend.sendRaw(rawData, sizeof(rawData) / sizeof(rawData[0]), khz); //power
 delay(40);
 }


case '1':
 { irsend.sendRaw(rawData1, sizeof(rawData1) / sizeof(rawData1[0]), khz); //mute
    delay(40);
    break;
 }
 
case '2':
 { irsend.sendRaw(rawData2, sizeof(rawData2) / sizeof(rawData2[0]), khz); //guide
    delay(40);
    break;
 }
 

 case '3':
 { irsend.sendRaw(rawData3, sizeof(rawData3) / sizeof(rawData3[0]), khz); //vol+
    delay(40);
    break;
  }


 case '4':
 { irsend.sendRaw(rawData4, sizeof(rawData4) / sizeof(rawData4[0]), khz); //vol-
    delay(40);
    break;
  }

case '6':
 { irsend.sendRaw(rawData6, sizeof(rawData6) / sizeof(rawData6[0]), khz); //back
    delay(40);
    break;
  }
//case '7':
// { irsend.sendRaw(rawData7, sizeof(rawData7) / sizeof(rawData7[0]), khz); //left
//    delay(40);
//    break;
//  }  
//case '8':
// { irsend.sendRaw(rawData8, sizeof(rawData8) / sizeof(rawData8[0]), khz); //right
//    delay(40);
//    break;
//  }    
//case '9':
// { irsend.sendRaw(rawData9, sizeof(rawData9) / sizeof(rawData9[0]), khz); //up
//    delay(40);
//    break;
//  }  
//case 'a':
// { irsend.sendRaw(rawData10, sizeof(rawData10) / sizeof(rawData10[0]), khz); //down
//    delay(40);
//    break;
//  }  
//case 'b':
// { irsend.sendRaw(rawData11, sizeof(rawData11) / sizeof(rawData11[0]), khz); //select
//    delay(40);
//    break;
//  }    
   
}
  
}
}
