# Obstacle Avoiding Rover

21st century can be called as the era of automation and machine learning. Right from the self-driving cars to the mars rover, humanity has been testing its potentials to the maximum.

The below project is the necessary level of automation in the self-driving cars.

Obstacle voiding rover can detect obstacles in front of it and make decisions accordingly either to move left or right. It uses ultrasonic sensor to detect the object in front of it. Servo motor give the ultrasonic sensor some motion which makes it cover a longer range.

## Components used:

- Arduino Atmega 328
- Motor driver shield L293D
- Servo motor
- 2 set of motors or stepper motor
- Jumper wire
- 9v battery

## Workflow:

- Arduino acts as central processing unit where all the calculations are done. 
- Motor driver shield is used which controls the current to be given to the motors. Motor driver shield also reduced the backlog current from the motor which protects the Arduino.
- Servo motor gives the ultrasonic sensor flexibility so that it can cover a longer range.
- When an object comes in front of the rover, the rover stops for a sec, then the servo rotates covering an arc while the ultrasonic sensor takes he readings i.e distances.
- After this, the distance which is greater is selected and the rover moves in that direction.

### Make sure the jumper is removed from the motor shield before running the code.


The code above attached is a four-wheel-drive code.
If you feel that you guys don’t want the four-wheel-drive configuration, you can make it two-wheel drive and add a pivot with a ball at front and change the code accordingly.


### happy coding.







