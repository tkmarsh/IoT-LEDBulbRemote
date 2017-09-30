# LEDBulbRemote
**Currenly only works with ones from Home Bargains.**

This repo includes two sketches, one demonstrating the use of the ledRemote function (arduino-example.ino) and one that implements the function in a NodeMCU based IoT remote (NodeMCU.ino).

I've got a few different bulbs with different IR codes sitting around, so I might decode all the remotes and turn this into an RGWB LED Bulb remote library.

Arduino example uses [z3t0's library](https://github.com/z3t0/Arduino-IRremote) for sending IR codes, NodeMCU sketch uses [markszabo's library](https://github.com/markszabo/IRremoteESP8266).
