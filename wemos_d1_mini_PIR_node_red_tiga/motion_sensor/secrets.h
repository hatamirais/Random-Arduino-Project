/*
 * Copy this file to `secrets.h` and set the values below to configure your
 * (2.4Ghz) wifi network, MQTT server, MQTT topic, and OTA server
 */

/************ WIFI and MQTT CONNECTIONS ******************/

#define wifi_ssid "TOTOLINK_N200RE"
#define wifi_password "hatami007"

#define mqtt_server "192.168.1.2"
#define mqtt_user NULL
#define mqtt_password NULL
#define mqtt_port 1883

/************* MQTT TOPICS (change these topics as you wish)  **************************/

#define motion_state_topic "esp/pir"
#define motion_set_topic "esp/pir/set"

/**************************** FOR OTA **************************************************/

#define SENSORNAME "motion_sensor"
#define OTApassword "" 
#define OTAport 8266
