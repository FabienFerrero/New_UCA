# New_UCA
Code for New UCA board

LoRaWAN ABP code with deep sleep between packets.
Current in deep sleep mode is 6.5uA.

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan.png "LoRaWan power")

After the sleep, the time0 counter is updated to avoid additional delay caused by duty cycle restriction.
A SF7 Tx including Rx windows has a 2.5s duration with 10mA average current.

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan2.png "LoRaWan power")


The code support also the AS923-2 bands (used in Vietnam).
It can be defined in the beginning of the code : 
Comment "define CFG_EU 1" and uncomment "define CFG_VN 1"

8 channels have been tested in uplink and downlink with a RAK831 gateway using this config :
https://github.com/FabienFerrero/New_UCA/blob/master/Misc/global_conf_AS923_2.json

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/VN_bands.png "LoRaWan power")

REFERENCE : 
Adjust Time over flow after sleep based on : 
https://github.com/tomtor/RFM-node/blob/master/RFM-basic.ino

