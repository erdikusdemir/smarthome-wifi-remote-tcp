


I am working on this project on left over times from my PhD thesis.  
For the version based on MQTT: https://github.com/erdikusdemir/smarthome-wifi-remote

# DESCRIPTION 

Portable remote controller to control smart home devices over TCP protocol. It is based on ESP8266 with OLED LCD and rotary encoder.
Remote can control switches, dimmers, fans, and temperature controllers.

The remote controller communicates with Node-Red flow by TCP messages. Node-Red flow converts the signals from both remote and HA side and makes implementation easier. Items you would like to control by remote can be edited by "config file" function. Arduino sketch only configures Wifi settings. All the item information are called at the initialization stage of the remote.

Wemos kill its power after 15 secs of idle time. Thus, power consumption of the remote is zero when it is not used. 

Hardware is consist of;
1. Wemos D1 mini Pro,
2. A clickable rotary encoder,
3. 0.96" I2C 128x64 OLED display,
4. Wemos battery shield,
5. LIPO battery,
6. 3D printed enclosure (under progress),  
7. TPS27081ADDCR load switch,  
8. 2222A NPN transistor,  
9. 330, 1 k, and 1 MOhm resistors.  

<img src="https://github.com/erdikusdemir/smarthome-wifi-remote/blob/master/remote_insidecover.jpg" width="600">
<img src="https://github.com/erdikusdemir/smarthome-wifi-remote/blob/master/Schematic.PNG" width="800">

# Instructions:  
1. Follow the schematic,  
2.1. Open the Arduino sketch and update your wifi information,  
2.2. Copy the libraries to documents/Arduino folder,  
3.1. Copy NodeRed flow into your NodeRed server,  
3.2. Configure your HA server,  
3.3. Configure your items by editing "config file" function,  
(id: order in your OLED screen, HAid: id name of item you want to control, type: switch(0), dimmer(1), or temperature controller(2))  
4.4. Deploy the node and everything should works.  

# To do list:
1. Code is slow for now. ESP spends time while sync process with Node-Red server.   
2. Previos messages needs to be ereased from the memory of the ESP.  
3. Memory of ESP might be used to store the items. This might improve the booting time. Aim is faster than 0.5s.

# Limitations:  
The number of an item is fixed to 20 because of code restrictions but it is possible to increase inside the Arduino code.  


