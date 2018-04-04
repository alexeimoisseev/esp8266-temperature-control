# ESP8266 Arduino Temperature control

Application for ESP8266 module that checks temperature, handles LCD (i2c) display, sends MQTT messages with temperature and switches fan on and off.

## Getting started

### Prerequisites
* [Dallas Temperature](https://github.com/milesburton/Arduino-Temperature-Control-Library)
* [OneWire](https://github.com/PaulStoffregen/OneWire)
* [LiquidCrystal_I2C for ESP8266](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library)
* [PubSub client](https://github.com/knolleary/pubsubclient)

### Configuration

Create two files:
* `credentials.h` with PubSub client config.
```
#define PUB_SUB_SERVER "192.168.0.10"
#define PUB_SUB_PORT 1883

#define PUB_SUB_USERNAME "alexeimoisseev"
#define PUB_SUB_KEY "asoidjfaosiduf012934"
#define PUB_SUB_TOPIC "temperature"
```

* `wifi_credentials.h`
```
#define WIFI_SSID "you-home-wifi"
#define WIFI_PASS "123"
```


### Deployment

Open `Main.ino` with Arduino IDE and build project.
