# IKEAPS2014
Control your IKEA PS 2014 lamp with a servo motor and Wemos d1 mini (ESP8266) via Alexa – dimmable solution 💡

The year is 2021 and I finally manage to put my Ikea hack online. Of course, there are already a number of hacks to be found on the internet. The special thing about this tutorial is that I set myself as a goal that it is easy to replicate, components are easily replaceable and most importantly, the lamp not only just opens and closes: It is dimmable! You can open the lamp for example 20% or 80%.
In the end, I only use the ESP8266 and a servo with feedback, but more details will follow after the short animation of the working lamp:
<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/120012386-b6c66680-bfdf-11eb-8f2e-1126270ea012.gif" width="800" align="center">
</p>

## Materials
1. [1x IKEA PS 2014 lamp](https://www.ikea.com/de/de/p/ikea-ps-2014-haengeleuchte-weiss-silberfarben-90311494/)
2. [1x WeMos D1 Mini](https://www.amazon.de/dp/B01N9RXGHY)
3. [1x Micro USB cable](https://www.amazon.de/dp/B01A9GLG6Q/)
4. [1x Feetech FB5317M 360° Servo - includes Analog Feedback with Magnetic Encoder](https://www.premium-modellbau.de/feetech-fb5317m-3600-cont-digital-servo-65g-17-5kg-feedback-arduino)
5. [1x servo mount](https://www.amazon.de/dp/B07SGPBCHM)
6. [1x sewing thread spool](https://www.amazon.de/dp/B074HF2KZV/)
7. [1x power supply 5V](https://www.amazon.de/dp/B00MWQD43U/)
8. [2x Wago connection clamp 3 x 0,2-4mm²](https://www.amazon.de/dp/B071ZHC2QH)
9. [2x 10cm braids 1,5mm² thickness for 230V](https://www.amazon.de/dp/B077JZNWV7)
10. [2x jumper cable male](https://www.amazon.de/dp/B01EV70C78/)
11. [1x 30cm 4-core white cable or 8-core flat ribbon telephone cable for extension from motor to ceiling](https://www.amazon.de/dp/B07TGKPFHK/)
12. [7x white cable ties](https://www.amazon.de/dp/B07JMKK66N)
13. [Optional: Crimping tool for cable lugs](https://www.amazon.de/gp/product/B07QMHNKW3)
14. [Optional: Crimping tool Dupont Set](https://www.amazon.de/dp/B078K9DT69/)
15. 3D printer for [servoHolder.stl](https://github.com/julisa99/IKEAPS2014/blob/main/servoHolder.stl)

## Preparation
Remove the white plastic spool from the frame of the lamp (see graphic) and cut the cord so that one side of the cord is longer than the other. We will knot the longer side to the sewing thread spool later. You can make the shorter side even shorter, because one cord with ball will be decoration.
<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121745419-8e248d80-cb04-11eb-882a-920219b43b77.png" width="400" align="center">
</p>

## Composition
Be careful, please check that you have turned off the fuses of your power supply, because 230V are dangerous - I know that even without being an electrician ;)
<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121742355-00df3a00-cb00-11eb-8079-ed36551967be.png" width="600" align="center">
</p>

As you can see in my graphic, the wiring is not complicated. I was helped by the orange Wago clamps and that I used cable lugs. But now follows a little explanation:

The servo motor has four cables. The orange one (analog feedback) you plug into A0 of the Wemos. The white data cable you plug into D0. I don't do the power supply for the motor via the microcontroller, because it only gives up to 500mA via the pins, but the motor could overload this, because it draws up to 1800mA when it turns with resistance. The power for the motor and microcontroller comes from the power supply, which outputs 5V. To make the four cables fit to the 2 connectors, I feed + and - together through each of the wago terminals and put a jumper cable in there. Then I screw the respective jumper cables (red: + and black: -) to the power supply by replacing the end with cable lugs.
I then connect the yellow ground cable from the ceiling to the ground of the power supply. Then I attach cable lugs to two 10cm cables (with 1,5mm² thickness because of the 230 V) to attach them at N and L between the power supply and the lamp as shown in the graphic with the brown and blue cable.

I later place the servo motor in the lamp and put everything else up in the tray on the ceiling. Since the four cables from the motor are too short to reach from the ceiling to the center of the lamp, I used a white flat telephone cable and connected that as a 30cm extension to the cable ends from the motor and then the other end of the telephone cable into the microcontroller. My phone cable had 8 wires, where I then attached Dupont connectors myself, so that always 2 wires were together and I thus had 4. Alternatively you can use a 4-wire cable. (I only own a cable drum with 100m telephone cable, which may become empty. If you are from Germany near Berlin I can give you some :D)

<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121745950-6255d780-cb05-11eb-8403-77a0b9b4c8b2.jpg" width="400" align="center">
<img src="https://user-images.githubusercontent.com/8758907/121746098-a2b55580-cb05-11eb-8393-1c021d274762.jpg" width="150" align="center">
<img src="https://user-images.githubusercontent.com/8758907/121746227-d7291180-cb05-11eb-8e12-151af13b4ca2.jpg" width="150" align="center">
</p>

That was all about the cabling. Now only the attachment of the sewing thread spool to the motor and then the attachment of the motor in the lamp is missing.
I screwed the sewing thread spool to the black circular servo horn with two small screws and then screwed the servo horn to the motor.
<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121747320-84e8f000-cb07-11eb-894a-9f0c07405b76.png" width="600" align="center">
</p>

I then screwed the motor to the aluminum servo holder I bought and then made my own 3D model [servoHolder.stl](https://github.com/julisa99/IKEAPS2014/blob/main/servoHolder.stl) where I screwed the servo holder to it. My 3D model consists of a rod with two slots at the ends, where a cable tie is attached, which then holds on the frame of the lamp. This makes it easy to remove the motor at any time. 
<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121748065-aac2c480-cb08-11eb-9b6b-41345d6445e3.jpg" width="600" align="center">
</p>

Afterwards you attach the white cord of the lamp to the metal sewing thread spool with a knot. With further cable ties you can lead your cable along the frame up to the ceiling. The assembly is finished!

<p align="center">
<img src="https://user-images.githubusercontent.com/8758907/121748607-903d1b00-cb09-11eb-8a0a-87a0942c686b.jpg" width="400" align="center">
</p>

## Arduino IDE and library
In order to control the ESP8266, the following address must be added in the Arduino IDE under `File->Preferences->Additional Board Manager URLs`: http://arduino.esp8266.com/stable/package_esp8266com_index.json. Then you can type "esp8266" in the search field under `Tools->Board->Boards Manager`and click on `Install`. Now the `LOLIN(WEMOS) D1 R1 & mini` appears under the boards and can be selected.

For communication with Alexa I use the library "espalexa" with version 2.4.7. There is a small bug, which is fixed, if in line 197 in Espalexa.h `arg(0)` is changed to `argName(0)`.

In line 5 and 6 of [IKEAPS2014.ino](https://github.com/julisa99/IKEAPS2014/blob/main/IKEAPS2014.ino) you have to enter your access data for your wifi. After that you can upload the code to your microcontroller. After that you can ask Alexa to search for new devices and you should find the device "star".

## How it works
When you command Alexa "Open star to 20%", then the function `deviceChanged(brightness)` is executed, where the 20% is passed there as `brightness` of "51", since brightness value is between 0-255.
Now I calculate how often the sewing thread spool has to rotate. I have set `MAX_ROTATION` to how many times my cord must be wound on the sewing thread spool until the lamp is fully open. In my case, `MAX_ROTATION` is 4500, which would be ~4.4 revolutions (=4500/1024). This is because the encoder of the motor provides values of 0-1024 for the rotation range of 0°-360°. So I calculate 20% of 4500 (=900) and that is then the target for the motor. 

Now I decide in which direction the motor has to rotate to achieve the target position. Because the encoder is sometimes a bit inaccurate, I use an offset for the target position, which can be adjusted arbitrarily. If the 20% is not reached, the lamp will either move open or close until the 20% is reached.
Here the function `onRotate(direction)` is used. This counts how many rounds the sewing thread spool has been rotated. Whenever the value of `FEEDBACK_PIN` changes between 1024 and 0, a round is done. Therefore I calculate the difference between the last position value and the current one. Since the encoder is imprecise, I don't check for exactly 1024 but only if the amount of the difference is greater than 500. I stop spinning the sewing thread spool as soon as the correct number of rounds and degrees is reached.

That's it, so the lamp can be moved dimmable.
