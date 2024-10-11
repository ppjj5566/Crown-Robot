#include "udp_server.hpp"

udp_server::udp_server()
{
    pcb = udp_new();
    if (pcb == nullptr){
        printf("Error creating UDP PDB");
        return;
    }

}

void udp_server::udp_receive_callback(void *arg, udp_pcb *pcb, pbuf *p, const ip_addr_t *addr, u16_t port)
{
    if(p != NULL){
        if(p->len == MAX_ARRAY_SIZE * sizeof(float)){
            uint32_t received_data[MAX_ARRAY_SIZE];
            memcpy(received_data, p->payload, p->len);
            float received_array[MAX_ARRAY_SIZE];
            float f;
            for (int i = 0; i < MAX_ARRAY_SIZE; i++)
            {
                uint32_t host = ntohl(received_data[i]);
                memcpy(&f, &host, sizeof(f));
                received_array[i] = f;
            }
            // joy_data.set_joystick_data(received_array[0], 0.00f, received_array[1], 0.00f);
            printf("recv data, X: %f, Y: %f\n", received_array[0], received_array[1]);
        }
        else {
            printf("Error: Received data exceeds buffer size.\n");
        }
        pbuf_free(p);
    }
}

void udp_server::start_udp_server(const int port){
    err_t bind = udp_bind(pcb, RCV_FROM_IP, port);
    if(bind != ERR_OK){
        printf("UDP bind failed\n");
        return;
    }
    printf("udp server started!\n");
    udp_recv(pcb, udp_receive_callback, NULL);

    while(true){
        cyw43_arch_poll();
    }
}

udp_server::~udp_server()
{   
    udp_remove(pcb);
    printf("udp connection disabled!\n");
}



