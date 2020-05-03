#include <chrono>

namespace cron = std::chrono;

/** return # of milliseconds since epoch */
long
now() {
  return cron::duration_cast<cron::milliseconds>
    (cron::system_clock::now().time_since_epoch()).count();
}
