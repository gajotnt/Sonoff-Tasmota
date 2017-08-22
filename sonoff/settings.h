/*
  settings.h - setting variables for Sonoff-Tasmota

  Copyright (C) 2017  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#define PARAM8_SIZE  23                    // Number of param bytes

typedef union {                            // Restricted by MISRA-C Rule 18.4 but so usefull...    
  uint32_t data;                           // Allow bit manipulation using SetOption
  struct {
    uint32_t savestate : 1;                // bit 0
    uint32_t button_restrict : 1;          // bit 1
    uint32_t value_units : 1;              // bit 2
    uint32_t mqtt_enabled : 1;             // bit 3
    uint32_t mqtt_response : 1;            // bit 4
    uint32_t mqtt_power_retain : 1;
    uint32_t mqtt_button_retain : 1;
    uint32_t mqtt_switch_retain : 1;
    uint32_t temperature_conversion : 1;   // bit 8
    uint32_t mqtt_sensor_retain : 1;
    uint32_t mqtt_offline : 1;             // bit 10
    uint32_t button_swap : 1;              // bit 11 (v5.1.6)
    uint32_t stop_flash_rotate : 1;        // bit 12 (v5.2.0)
    uint32_t button_single : 1;            // bit 13 (v5.4.0)
    uint32_t interlock : 1;                // bit 14 (v5.6.0)
    uint32_t spare15 : 1;
    uint32_t spare16 : 1;
    uint32_t spare17 : 1;
    uint32_t spare18 : 1;
    uint32_t spare19 : 1;
    uint32_t voltage_resolution : 1;
    uint32_t emulation : 2;
    uint32_t energy_resolution : 3;
    uint32_t pressure_resolution : 2;
    uint32_t humidity_resolution : 2;
    uint32_t temperature_resolution : 2;
  };
} sysBitfield;

struct SYSCFG {
  unsigned long cfg_holder;
  unsigned long saveFlag;
  unsigned long version;
  unsigned long bootcount;
  sysBitfield   flag;                      // Add flag since 5.0.2
  int16_t       savedata;
  
  int8_t        timezone;
  char          otaUrl[101];

  char          mqtt_prefix[3][11];        // was ex_friendlyname[33] until 3.2.5

  byte          serial_enable;             // Not used (ever)
  byte          seriallog_level;
  uint8_t       sta_config;
  byte          sta_active;
  char          sta_ssid[2][33];
  char          sta_pwd[2][65];
  char          hostname[33];
  char          syslog_host[33];
  uint16_t      syslog_port;
  byte          syslog_level;
  uint8_t       webserver;
  byte          weblog_level;

  char          mqtt_fingerprint[60];
  char          mqtt_host[33];
  uint16_t      mqtt_port;
  char          mqtt_client[33];
  char          mqtt_user[33];
  char          mqtt_pwd[33];
  char          mqtt_topic[33];
  char          button_topic[33];
  char          mqtt_grptopic[33];
  char          ex_state_text[3][11];      // was state_text until 5.1.6, was ex_mqtt_subtopic[33] until 4.1.1
  byte          ex_mqtt_button_retain;     // Not used since 5.0.2
  byte          ex_mqtt_power_retain;      // Not used since 5.0.2
  byte          ex_value_units;            // Not used since 5.0.2
  byte          ex_button_restrict;        // Not used since 5.0.2
  uint16_t      tele_period;

  uint8_t       power;
  uint8_t       ledstate;

  uint8_t       param[PARAM8_SIZE];        // was domoticz_in_topic until 5.1.6
  char          state_text[4][11];         // was domoticz_out_topic until 5.1.6
  
  uint16_t      domoticz_update_timer;
  unsigned long domoticz_relay_idx[4];
  unsigned long domoticz_key_idx[4];

  unsigned long wattmtr_pcal;
  unsigned long wattmtr_ucal;
  unsigned long wattmtr_ical;
  unsigned long wattmtr_kWhtoday;
  unsigned long wattmtr_kWhyesterday;
  uint16_t      wattmtr_kWhdoy;
  uint16_t      wattmtr_pmin;
  uint16_t      wattmtr_pmax;
  uint16_t      wattmtr_umin;
  uint16_t      wattmtr_umax;
  uint16_t      wattmtr_imin;
  uint16_t      wattmtr_imax;
  uint16_t      wattmtr_mpl;    // MaxPowerLimit
  uint16_t      wattmtr_mplh;   // MaxPowerLimitHold
  uint16_t      wattmtr_mplw;   // MaxPowerLimitWindow
  uint16_t      wattmtr_mspl;   // MaxSafePowerLimit
  uint16_t      wattmtr_msplh;  // MaxSafePowerLimitHold
  uint16_t      wattmtr_msplw;  // MaxSafePowerLimitWindow
  uint16_t      wattmtr_mkwh;   // MaxEnergy
  uint16_t      wattmtr_mkwhs;  // MaxEnergyStart

  // 3.0.6
  uint16_t      mqtt_retry;                // was ex_pulsetime until 4.0.4

  // 3.1.1
  uint8_t       poweronstate;

  // 3.1.6
  uint16_t      blinktime;
  uint16_t      blinkcount;

  // 3.2.4
  uint16_t      ws_pixels;
  uint8_t       ws_red;
  uint8_t       ws_green;
  uint8_t       ws_blue;
  uint8_t       ws_ledtable;
  uint8_t       ws_dimmer;
  uint8_t       ws_fade;
  uint8_t       ws_speed;
  uint8_t       ws_scheme;
  uint8_t       ws_width;
  uint16_t      ws_wakeup;

  // 3.2.5
  char          friendlyname[4][33];

  // 3.2.8
  char          switch_topic[33];
  byte          ex_mqtt_switch_retain;     // Not used since 5.0.2
  uint8_t       ex_mqtt_enabled;           // Not used since 5.0.2

  // 3.2.12
  uint8_t       sleep;

  // 3.9.3
  uint16_t      domoticz_switch_idx[4];
  uint16_t      domoticz_sensor_idx[12];
  uint8_t       module;
  mytmplt       my_module;
  uint16_t      led_pixels;
  uint8_t       led_color[5];
  uint8_t       led_table;
  uint8_t       led_dimmer[3];
  uint8_t       led_fade;
  uint8_t       led_speed;
  uint8_t       led_scheme;
  uint8_t       led_width;
  uint16_t      led_wakeup;

  // 3.9.7
  uint8_t       ex_emulation;              // Not used since 5.0.2

  // 3.9.20
  char          web_password[33];

  // 3.9.21
  uint8_t       switchmode[4];

  // 4.0.4
  char          ntp_server[3][33];
  uint16_t      pulsetime[MAX_PULSETIMERS];

  // 4.0.7
  uint16_t      pwmvalue[5];

  // 4.0.9
  uint32_t      ip_address[4];

  // 5.0.4
  unsigned long wattmtr_kWhtotal;

  // 5.0.4a
  char          mqtt_fulltopic[101];

  // 5.1.1
  unsigned long pCounter[MAX_COUNTERS];
  uint16_t      pCounterType;
  uint16_t      pCounterDebounce;

  // 5.4.1
  uint8_t       sfb_code[17][9];

  // Next version
  unsigned long pzem_Whstart;
} sysCfg;

struct RTCMEM {
  uint16_t      valid;
  byte          osw_flag;
  uint8_t       power;
  unsigned long wattmtr_kWhtoday;
  unsigned long wattmtr_kWhtotal;
  unsigned long pCounter[MAX_COUNTERS];
} rtcMem;

// See issue https://github.com/esp8266/Arduino/issues/2913  
#ifdef USE_ADC_VCC
  ADC_MODE(ADC_VCC);                        // Set ADC input for Power Supply Voltage usage
#endif

