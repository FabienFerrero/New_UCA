# New_UCA
Code for New UCA board

LoRaWAN ABP code with deep sleep between packets.

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan.png "LoRaWan power")

After the sleep, the time0 counter is updated to avoid additional delay caused by duty cycle restriction.

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan2.png "LoRaWan power")


The code support also the AS923-2 bands (used in Vietnam).
It can be defined in the beginning of the code : comment
>defined CFG_EU 
and uncomment 
>defined CFG_VN

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/VN_bands.png "LoRaWan power")

REFERENCE : 
Adjust Time over flow after sleep based on : 
https://github.com/tomtor/RFM-node/blob/master/RFM-basic.ino

