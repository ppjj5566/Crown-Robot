#include "lwip/udp.h"

class udp_connection
{
private:
    char ssid[20] = "ipiptime";
    char pass[20] = "Park98124";
    struct udp_pcb* pcb;

public:
    udp_connection(int udp_port);
    void run_udp_server();
    float ntohf(uint32_t net);
    ~udp_connection();
};