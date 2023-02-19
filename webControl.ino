
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
String html = R"***(
 <!DOCTYPE html>
<html>
<head>
<style>
.button {
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
}

.button1 {background-color: #4CAF50;} /* Green */
.button2 {background-color: #008CBA;} /* Blue */
</style>
</head>
<body>
<a href="/led1on"> <button class="button button1">LED 1 ON</button></a>

<a href="/led1off"><button class="button button2">LED 1 OFF</button>
<br>
<a href="/led2on"><button class="button button1">LED 2 ON</button>
<a href="/led2off"><button class="button button2">LED 2 OFF</button>
<br>
<a href="/led3on"><button class="button button1">LED 3 ON</button>
<a href="/led3off"><button class="button button2">LED 3 OFF</button>
<br>
<a href="/led4on"><button class="button button1">LED 4 ON</button>
<a href="/led4off"><button class="button button2">LED 4 OFF</button>
<br>
<a href="/led5on"><button class="button button1">LED 5 ON</button>
<a href="/led5off"><button class="button button2">LED 5 OFF</button>

</body>
</html> 
)***";
//--------------------------------------
//#define led 1
int led1 = 16;
int led2 = 5;
int led3 = 4;
int led4 = 0;
int led5 = 2;

const char* ssid = "for test";
IPAddress IPaddr (192, 168, 168, 168);
IPAddress IPmask(255, 255, 255, 0);
ESP8266WebServer server(80);
//--------------------------------------
void handleRoot()
{
  server.send(200, "text/html", html);
}
///=======1=======
void led1on()
{
  Serial.println("led on");
  digitalWrite(led1, 1);
  server.send(200, "text/html", html);
}
void led1off()
{
    Serial.println("led off");
  digitalWrite(led1, 0);
  server.send(200, "text/html", html);
}
///=======2=======
void led2on()
{
  Serial.println("led on");
  digitalWrite(led2, 1);
  server.send(200, "text/html", html);
}
void led2off()
{
    Serial.println("led off");
  digitalWrite(led2, 0);
  server.send(200, "text/html", html);
}
///=======3=======
void led3on()
{
  Serial.println("led on");
  digitalWrite(led3, 1);
  server.send(200, "text/html", html);
}
void led3off()
{
    Serial.println("led off");
  digitalWrite(led3, 0);
  server.send(200, "text/html", html);
}
///=======4=======
void led4on()
{
  Serial.println("led on");
  digitalWrite(led4, 1);
  server.send(200, "text/html", html);
}
void led4off()
{
    Serial.println("led off");
  digitalWrite(led4, 0);
  server.send(200, "text/html", html);
}
///=======5=======
void led5on()
{
  Serial.println("led on");
  digitalWrite(led5, 1);
  server.send(200, "text/html", html);
}
void led5off()
{
    Serial.println("led off");
  digitalWrite(led5, 0);
  server.send(200, "text/html", html);
}
//===============================================
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  WiFi.softAP(ssid);
//  WiFi.softAPConfig(IPaddr, IPaddr, IPmask); 
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", handleRoot);
  ///.........1
  server.on("/led1on", led1on);
  server.on("/led1off", led1off);
    ///.........2
  server.on("/led2on", led2on);
  server.on("/led2off", led2off);
    ///.........3
  server.on("/led3on", led3on);
  server.on("/led3off", led3off);
    ///.........4
  server.on("/led4on", led4on);
  server.on("/led4off", led4off);
      ///.........5
  server.on("/led5on", led5on);
  server.on("/led5off", led5off);
  
  server.begin();
  Serial.println("HTTP server started");
}
//===============================================
void loop()
{
  server.handleClient();
}
