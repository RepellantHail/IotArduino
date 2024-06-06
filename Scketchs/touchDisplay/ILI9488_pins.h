// Header Setup
#include <Arduino_GFX_Library.h>
#include </home/jearim/Arduino/libraries/GFX_Library_for_Arduino/src/display/Arduino_ILI9488.h>
#include <../../../../../../arduino/libraries/GFX_Library_for_Arduino/src/databus/Arduino_HWSPI.h>

// Pin setup
#define MODEL ILI9488

#define CS_PIN 5    // Pin 8 for Chip Select
#define DC_PIN 4    // Pin 9 for Data/Command Select
#define RST_PIN 3   // Pin 10 for Reset
#define MOSI_PIN 10 // Pin 5 for Master Out Slave In (Data)
#define SCK_PIN 8   // Pin 3 for Serial Clock
#define LED_PIN 2   // Pin 11 for LED Backlight Control (Optional)
#define MISO_PIN -1 // Pin 13 for Master In Slave Out (Data)

// Touch Screen Pins
#define TCS_PIN 45  // Pin 6 for Touch Chip Select
#define TCLK_PIN 46 // Pin 12 for Touch Clock
#define TDO_PIN 47  // Pin 7 for Touch Data Out
#define TDI_PIN 48  // Pin 4 for Touch Data In
#define IRQ_PIN 49  // Pin 2 for Touch Interrupt

#define GFX_BL LED_PIN // backlight pin

#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */

// Initial setup
Arduino_DataBus *bus = new Arduino_HWSPI(DC_PIN, CS_PIN);
Arduino_GFX *gfx = new Arduino_ILI9488_18bit(bus, RST_PIN, 0, false);

#endif /* !defined(DISPLAY_DEV_KIT) */
       /*******************************************************************************
        * End of Arduino_GFX setting
        ******************************************************************************/