# Walk-e
This is a repo containing scripts for Walk-e, a smart walker that utilizes ML algorithm object detection and a number of various alerts controlled by Arduino microcontroller 

## Purpose:
Walk-e is a walker that is enhanced with intelligent technology. An object detection machine learning algorithm is incorporated into it. It is managed by an Arduino microcontroller to provide alerts and warnings based on the environment, thus increasing user safety. By integrating advanced technology into a conventional mobility aid, this innovative device aims to improve the overall walking experience and prevent falls for individuals facing mobility issues. The product aims to enrich the lives of individuals, restore their independence and boost confidence. 

![image](https://github.com/kapis20/Walk-e/assets/87130809/f7cb8916-d384-4c62-a9fc-9516d806150c)


## High-Level user manuals:
### Set up:
1) Power up Raspberry Pi - connect the white plug to the mains and type-c end to the Raspberry Pi.
2) Connect HDMI0 on Raspberry Pi to HDMI on the monitor.
   ![image](https://github.com/kapis20/Walk-e/assets/87130809/e1248caa-0172-42b7-9345-fd37b1b740bb)

3) Attach the mouse and keyboard to the Raspberry Pi through the black USB ports on the left.   
![image](https://github.com/kapis20/Walk-e/assets/87130809/89f42562-065b-4cf4-bf30-04b7240b601a)

4) Connect the grey USB cable to the 5V and 1A power supply. It can be attached to the computer/laptop.
![image](https://github.com/kapis20/Walk-e/assets/87130809/2d25db6c-ab95-4e42-ba99-8cf59f2267be)

5) Connect a black USB cable from Arduino to a serial port on Raspberry Pi. Either one of the blue USB ports on Raspberry Pi.
![image](https://github.com/kapis20/Walk-e/assets/87130809/2f4ac62e-1e11-4337-80c0-69af9aac8ffd)

6) When you power on the device, the vibration motor will emit a short sound and the LED strips will briefly turn blue before turning off. Additionally, you should be able to view the Raspberry Pi turning on through your monitor.
7) If nothing happens, try disconnecting Raspberry Pi from the mains for a few seconds and then power it up again. 

### Turn the program on:
1) Open the command terminal and paste the following code (also available in code.txt) :
      cd ~/Projects/Python/tflite
      source tflite-env/bin/activate
      cd object_detection
      python TFLite_detection_webcam.py --modeldir=coco_ssd_mobilenet_v1
   
2) If successful, you should be able to see a camera window on the screen. The LED strip should be emitting blue light unless an obstacle is detected. Also in the command window, you should be able to see the names of the objects and their coordinates.
![image](https://github.com/kapis20/Walk-e/assets/87130809/9d8b357c-5496-41e7-82a6-f0187bee90e7)

3) Sometimes there is an issue with a serial port on Raspberry Pi. If a problem arises with the serial port, none of the actions outlined in step 2 will occur and an error message will be displayed in the command terminal.
4) To fix it, navigate to /home/pi/Projects/Python/tflite/object_detection/TFLite_detection_webcam.py
5) In Line 102 of the code : serial_port = “/dev/ttyACM [CHANGE HERE]. Replace 0 with 1, or 1 with 0.
![image](https://github.com/kapis20/Walk-e/assets/87130809/9351c624-9a3f-4e20-8934-be925d13533c)
6) Save the code and follow step 1 again.


## The normal operation of the system 
This code is based off the TensorFlow Lite image classification example at:
https://github.com/tensorflow/tensorflow/blob/master/tensorflow/lite/examples/python/label_image.py
Modified by: Shawn Hyme who added method of drawing boxes and labels using OpenCV
and modified by Boon K Teo, Mahmoud Elhelaly and KAcper Sikorski who established the serial communication between the Raspberry Pi and Arduino to send commands that trigger various alerts in the system. 

1) In the picture below is the lists of objects and different colours they were assigned to: 
![image](https://github.com/kapis20/Walk-e/assets/87130809/f1b0de36-3e5d-4041-b739-8e5d323ee671)



2) Interest is a collection of object categories that trigger various alerts.
![image](https://github.com/kapis20/Walk-e/assets/87130809/dd29904d-bdc1-4448-8090-b3e18666f18f)

3) These objects are used later in the code to display warnings on the screen (Raspberry Pi display).
![image](https://github.com/kapis20/Walk-e/assets/87130809/5e927d8c-2472-487b-bbf3-a94b9fd2ecd0)

