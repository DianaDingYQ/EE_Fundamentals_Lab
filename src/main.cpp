#include <Arduino.h>

// put function declarations here:
// 定义模拟输入引脚
const int analogPin1 = 1;  // GPIO1
const int analogPin2 = 2;  // GPIO2

void setup() {
  // 初始化串口监视器，设置波特率为 115200
  Serial.begin(115200);

  // 设置 ADC 分辨率为 12 位
  analogReadResolution(12);

  // 打印初始化信息
  Serial.println("ESP32 ADC Voltage Reader");
}

void loop() {
  // 从 GPIO1 和 GPIO2 读取 ADC 值
  int adcValue1 = analogRead(analogPin1);
  int adcValue2 = analogRead(analogPin2);

  // 将 ADC 值转换为电压
  float voltage1 = (adcValue1 / 4095.0) * 3.3; // 参考电压为 3.3V
  float voltage2 = (adcValue2 / 4095.0) * 3.3;

  // 打印结果到串口监视器
  Serial.print("GPIO1 Voltage: ");
  Serial.print(voltage1);
  Serial.println(" V");

  Serial.print("GPIO2 Voltage: ");
  Serial.print(voltage2);
  Serial.println(" V");

  Serial.println("-------------------------");

  delay(1000);
}
