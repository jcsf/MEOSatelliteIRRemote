#include <ESP8266WiFi.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>

#define POWER -1
#define OK -2

#define POWER_LENGHT 78
#define OK_LENGHT 78

#define ONE_LENGHT 78
#define TWO_LENGHT 78
#define THREE_LENGHT 78
#define FOUR_LENGHT 78
#define FIVE_LENGHT 78
#define SIX_LENGHT 78
#define SEVEN_LENGHT 78
#define EIGHT_LENGHT 78
#define NINE_LENGHT 78
#define ZERO_LENGHT 78

#define KHZ 38

#define IRLED 15

#define IP_ADDRESS_1 192
#define IP_ADDRESS_2 168
#define IP_ADDRESS_3 8
#define IP_ADDRESS_SERVER 5
#define IP_ADDRESS_GATEWAY 1

/* Motorolla Box */
/*
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
*/

/* Samsung Box */
uint16_t power[78] = {4450,4450,500,500,500,450,550,450,550,500,500,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1450,500,450,550,450,550,450,550,450,550,1400,550,1400,550,1400,500,1450,500,500,550,450,500,500,500,1450,500,450,550,450,550,450,550,450,550,1400,550,1400,550,1400,55};
uint16_t ok[78] = {4450,4400,550,450,550,450,550,450,550,450,550,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,500,500,500,4450,550,1400,500,450,550,450,550,450,550,450,550,450,550,1450,500,450,550,1400,550,450,550,450,550,450,550,1400,550,1400,550,450,550,1400,500,500,500,1450,500,1450,500,1450,500};

uint16_t one[78] = {4500,4400,550,450,550,450,550,450,550,450,550,450,550,1400,550,450,550,450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,500,500,550,1400,500,1450,500,1450,500,1450,500,1450,500,1400,550,1450,500,1400,550};
uint16_t two[78] = {4450,4450,550,450,500,500,500,500,550,450,500,500,500,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,500,500,500,500,550,4400,550,1400,550,450,550,450,500,500,500,1450,500,500,500,500,500,450,550,450,550,450,550,450,550,450,550,450,550,1450,500,1400,550,1400,550,1400,550,1400,500,1450,550,1400,500};
uint16_t three[78] = {4450,4400,550,450,550,450,550,450,550,450,550,450,550,1400,550,450,550,450,500,500,500,500,500,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1450,500,450,550,450,550,450,550,450,550,1450,500,450,550,450,550,450,550,450,550,450,500,500,550,1400,550,450,500,1450,500,1450,500,1450,500,1450,500,1450,500,1450,500};
uint16_t four[78] = {4450,4400,550,450,550,450,550,450,550,450,550,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,500,450,550,500,550,4400,550,1400,550,450,550,450,500,450,550,1450,500,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,1400,550,1400,550,1400,550,1400,500,1450,500,1450,500};
uint16_t five[78] = {4450,4450,550,450,500,450,550,450,550,500,500,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1450,500,450,550,450,550,450,550,450,550,450,500,1450,550,450,550,450,500,500,500,450,550,500,500,1450,500,1450,500,450,550,1450,500,1400,550,1400,550,1400,550,1400,550};
uint16_t six[78] = {4450,4450,500,500,500,450,550,450,550,450,550,500,500,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1400,550,450,550,450,500,500,500,1450,500,500,500,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,1450,500,450,550,1400,550,1400,550,1400,500,1450,550,1400,500};
uint16_t seven[78] = {4450,4400,550,450,550,450,550,450,550,450,550,450,550,1400,550,450,550,450,550,450,550,450,500,500,500,500,500,450,550,450,550,450,550,450,550,4450,500,1450,500,450,550,450,550,450,550,450,550,1450,500,1450,500,450,550,450,550,450,550,450,550,450,550,1400,550,450,550,450,500,1450,500,1450,500,1450,500,1450,500,1450,500};
uint16_t eight[78] = {4450,4450,550,450,550,450,500,500,550,450,550,450,550,1400,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1400,550,450,550,450,550,450,550,1400,550,1400,550,1400,500,500,500,450,550,500,500,500,500,450,550,450,550,450,550,450,550,1400,550,1400,550,1400,550,1400,550,1400,550};
uint16_t nine[78] = {4450,4450,550,450,500,500,500,450,550,500,500,500,500,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,1400,550,450,550,450,500,450,550,500,550,1400,500,1450,500,1450,500,450,550,1450,500,1400,550,1400,550,1400,550};
uint16_t zero[78] = {4450,4450,500,450,550,450,550,450,550,450,550,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,450,550,4400,550,1400,550,450,550,450,500,450,550,1450,500,500,500,450,550,1450,500,450,550,450,550,450,550,450,550,450,550,1450,500,1400,550,450,550,1400,550,1400,500,1450,550,1400,500};


