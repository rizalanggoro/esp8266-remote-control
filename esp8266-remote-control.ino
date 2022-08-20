#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoOTA.h>

const char * ssid_name = "RC Rock Crawler";
const char * ssid_password = "123456788";

const int in1 = 14;
const int in2 = 12;
const int in3 = 13;
const int in4 = 15;
const int enb = 0;

void setup() {
  Serial.begin(115200);
  while (!Serial) {
    ;
  }

  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enb, OUTPUT);

  enableWiFiAP();
  beginOTA();
  beginServer();

  analogWrite(enb, 255);
}

void loop() {
  ArduinoOTA.handle();
  handleServer();

  serial();
}

void serial() {
  String data = "";
  if (Serial.available() > 0) {
    char c = Serial.read();
    data += c;
    if (data.length() > 0) {
      Serial.print("serial command: ");
      Serial.println(data);
      parser(data);
    }
  }
}

void enableWiFiAP() {
  WiFi.mode(WIFI_AP);
  WiFi.softAP(ssid_name, ssid_password);
}
