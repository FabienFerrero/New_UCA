# New_UCA
Code for New UCA board

**Power consumption

![UCA](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/UCA.png "UCA")

LoRaWAN ABP code with deep sleep between packets.
Current in deep sleep mode is 6.5uA.

![LoRaWan power](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan.png "LoRaWan power")

After the sleep, the time0 counter is updated to avoid additional delay caused by duty cycle restriction.
A SF7 Tx including Rx windows has a 2.5s duration with 10mA average current.

![LoRaWan power2](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/lorawan2.png "LoRaWan power2")

** VN Bands support

Vietnam is using AS923-2 frequency bands. In comparison to AS923-1, an offset on all the freq. band is requested :
Group AS923-2: AS923_FREQ_OFFSET_HZ  = -1.80 MHz

![AS923-2](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/AS923-2.png "AS923-2")


The code support also the AS923-2 band.
It can be defined in the beginning of the code : 
Comment "define CFG_EU 1" and uncomment "define CFG_VN 1"

8 channels have been tested in uplink and downlink with a RAK831 gateway using this config :
https://github.com/FabienFerrero/New_UCA/blob/master/Misc/global_conf_AS923_2.json

For some strange reason, the gateway is not giving the good frequency, but the 8 channels are ok.

![VN](https://github.com/FabienFerrero/New_UCA/blob/master/Misc/VN_bands.png "VN")

REFERENCE : 
Adjust Time over flow after sleep based on : 
https://github.com/tomtor/RFM-node/blob/master/RFM-basic.ino

