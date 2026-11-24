# Functional design: ESPHome Config Builder

## Purpose and use

Provide a simple, browser-only ESPHome YAML builder. Open `index.html` alongside
`tep-registers.js`, choose the device details and diagnostics, and optionally
add TEP or TEP-A controllers. Enter the shared UART pins, a unique Modbus
address, and the registers for each controller, then copy or download the live
preview. Place the YAML alongside your ESPHome
`secrets.yaml` and validate it with `esphome config <filename>.yaml` before
installing it. Add device-specific sensors, outputs, and other components
afterward.

## Decisions

- Use static files with no build system, server, dependencies, or network
  requests. Device details remain in the browser; the documentation link is
  only opened when the user chooses it.
- Offer common ESP32 variants and two ESP8266 boards; users must match the
  selection to their hardware.
- Include Wi-Fi, logging, an encrypted native API, and password-protected
  ESPHome OTA updates. Optionally include Wi-Fi signal and uptime sensors.
  Use the current platform-based OTA syntax and ESP32 variant syntax.
- Reference `wifi_ssid`, `wifi_password`, `api_encryption_key`, and
  `ota_password` from `secrets.yaml` rather than collecting credentials in the
  page. Set up those secrets before validation; use unique API keys and OTA
  passwords per device (use separate secret names when sharing a secrets file).
  Generate API keys as described in the linked ESPHome API documentation.
- Validate the device name before enabling copy or download, and quote the
  friendly name as a JSON string (valid YAML) so punctuation cannot change the
  generated structure. Show clipboard failures and allow manual copying.
- The TEP and TEP-A options use the shared V1.01 register map in
  `EPEver-TEP-ChargeController.md`. Controllers share one Modbus RTU bus at
  115200 baud, 8N1, and have independent addresses (1–100 per the map) and
  register selections. For a standard RS485 adapter, UART pins and optional
  transceiver direction control must be supplied by the user. The map
  identifies readings as `read`, so
  generated entities use ESPHome's `input` register type (function 04), while
  settings use `holding` (function 03); the old sample used `holding` for
  readings and should not be treated as protocol verification.
- Offer a dedicated checkbox for the EPlop RS485 to WIFI v1.5 board by Colin
  Hickey only when D1 mini is selected, and make D1 mini the default hardware.
  When checked, use its documented `TX`/`RX` UART aliases, disable
  serial logging with `logger.baud_rate: 0`, and set the Modbus UART,
  `flow_control_pin: D1`, ID `modbus1`, and `send_wait_time: 200ms` as specified.
  Its pin aliases require an ESP8266 target. Changing to another hardware option
  hides and clears the checkbox. The checkbox is only available when at least
  one TEP controller has been added. Otherwise, show user-configurable UART
  pins.
- Provide per-controller `Select all`, `Select none`, and `Default` register
  buttons. New controllers start with the example defaults: the 22 displayed
  sensor registers (including PV1 output voltage and current, which are disabled
  by default). Status entities, writable settings, and coils are opt-in.
- Let users name each TEP controller separately from the ESPHome node. Add that
  name as an ESPHome sub-device and link every generated controller entity to
  it with `device_id`, so Home Assistant groups the entities under that
  controller device.
- Select 32-bit measurements by their low-word address; `U_DWORD_R` reads both
  words in low-word-first order. Status register selection emits its documented
  fields, with text labels where the map defines codes, binary sensors for
  individual bits, and numeric codes where meanings are unspecified. Status
  code registers without documented values remain numeric. Avoid `/` in
  generated entity names because ESPHome reserves it as a URL path separator.
- Choose decimal places independently for each controller's reading registers.
  This sets ESPHome's `accuracy_decimals` without changing the register scale;
  Battery SOC defaults to zero decimal places.
- Writable settings use raw register units and documented raw limits. Where the
  map omits a limit, the representable 16-bit range is not a safety limit. RTC
  settings are packed words; baud rate is restricted to the documented options.
  Settings and coils are individually selectable and emitted disabled by
  default. Factory reset, clearing statistics, changing communication settings,
  and changing charging or protection settings can be disruptive. Users must
  review the protocol and equipment before enabling or writing them.
- Selecting BMS Protocol (`0x9040`) generates a disabled-by-default ESPHome
  Select with the 35 numbered choices in
  `BMS Communication Protocols & Fixed ID-EN-V1.5.pdf`. Option values write the
  PRO number from that table; the displayed fixed ID is informational and is
  not the register value.
- Keep the output editable by the user. This tool does not verify physical pin
  suitability, wiring, transceiver compatibility, controller responses, or
  setting interdependencies; it does not manage secrets, flash devices, or
  replace ESPHome validation.
