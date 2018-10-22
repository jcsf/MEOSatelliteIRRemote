/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */

#include <ESP8266WiFi.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

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

#define IRLED 15

uint16_t power[38] = {2700,850,450,900,450,400,500,400,450,850,900,400,450,450,850,900,450,450,850,450,450,450,450,850,500,400,450,400,450,450,900,450,400,900,450,450,400};
uint16_t ok[36] = {2700,800,500,850,500,350,500,400,500,800,950,400,500,350,950,850,500,350,950,400,500,350,500,850,950,800,950,400,500,350,500,850,500,350,500};

uint16_t one[38] = {2650,850,500,800,500,400,500,350,500,850,950,350,500,400,950,850,450,400,900,400,500,400,500,800,500,400,500,400,450,400,500,400,500,350,500,400,950};
uint16_t two[36] = {2600,900,450,850,450,450,450,450,1300,1300,450,450,900,850,450,450,850,450,450,450,450,850,450,450,450,450,400,450,450,450,450,450,850,900,450};
uint16_t three[38] = {2600,900,450,850,450,450,450,450,400,900,900,400,450,450,900,850,450,450,850,450,450,450,450,850,450,500,400,450,400,450,450,450,450,400,900,450,450};
uint16_t four[36] = {2600,900,450,850,450,450,450,450,1300,1300,450,450,900,850,450,450,850,450,450,450,450,850,450,450,450,450,450,400,450,450,900,850,450,450,450};
uint16_t five[36] = {2650,850,450,900,450,450,400,450,500,850,900,450,400,450,900,850,450,400,950,400,450,400,500,850,450,450,400,450,500,400,450,450,900,850,900};
uint16_t six[36] = {2650,850,450,900,400,450,450,450,1300,1350,400,450,900,850,450,450,900,400,450,450,450,900,450,400,450,450,450,400,450,450,900,450,400,900,450};
uint16_t seven[38] = {2650,900,450,850,450,450,450,400,450,900,850,450,450,450,850,900,450,450,850,450,450,450,450,850,450,450,450,400,450,450,450,450,850,500,400,450,450};
uint16_t eight[36] = {2650,850,500,850,400,450,450,450,1300,1350,500,350,900,900,450,400,950,400,400,450,450,900,450,400,450,450,500,400,900,850,500,400,400,450,450};
uint16_t nine[36] = {2650,850,500,850,400,450,500,400,450,850,900,450,450,400,900,900,450,400,900,450,400,450,500,850,500,350,500,400,450,450,850,900,450,400,900};
uint16_t zero[38] = {2700,800,500,850,450,400,500,400,1300,1350,400,450,900,850,450,450,950,350,500,400,500,850,500,350,500,400,450,400,500,400,500,400,500,350,450,450,500};

IRsend irsend(IRLED);
int number;

/* WI-FI CONNECTION VARIABLES */
const char* ssid = "ADSLPT-TR36402B";
const char* password = "fontinha";

WiFiServer server(80);

IPAddress ip(192, 168, 1, 5);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  irsend.begin();
  number = 2;
  Serial.begin(115200);

  // Connect to WiFi network
  WiFi.config(ip, gateway, subnet); 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");
 
  // Start the server
  server.begin();
  Serial.println("Server started");
 
  // Print the IP address
  Serial.print("Use this URL : ");
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println(":80");
}

void loop() {  
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait until the client sends some data
  Serial.println("New Client");
  while(!client.available()){
    delay(1);
  }
 
  // Read the first line of the request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  receiveRequest(request);
    
  if(request.indexOf("GET /channel?") == 0) {
    int index = request.indexOf("?ch=");
    String ch = request.substring(index+4);
    index = request.indexOf(" ");
    ch = ch.substring(0, index);
    ch.trim();
    IRRemoteLogic(ch);
    redirect(client);
  } else if(request.compareTo("GET / HTTP/1.1") != 0) {
    redirect(client);
  } else {
    view(client);
  }
  
  delay(1);
  Serial.println("Client disconnected");
  Serial.println("");
}

void receiveRequest(String request) {
  // Match the request
  request.indexOf("/number") != -1;
}

void view(WiFiClient client) {
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html><body>");
  client.println("<h1>Alterar Canal MEO</h1>");
  client.println("<form action=\"/channel\" method=\"get\">");
  client.println("<input type=\"number\" name=\"ch\" min=\"1\" max=\"248\">");
  client.println("<input type=\"submit\" value=\"Mudar\">");
  client.println("</form>");
  client.println("</body></html>");
}

void redirect(WiFiClient client) {
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("<meta http-equiv=\"refresh\" content=\"0;URL='http://192.168.1.5/'\" />");      
  client.println("</head>"); 
  client.println("<body>REDIRECTING...</body>");
  client.println("</html>");
}

void IRRemoteLogic(String number) {
  Serial.println(number);
  int ch[3] = {-100, -100, -100};

  for(int i = 0; i < number.length(); i++) {
    char c = number.charAt(i);
    int n = c - '0';
    ch[i] = n;
  }
  
  for(int i = 0; i < 3; i++) {
    switch(ch[i]) {
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
  }
}
