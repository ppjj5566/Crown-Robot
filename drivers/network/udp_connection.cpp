#include<stdio.h>

#include "pico/stdlib.h"
#include "pico/cyw43_arch.h"

#include "lwip/pbuf.h"
#include "lwip/ip_addr.h"

#include "udp_connection.hpp"

#define RCV_FROM_IP IP_ADDR_ANY
#define MAX_ARRAY_SIZE 2

float ntohf(uint32_t net){
    uint32_t host = ntohl(net);
    float f;
    memcpy(&f, &host, sizeof(f));
    return f;
}

void udp_receive_callback(void *arg, struct udp_pcb *pcb, struct pbuf *p, const ip_addr_t *addr, u16_t port){
    if(p != NULL){
        if (p->len == MAX_ARRAY_SIZE * sizeof(float)){
            uint32_t received_data[MAX_ARRAY_SIZE];
            float received_array[MAX_ARRAY_SIZE];
            memcpy(received_data, p->payload, p->len);
            for (int i = 0; i < MAX_ARRAY_SIZE; i++)
            {
                received_array[i] = ntohf(received_data[i]);
            }
        }
        else {
            printf("Error: Received data exceeds buffer size.\n");
        }
        pbuf_free(p);
    }
}

udp_connection::udp_connection(int udp_port)
{
    stdio_init_all();
    if(cyw43_arch_init()){
        printf("failed to initialise\n");
    }
    printf("initialised\n");
    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(wifi_ssid, wifi_pass, CYW43_AUTH_WPA2_AES_PSK, 10000)){
        printf("failed to connect\n");
    }else{
        printf("Connected.\n");
        printf("IP: %s\n", ipaddr_ntoa((const ip_addr_t *)&cyw43_state.netif[0].ip_addr));
        printf("");
    }
    run_udp_server();

    while(true)
    {
        cyw43_arch_poll();
    }
}

udp_connection::~udp_connection()
{
}

void udp_connection::run_udp_server(){
    pcb = udp_new();
    if (pcb == nullptr)
    {
        printf("Error creating UDP PCB\n");
        return;
    }
    err_t bind = udp_bind(pcb, wifi_ssid, wifi_pass);
    if (bind != ERR_OK)
    {
        printf("UDP bind failed\n");
        return;
    }
    udp_recv(pcb, udp_receive_callback, NULL);
}