# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Describe the effect each of the P, I, D components had in my implementation.

My implementation includes two PID controllers: steer controller and throttle controller. The car drives successfully around the track.

### Steer Controller

The goal of steer controller is to output a steer correction based on the value of cross-track error (CET).
The output of steer controller is constrained between -1 and 1.
The P, I, D parameters determines the change numerical value of steer. 

	- P component makes the car to steer proportional to the car's distance from the lane center. Increasing the weight P enlarges the steer response with sharp turns (and opposite). 

	- I component counteracts a bias between vehicle trajectory and target trajectory. It is proportional to the accumulate of CTE.  

	- D reacts to fast changing input signals. A properly tuned D parameter will make the car approach center line smoothly without swing.

### Throttle Controller

The goal of throttle controller is to control vihecle speed. Like hunman driver, the vehicle will have more time to correct its motion if it run slowly. I set speed constrains between 0.05 and 0.3. The P, I, D parameters and CTE determine the speed of vehicle by PID parameters:

	- P components makes the car speed to steer proportional to the car's distance from the lane center. If CET is large, the throtte controller will output a large negative value to decrease the vehicle speed.

	- I do not use I components in throttle controller and set it to zero.

	- D reacts to fast changing input signals. If CET change is huge, the throtte controller will output a large negative value to decrease the vehicle speed.

## Describe how the final hyperparameters were chosen.

First, I use hyperparameters used in lesson 17, which is P = 0.2, I = 0.004, D = 3.0. I compiled and ran application to see if these parameters work in simulator. The result showed that, with the parameters, the vehicle can successful to complete test, but the vehicle have obvious swing. 

To shortten swing, I tried to tune parameters by manually implementing twiddle method in the course. I finally got a good result with group of parameters (0.14, 0.0003, 3.0).

Besides, I noticed that the stear controller can't effect vehicle speed, which has influence for vehicle to correct its motion. Thus I add a new speed controller to control vehicle. When the CTE become large, the speed controller will make vehicle slow down. When the CTE become small, the speed controller will make vehicle fast. I also tuned this controller and found out it got a good result with parameters (0.3, 0.0, 0.02).

With these approaches, the vehicle can complete the test with slightly swing.
