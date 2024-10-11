#include <stdio.h>
#include <string.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"
#include "lwip/udp.h"

// #include "received_joystick_data.hpp"

#define RCV_FROM_IP IP_ADDR_ANY
#define MAX_ARRAY_SIZE 2

class udp_server
{
private:
    struct udp_pcb* pcb;
    // received_joystick_data &joy_data;

public:
    udp_server();
    void start_udp_server(const int port);
    static void udp_receive_callback(void *arg, udp_pcb *pcb, pbuf *p, const ip_addr_t *addr, u16_t port);
    ~udp_server();
};