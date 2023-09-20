/* Copyright 2021 HarrySizuku
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "HS28.h"

#ifdef RGB_MATRIX_ENABLE

led_config_t g_led_config = {
  {// Key Matrix to LED Index
    { 0,  1,  2,  3,  4,  5  },
    { 6,  7,  8,  9,  10, 11 },
    { 12, 13, 14, 15, 16, 17 },
    { 18, 19, 20, 21, 22, 23 },
    { 24, NO_LED, NO_LED, 25, 26, 27 },
    { 28, 29, 30, 31, 32, 33 }
  },
  {
    { 0,   7   }, { 40,  0   }, { 81,  4   }, { 122, 0   }, { 163, 0   }, { 204, 0   }, 
    { 0,   21  }, { 40,  14  }, { 81,  18  }, { 122, 14  }, { 163, 14  }, { 204, 14  }, 
    { 0,   36  }, { 40,  28  }, { 81,  32  }, { 122, 28  }, { 163, 28  }, { 204, 28  }, 
    { 0,   50  }, { 40,  42  }, { 81,  46  }, { 122, 42  }, { 163, 42  }, { 204, 42  }, 
    { 0,   64  },                             { 122, 57  }, { 163, 59  }, { 224, 61  }, 
    { 0,   61  }, { 100, 59  }, { 204, 55  }, { 204, 12  }, { 110, 12  }, { 2,   18  }
  },
  {
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1, 4, 4, 4, 4, 4,
    1,       1, 1, 1, 
    2, 2, 2, 2, 2, 2
};

#endif