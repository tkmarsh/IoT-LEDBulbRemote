# LEDBulbRemote
## IoT LED Bulb controller

**Currenly only works with ones from Home Bargains.**

Sketch for NodeMCU boards that can be paired with IFTT to control bulbs using Google Assistant.

I've got a few different bulbs with different IR codes sitting around, so I might decode all the remotes and turn this into an RGWB LED Bulb remote library.

Arduino example uses [z3t0's library](https://github.com/z3t0/Arduino-IRremote) for sending IR codes, NodeMCU sketch uses [markszabo's library](https://github.com/markszabo/IRremoteESP8266).
