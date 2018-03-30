# FreeModbus_Slave-Master-NOOS-STM32
freemodbus stm32 hal master slave noos
# Fork from
https://github.com/armink/FreeModbus_Slave-Master-RTT-STM32

becaule no os,only use poll and block to realize a simple event engine.
# RS485
* uart(pa9,pa10) 
* max485 tx/rx control pin (pa8)
# Build
* the project based of stm32f103c8,use the stm32cubemx to build the project
* the project use IAR,you can use other IDE or makefile to build the project,just config the stm32cubemx

# Stm32cubemx
download link:http://www.st.com/zh/development-tools/stm32cubemx.html
the *.ico file is stm32cubemx config file.
