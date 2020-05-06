from smbus import SMBus
import time

# Initial I2C port address: 0x08
address = 0x08
bus = SMBus(1)

# Read data from I2C address connected device
def getData():
    number = bus.read_byte(address)
    return number

# infinite loop to receive data from I2C slave device
while True:
    data = getData()
    print("Data received : %d" %data)
    time.sleep(1)