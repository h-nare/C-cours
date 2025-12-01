#include <stdio.h>

typedef union {
    int temperature;
    float pressure;
    float humidity;
} SensorData;

int main() {
    SensorData sensor;
    int type;

    printf("Select sensor type:\n");
    printf("1 - Temperature\n");
    printf("2 - Pressure\n");
    printf("3 - Humidity\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    switch(type) {
        case 1:
            printf("Enter temperature (int): ");
            scanf("%d", &sensor.temperature);
            printf("Sensor type: Temperature, Reading: %d°C\n", sensor.temperature);
            break;
        case 2:
            printf("Enter pressure (float): ");
            scanf("%f", &sensor.pressure);
            printf("Sensor type: Pressure, Reading: %.2f Pa\n", sensor.pressure);
            break;
        case 3:
            printf("Enter humidity (float): ");
            scanf("%f", &sensor.humidity);
            printf("Sensor type: Humidity, Reading: %.2f%%\n", sensor.humidity);
            break;
        default:
            printf("Invalid sensor type!\n");
    }

    return 0;
}

