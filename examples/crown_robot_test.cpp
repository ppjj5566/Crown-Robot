#include <stdio.h>

#include "tusb.h"

#include "wifi_connection.hpp"
#include "udp_server.hpp"

char ssid[64];
char pw[64];
int port = 12345;

wifi_connection wifi;
udp_server server;
const uint32_t buf_size = 1;

int main(){
    stdio_init_all();
    wifi.connect_wifi(ssid, pw);
    server.start_udp_server(12345);
    return 0;
}