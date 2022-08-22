# smart-watering-system

Automate the process of watering your flower and get a relaxed mind as you would never be in a haste or worried that you forgot to water your flowers before leaving home 

## Components needed

| Name | Qty |
| :---: | :---: |
| Arduino uno | 1 |
| Buzzer | 1 |
| 16 * 2 lcd | 1 |
| 12v dc pump | 1 |
| Push button | 2 |
| 10k resistor | 3 | 
| Potentiometer | 1 |
| Soil moisture | 1 |
| Ultrasonic sensor | 1 |
| Tip41c (NPN transistor) | 1 |
| 12v dc power supply | 1 |

### Note 

- In this project i'm going to be making use of a custom soil moisture sensor which you can easily create at home

  - Check here to know how to make a custom soil moisture sensor[^1]
  - Click here for schematic with geninue soil moisture [^2]


[^1]: Since soil moisture deals with measuring the conductivity of the soil it can easily be reproduced. To do this simply Connect a 10k ohm resistor to your analouge signal pin and then to ground after which you take out jumpers from your 5v power supply and from the signal pin you pulled down with the 10k ohm resistor. If you're correct, you're circuit should be looking like this as i am currently using an led to indicate the two wires that are meant to go into your soil                                        ![moisture sensor](https://user-images.githubusercontent.com/65239245/185814108-e13458bc-3dc3-41fa-a580-5545dfe56310.png)


[^2]:**SCHEMATIC FOR GENUIE MOISTURE SENSOR**
  ![Circuit diagram without custom moisture sesnor](https://user-images.githubusercontent.com/65239245/185812297-cc50666b-79a8-4393-af1d-9c09d9c1bcae.png)

## Usage 

- Download the project [zip](https://github.com/n1lby73/smart-watering-system/archive/refs/heads/main.zip)

- Extract the project and save it in a folder with any name of your choice 

- Open up the *.ino file with [arduino ide](https://www.arduino.cc/en/software)

- Upload and wire your circuit using the schematics below


![circuit diagram](https://user-images.githubusercontent.com/65239245/185811462-699d7f81-4db8-4ba8-acc4-001bdbfc1be7.png)


## pin use
| Arduino digital pin | usage |
| :----: | :----: |
| pin 2 - 7 | LCD (rs,en,d4,d5,d6,d7) |
| pin 8 - 9 | Ultrasonic (tig, echo) | 
| pin 10 | Dc pump |
| pin 11 | Buzzer |
| pin 12 | Increase and next button |
| pin 13 | Decrease and previous button |


| Arduino analouge pin | usage |
| :----: | :----: |
| AO | Soil moisture sensor |

## Known issues
- [Random moisture values](https://github.com/n1lby73/smart-watering-system/issues/1#issue-1345617774)

## Support and bug reporting
- Report found bugs [here](https://github.com/n1lby73/smart-watering-system/issues)
- Contributions, issues, and feature requests are welcome!
- Feel free to make PR
- Give a ★ if you like this project!

## License

[GNU V3](https://github.com/n1lby73/remote-shutdown/blob/main/LICENSE)
