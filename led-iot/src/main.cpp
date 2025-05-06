#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <esp8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

const char* ssid = "KYS-NOW"; 
const char* password = "123123123"; 

ESP8266WebServer server(80); // Create a web server object that listens for HTTP requests on port 80
String webpage;

void setup() {
  Serial.begin(115200);
  delay(10);



pinMode(D0, OUTPUT); // Set GPIO pin D0 as output
pinMode(D1, OUTPUT); // Set GPIO pin D1 as output 
pinMode(D4, OUTPUT); // Set GPIO pin D2 as output

Serial.println();
Serial.println("Connecting to WiFi...");

WiFi.mode(WIFI_AP); // Set WiFi mode to access point
WiFi.begin(ssid, password); // Connect to the WiFi network

Serial.println("Ip address: ");
Serial.println(WiFi.softAPIP()); // Print the local IP address assigned to the ESP8266

// isi webpage
webpage+= "<h1>Web control EPS8266</h1>";
webpage+= "<p>LED 1 <a href=\"/LED1/on\">ON</a> <a href=\"/LED1/off\">OFF</a></p>";
webpage+= "<p>LED 2 <a href=\"/LED2/on\">ON</a> <a href=\"/LED2/off\">OFF</a></p>";
webpage+= "<p>LED 3 <a href=\"/LED3/on\">ON</a> <a href=\"/LED3/off\">OFF</a></p>";

// Create web interface
server.on("/", []() {
    server.send(200, "text/html", webpage); // Send the HTML webpage to the client
  });

  // This section responds to incoming commands
server.on("/LED1ON", []() {
  server.send(200, "text/html", webpage); // Send a response to the client
  digitalWrite(D0, HIGH); // Turn on LED connected to GPIO pin D0
  delay(1000); // Wait for 1 second
});

server.on("/LED2ON", []() {
  server.send(200, "text/html", webpage); // Send a response to the client
  digitalWrite(D1, HIGH); // Turn on LED connected to GPIO pin D1
  delay(1000); // Wait for 1 second
});

server.on("/LED3ON", []() {
  server.send(200, "text/html", webpage); // Send a response to the client
  digitalWrite(D4, HIGH); // Turn on LED connected to GPIO pin D2
  delay(1000); // Wait for 1 second
});

}

void loop() {
  server.handleClient(); // Handle incoming client requests

}