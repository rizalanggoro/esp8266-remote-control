ESP8266WebServer server(80);

void beginServer() {
  server.on("/", server_handleRoot);
  server.begin();
}

void handleServer() {
  server.handleClient();
}

void server_handleRoot() {
  server.send(200, "text/html", "");
  if (server.hasArg("State")) {
    String data = server.arg("State");
    parser(data);
  }
}
