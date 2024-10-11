class wifi_connection
{
private:
    char *ssid = new char[30];
    char *pw = new char[30];
public:
    wifi_connection();
    void connect_wifi(const char *wifi_ssid, const char *wifi_pass);
    ~wifi_connection();
};