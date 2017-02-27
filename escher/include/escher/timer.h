#ifndef ESCHER_TIMER_H
#define ESCHER_TIMER_H

#include <stdint.h>

/* Timers we'll need
 * - Blink cursor timer
 * - Dim Screen timer
 * - Power down timer
 * - Watchdog timer ?
 * - Battery level timer
 * - LED blink timer
 */

class Timer {
public:
  static constexpr int TickDuration = 100; // In Miliseconds
  Timer(uint32_t period); // Period is in ticks
  void tick();
  void reset();
protected:
  virtual void fire() = 0;
private:
  uint32_t m_period;
  uint32_t m_numberOfTicksBeforeFire;
};

#endif