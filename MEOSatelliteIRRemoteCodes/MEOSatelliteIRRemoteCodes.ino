#include <IRremote.h>

#define POWER -1
#define OK -2

#define POWER_LENGHT 38
#define OK_LENGHT 36

#define ONE_LENGHT 38
#define TWO_LENGHT 36
#define THREE_LENGHT 38
#define FOUR_LENGHT 36
#define FIVE_LENGHT 36
#define SIX_LENGHT 36
#define SEVEN_LENGHT 38
#define EIGHT_LENGHT 36
#define NINE_LENGHT 36
#define ZERO_LENGHT 38

#define KHZ 38

unsigned int power[38] = {2700,850,450,900,450,400,500,400,450,850,900,400,450,450,850,900,450,450,850,450,450,450,450,850,500,400,450,400,450,450,900,450,400,900,450,450,400};
unsigned int ok[36] = {2700,800,500,850,500,350,500,400,500,800,950,400,500,350,950,850,500,350,950,400,500,350,500,850,950,800,950,400,500,350,500,850,500,350,500};

unsigned int one[38] = {2650,850,500,800,500,400,500,350,500,850,950,350,500,400,950,850,450,400,900,400,500,400,500,800,500,400,500,400,450,400,500,400,500,350,500,400,950};
unsigned int two[36] = {2600,900,450,850,450,450,450,450,1300,1300,450,450,900,850,450,450,850,450,450,450,450,850,450,450,450,450,400,450,450,450,450,450,850,900,450};
unsigned int three[38] = {2600,900,450,850,450,450,450,450,400,900,900,400,450,450,900,850,450,450,850,450,450,450,450,850,450,500,400,450,400,450,450,450,450,400,900,450,450};
unsigned int four[36] = {2600,900,450,850,450,450,450,450,1300,1300,450,450,900,850,450,450,850,450,450,450,450,850,450,450,450,450,450,400,450,450,900,850,450,450,450};
unsigned int five[36] = {2650,850,450,900,450,450,400,450,500,850,900,450,400,450,900,850,450,400,950,400,450,400,500,850,450,450,400,450,500,400,450,450,900,850,900};
unsigned int six[36] = {2650,850,450,900,400,450,450,450,1300,1350,400,450,900,850,450,450,900,400,450,450,450,900,450,400,450,450,450,400,450,450,900,450,400,900,450};
unsigned int seven[38] = {2650,900,450,850,450,450,450,400,450,900,850,450,450,450,850,900,450,450,850,450,450,450,450,850,450,450,450,400,450,450,450,450,850,500,400,450,450};
unsigned int eight[36] = {2650,850,500,850,400,450,450,450,1300,1350,500,350,900,900,450,400,950,400,400,450,450,900,450,400,450,450,500,400,900,850,500,400,400,450,450};
unsigned int nine[36] = {2650,850,500,850,400,450,500,400,450,850,900,450,450,400,900,900,450,400,900,450,400,450,500,850,500,350,500,400,450,450,850,900,450,400,900};
unsigned int zero[38] = {2700,800,500,850,450,400,500,400,1300,1350,400,450,900,850,450,450,950,350,500,400,500,850,500,350,500,400,450,400,500,400,500,400,500,350,450,450,500};

IRsend irsend;

int number;

void setup() {
  number = 2;
  Serial.begin(9600);
}

void loop() {

  Serial.println(number);

  irsend.sendRaw(one, ONE_LENGHT, KHZ);
  delay(1000);
  
  switch(number) {
    case POWER:
      irsend.sendRaw(power, POWER_LENGHT, KHZ);
      break;
    case OK:
      irsend.sendRaw(ok, OK_LENGHT, KHZ);
      break;
    case 0:
      irsend.sendRaw(zero, ZERO_LENGHT, KHZ);
      break;
    case 1:
      irsend.sendRaw(one, ONE_LENGHT, KHZ);
      break;
    case 2:
      irsend.sendRaw(two, TWO_LENGHT, KHZ);
      break;
    case 3:
      irsend.sendRaw(three, THREE_LENGHT, KHZ);
      break;
    case 4:
      irsend.sendRaw(four, FOUR_LENGHT, KHZ);
      break;
    case 5:
      irsend.sendRaw(five, FIVE_LENGHT, KHZ);
      break;
    case 6:
      irsend.sendRaw(six, SIX_LENGHT, KHZ);
      break;
    case 7:
      irsend.sendRaw(seven, SEVEN_LENGHT, KHZ);
      break;
    case 8:
      irsend.sendRaw(eight, EIGHT_LENGHT, KHZ);
      break;
    case 9:
      irsend.sendRaw(nine, NINE_LENGHT, KHZ);
      break;
    default:
      break;  
  }

  delay(1000);
  irsend.sendRaw(one, ONE_LENGHT, KHZ);

  number++;
  
  delay(5000); //In this example, the signal will be repeated every 5 seconds, approximately.
}
