int led = D7;
int lightLevel = 0;
bool increase = true;

//define I2C port connection
#define I2C_Slave_address 0x08

void setup() 
{
    // Join I2C bus as slave with address 0x08 on Raspberry Pi
    Wire.begin(I2C_Slave_address);
    
    // Call requestHandler function if receive request from RPi
    Wire.onRequest(requestHandler);
    
    //Declare pinmode for led light
    pinMode(led, OUTPUT);
    digitalWrite(led, HIGH);
}

// change mockup data by conditions: increasing or descreasing
int dataChange(int lightLevel, bool increase)
{
    if (increase){
        return lightLevel+=20;      // Increases by 20
    }
    else{
        return lightLevel-=10;      // Decreases by 10
    }
}

// function to generate mockup light level
// Data mockup simulated as chganed 0 --> 200
int mockupData(){
    if(lightLevel == 200 && increase == true){
        increase = false;
        return dataChange(lightLevel, increase);
    }
    else if(lightLevel == 20 && increase == false){
        increase = true;
        return dataChange(lightLevel, increase);
    }
    else{
        return dataChange(lightLevel, increase);
    }
}

// Get mockup data and write it to RPi
void requestHandler()
{
    lightLevel = mockupData();
    Wire.write(lightLevel);
    
}
void loop()
{
    delay(100);
}