# IKEA Rodulf ESP32
ESP32 tutorial for hacking your IKEA Rodulf to support web API 

### Pinout
Connect your ESP32 with relay module using this pinout
| ESP32         | Relay module  |
| ------------- | ------------- |
| VIN           | VCC           |
| GND           | GND           |
| D26           | IN1           |
| D27           | IN2           |

### RJ42 table connector
You can always repurpose an old LAN cable for this step.

IKEA uses RJ45 as the controller connector. Since there are only UP and DOWN directions, they utilize only 3 out of the 8 cables. These cables are orange for down, white/blue for up, and brown for ground. Connecting orange and brown would make the table go down, while connecting white/blue and brown would make the table go up.

| RJ45 Cable    | IKEA usage    |
| ------------- | ------------- |
| Orange        | Down          |
| White/Blue    | Up            |
| Brown         | GND           |

![eps32-ikea](https://github.com/ekv88/ikea-rodulf-eps32/assets/5781702/53f53a0c-635a-4f0c-b10a-2a843fe3379d)
