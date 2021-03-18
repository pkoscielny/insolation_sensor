# Insolation sensor
Insolation sensor project based on ESP8266 device. It measures resistance dependent value and then sends the result to the given ZeroIoT server once per minute.
The resistance corelates with insolation value.

## Hardware

### List of components
* ESP8266 WeMos D1 mini board
* GL5528 10k-20k photoresistor
* 10k resistor

### Breadboard circuit diagram
![circuit](/fz/insolation_sensor.png)


### Visualisation of data from the sensor 

#### Sunny day. There were some clounds in the morning and then the sky was clear

![sunny](/img/sunny_day_24h.png)


#### Rainy days

![rainy](/img/rainy_day_24h.png)


#### Sunny and cloudy days a month

![month](/img/sunny_and_cloudy_days_month.png)

