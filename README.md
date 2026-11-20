# 9568Z Regionals

Robot code for VEX V5 team **9568Z**, written for the 2024–25 *High Stakes* season. It's a [PROS](https://pros.cs.purdue.edu/) (C++) project that uses [LemLib](https://github.com/LemLib/LemLib) for odometry and motion control.

## Features

- Drivetrain with 3-motor blue-cartridge sides, IMU, and horizontal and vertical tracking wheels, using LemLib odometry
- Arm with rotation-sensor feedback, intake, goal clamp, doinkers and a pneumatic piston ("pistake")
- Autonomous routines for both alliances, plus skills runs
- Controller screen display helpers and button macros

## Project layout

```
src/
  main.cpp            Competition entry points (initialize, autonomous, opcontrol)
  robot-config.cpp    Motors, sensors, pneumatics and LemLib chassis setup
  autons/
    pos/              Positive-side autons (3+1 qual, 5 ring, safe, SAWP)
    neg/              Negative-side autons (5+1 qual, anti-rush)
    skill/            Skills routines
    test/             Test auton for tuning
  utils/              Controller display and driver macros
include/              Headers, plus the PROS, LVGL, fmt and LemLib APIs
firmware/             PROS and LemLib prebuilt libraries and linker scripts
project.pros          PROS project metadata
```

## Building

Requires the [PROS CLI](https://pros.cs.purdue.edu/v5/getting-started/index.html).

```bash
pros make          # build
pros mu            # build and upload to the brain
```

Dependencies: PROS kernel 4.1.1, LemLib 0.5.5 and LVGL 8.3.8, as listed in `project.pros`.

## Configuring for your robot

Port numbers, motor gearsets and tuning constants live in [`src/robot-config.cpp`](src/robot-config.cpp). Change those to match your own build before running anything.

## License

[MIT](LICENSE)
