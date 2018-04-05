#include "pubsub.h"

// create this file
// define PUB_SUB_SERVER, PUB_SUB_PORT, PUB_SUB_USERNAME, PUB_SUB_KEY,
// PUB_SUB_TOPIC
#include "credentials.h"

PubSub::PubSub() {
    client = new PubSubClient(PUB_SUB_SERVER, PUB_SUB_PORT, espClient);

}

PubSub::~PubSub() {
    delete client;
}

void PubSub::connect() {
    client->connect("ESP8266Client", PUB_SUB_USERNAME, PUB_SUB_KEY);
}
void PubSub::sendTemp(float temp) {
    if (!client->connected()) {
        connect();
    }
    String s(temp);
    client->publish(PUB_SUB_TOPIC, s.c_str());
    client->loop();
}
