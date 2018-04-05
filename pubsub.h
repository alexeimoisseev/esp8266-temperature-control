// https://github.com/knolleary/pubsubclient
#include <PubSubClient.h>
#include <ESP8266WiFi.h>

class PubSub {
public:
    PubSub();
    ~PubSub();
    void sendTemp(float temp);
    void connect();
private:
    WiFiClient espClient;
    PubSubClient *client;
};