IRsend irsend(IRLED);

/* WI-FI CONNECTION VARIABLES */
const char* hostname = "MEO Remote Controller";
const char* ssid = "SSID";
const char* password = "password";

WiFiServer server(80);

IPAddress ip(IP_ADDRESS_1, IP_ADDRESS_2, IP_ADDRESS_3, IP_ADDRESS_SERVER);
IPAddress gateway(IP_ADDRESS_1, IP_ADDRESS_2, IP_ADDRESS_3, IP_ADDRESS_GATEWAY);
IPAddress subnet(255, 255, 255, 0);

void setup() {
  irsend.begin();
  Serial.begin(115200);

  startWIFI();
}

void loop() {
  //Reconnect WiFi If Disconnected
  if (WiFi.status() != WL_CONNECTED) {
      startWIFI();
      return;
  }
  
  //Check If a Client has Connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
 
  // Wait Until the Client Sends Some Data
  Serial.println("New Client");
  long startTime = millis();
  while(!client.available()){
    if((millis() - startTime) > 3000) {
      client.flush();
      Serial.println("Client Timeout");
      Serial.println("");
      return;
    }
    delay(1);
  }
 
  // Read the First Line of The Request
  String request = client.readStringUntil('\r');
  Serial.println(request);
  client.flush();
 
  if(receiveRequest(request) == 0) {
    view(client);
  } else {
    redirect(client);
  }
  
  delay(1);
  Serial.println("Client Disconnected");
  Serial.println("");
}

int receiveRequest(String request) {
  if(request.indexOf("GET /channel?") == 0) {
    int index = request.indexOf("?ch=");
    String ch = request.substring(index+4);
    index = request.indexOf(" ");
    ch = ch.substring(0, index);
    ch.trim();
    IRRemoteLogic(ch);
    return -1;
  } else if(request.compareTo("GET / HTTP/1.1") != 0) {
    return -1;
  } else {
    return 0;
  }
}

void view(WiFiClient client) {
  // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">");
  client.println("<title>MEO Satelite Remote</title>");
  client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  client.println("body{margin-top: 50px;} h1 {color: #444444; margin: 50px auto 30px;} h3 {color: #444444; margin-bottom: 50px;}");
  client.println(".button {display: block; width: auto; background-color: #000000; border: none; color: #ffffff; padding: 15px 25px; text-decoration: none; font-size: 20px; cursor: pointer; margin: 0px auto 35px; border-radius: 4px;}");
  client.println(".text-box {display: block; width: 50%; background-color: #ffffff; border-width: 0px 0px 2px 0px; border-color: #444444; color: #333333; text-align: center; text-decoration: none; font-size: 20px; margin: 0px 25% 35px 25%;}");
  client.println(".text-box:focus {outline: none;}");
  client.println("p {font-size: 14px;color: #888;margin-bottom: 10px;}");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<h1>Alterar Canal MEO</h1>");
  client.println("<form action=\"/channel\" method=\"get\">");
  client.println("<input class=\"text-box\" type=\"number\" name=\"ch\" min=\"1\" max=\"999\" autofocus>");
  client.println("<input class=\"button\" type=\"submit\" value=\"Mudar\">");
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
  char clientRedirect[128];
  sprintf(clientRedirect, "<meta http-equiv=\"refresh\" content=\"0;URL='http://%d.%d.%d.%d/'\" />", IP_ADDRESS_1, IP_ADDRESS_2, IP_ADDRESS_3, IP_ADDRESS_SERVER);
  client.println(clientRedirect);
  client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">");
  client.println("<title>MEO Satelite Remote (Redirect)</title>");
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
    delay(500);
  }
}

void startWIFI() {

  // Config WiFi network
  WiFi.config(ip, gateway, subnet);

  // Disables Soft AP Wireless
  WiFi.softAPdisconnect(true);

  // Connect to WiFi network
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
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
