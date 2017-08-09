# PID Control Project [![Udacity - Self-Driving Car NanoDegree](https://s3.amazonaws.com/udacity-sdc/github/shield-carnd.svg)](http://www.udacity.com/drive)

This is my solution of Project 9 of Udacity's Self Driving Car Nanodegree. 

## Implementation

- [PID.cpp](./src/PID.cpp)
- [PID.h](./src/PID.h)
- [main.cpp](./src/main.cpp)

## Reflection

#### Describe the effect each of the P, I, D components had in your implementation.

|component|effect|
|:---:|---|
|P "proportional"|Steer in proportion to the cross track error, if the error is large, the steering angle gets large, it tends to overshoot, the oscillation will increase if the value is too high|
|D "differential"|Considers the rate of change in the error, prevents overshooting the center line|
|I "integral"|Counteracts a bias in the cross track error, which prevents the PD controller from reaching the center line|

The following graphs and videos show the effect of different hyperparameter values: 

---------
In the following plot you can see the cte (cross-track-error) and the steering angle (total_error) when using Kp=0.1
![propotional only](./media/kp_0p1_30mph.png "propotional only")

and this is how it looks like in the simulator: [Video](./media/kp_0p1_30mph?raw=true)

---------
In the following plot you can see the cte (cross-track-error) and the steering angle (total_error) when using Kp=0.1 and Kd=0.9
![propotional and differential](./media/kp_0p1_kd_0p9_30mph.png "propotional and differential")

and this is how it looks like in the simulator: [Video](./media/kp_0p1_kd_0p9_30mph.m4v?raw=true)

---------
In the following plot you can see the cte (cross-track-error) and the steering angle (total_error) when using Kp=0.1, Kd=0.9 and Ki=0.005
![final pid](./media/kp_0p1_kd_0p9_ki_0.005_30mph.png "final pid")

and this is how it looks like in the simulator: [Video](./media/kp_0p1_kd_0p9_ki_0.005_30mph.m4v?raw=true)

#### Describe how the final hyperparameters were chosen.

I tuned the hyperparameters of the PID controller manually. First I started with only the proportional component as you can see in the images and the video above. In the next step I added the differential part, so the car gets around the track, but it was still unstable, especially after the first curve. I tuned these parameters so the car gets more stable. I added the integral component as well, but it had only a small impact on the track. Finally I get these hyperparameters by manually tunning:

|parameter|value|
|---|---|
|P|-0.1|
|I|-0.0001|
|D|-3.2|

With these parameters you get the car around the track. But there is still room for improvement. You can use for example an algorithm like twiddle to tune these parameters even more.


---
Udacity's original README
---

# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./
