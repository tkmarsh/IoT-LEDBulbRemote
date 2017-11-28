# LEDBulbRemote
**Currenly only works with ones from Home Bargains and B&M.**

This repo includes two sketches, one demonstrating the use of the ledRemote function (arduino-example.ino) and one that implements the function in a NodeMCU based IoT remote (NodeMCU.ino) and also works on generic standalone ESP8266s using the FTDI flasher.

I've got a few different bulbs with different IR codes sitting around, so I might decode all the remotes and turn this into an RGWB LED Bulb remote library.

Arduino example uses [z3t0's library](https://github.com/z3t0/Arduino-IRremote) for sending IR codes, NodeMCU/ESP8266 sketch uses [markszabo's library](https://github.com/markszabo/IRremoteESP8266).
