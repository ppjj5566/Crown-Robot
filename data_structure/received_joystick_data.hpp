class received_joystick_data
{
private:
    float x1;
    float x2;
    float y1;
    float y2;
    int mode;
    int connection_mode;
    int led_data;

public: 
    received_joystick_data():x1(0.00f), x2(0.00f), y1(0.00f), y2(0.00f), mode(0), connection_mode(0), led_data(0) {};
    void set_joystick_data(float _x1, float _x2, float _y1, float _y2){
        x1 = _x1;
        x2 = _x2;
        y1 = _y1;
        y2 = _y2;
    };
    float get_x1(){
        return x1;
    };
    float get_y1(){
        return y1;
    }
    float get_x2(){
        return x2;
    }
    float get_y2(){
        return y2;
    }
    ~received_joystick_data() {};
};