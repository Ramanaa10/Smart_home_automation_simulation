#include <stdio.h>
#include <stdbool.h>

typedef struct {
    bool isOn;
    int brightness;
} Light;

typedef struct {
    int temperature;
} Thermostat;

typedef struct {
    bool isLocked;
} DoorLock;

typedef struct {
    char name[20];
    int type;  
    union {
        Light light;
        Thermostat thermostat;
        DoorLock doorLock;
    } device;
} Device;

void controlDevice(Device *device);

void setSchedule(Device *device);

void automateTasks(Device devices[], int numDevices);

void viewDeviceStatus(Device *device);

int main() {
    Device devices[3] = {
        {"Living Room Light", 0, .device.light = {false, 0}},
        {"Thermostat", 1, .device.thermostat = {72}},
        {"Front Door Lock", 2, .device.doorLock = {true}}
    };

    controlDevice(&devices[0]);  
    controlDevice(&devices[1]);  
    controlDevice(&devices[2]);  

    setSchedule(&devices[0]); 
    setSchedule(&devices[1]);  

    automateTasks(devices, 3);  

    for (int i = 0; i < 3; i++) {
        viewDeviceStatus(&devices[i]);
    }

    return 0;
}

void controlDevice(Device *device) {
  
    if (device->type == 0) {
        device->device.light.isOn = !device->device.light.isOn;
        if (device->device.light.isOn)
            device->device.light.brightness = 100;
    } else if (device->type == 1) {
        device->device.thermostat.temperature -= 2;
    } else if (device->type == 2) {
        device->device.doorLock.isLocked = !device->device.doorLock.isLocked;
    }
}

void setSchedule(Device *device) {
  
    printf("Schedule set for device: %s\n", device->name);
}

void automateTasks(Device devices[], int numDevices) {
   
    printf("Automating tasks based on schedule...\n");
}

void viewDeviceStatus(Device *device) {
    
    printf("Device: %s\n", device->name);
    if (device->type == 0) {
        printf("Type: Light\n");
        printf("Status: %s, Brightness: %d\n", (device->device.light.isOn ? "On" : "Off"), device->device.light.brightness);
    } else if (device->type == 1) {
        printf("Type: Thermostat\n");
        printf("Temperature: %d°C\n", device->device.thermostat.temperature);
    } else if (device->type == 2) {
        printf("Type: Door Lock\n");
        printf("Status: %s\n", (device->device.doorLock.isLocked ? "Locked" : "Unlocked"));
    }
}





