#include "main.h"
#include "gif-pros/gifclass.hpp"
#include "lemlib/asset.hpp"
#include "pros/rtos.hpp"
#include "robotconfig.h"

ASSET(david_gif)
ASSET(skillsmatchload_txt)

void initialize() {

  sylib::initialize();
  //chassis.calibrate();
  static Gif gif(david_gif, lv_scr_act());
  pros::delay(500);
}

void autonomous() { chassis.follow(skillsmatchload_txt, 5000, 5); }

void disabled() {
  intakeLED.gradient(0xFF0000, 0xFF0005, 0, 0, false, true);
  intakeLED.cycle(*intakeLED, 5);

  // Store the time at the start of the loop
  std::uint32_t clock = sylib::millis();
  while (true) {

    // 10ms delay to allow other tasks to run
    sylib::delay_until(&clock, 10);
  }
}

void opcontrol() {
  
  std::uint32_t clock = sylib::millis();

  while (true) {
    sylib::delay_until(&clock, 10);
  }
}
