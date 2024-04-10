#include <WiFi.h>
#include <WebServer.h>

// Replace with your network credentials
const char* ssid = "NetworkID";
const char* password = "NetworkPa$$word";

WebServer server(80);

// Relay GPIO pins
const int relay1 = 26;
const int relay2 = 27;

void setup() {
  Serial.begin(115200);
  
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);
  
  digitalWrite(relay1, HIGH);
  digitalWrite(relay2, HIGH);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.print("Connected to the WiFi network, IP Address: ");
  Serial.println(WiFi.localIP());

  // Set up the web server routes
  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", "<html><head><meta charset=\"UTF-8\"></head><body>"
                                  "<button onmousedown=\"toggleRelay(1, true)\" onmouseup=\"toggleRelay(1, false)\">Up ⬆️</button><br/>"
                                  "<button onmousedown=\"toggleRelay(2, true)\" onmouseup=\"toggleRelay(2, false)\">Down 🔽</button>"
                                  "<script>"
                                  "function toggleRelay(relay, state) {"
                                  "  var xhr = new XMLHttpRequest();"
                                  "  xhr.open('GET', '/relay?r=' + relay + '&state=' + (state ? 'on' : 'off'), true);"
                                  "  xhr.send();"
                                  "}"
                                  "</script></body></html>");
  });

  server.on("/relay", HTTP_GET, []() {
    String relay = server.arg("r");
    String state = server.arg("state");
    
    if (relay == "1") {
      digitalWrite(relay1, state == "on" ? LOW : HIGH);
    } else if (relay == "2") {
      digitalWrite(relay2, state == "on" ? LOW : HIGH);
    }
    server.send(204, "text/plain", "");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
