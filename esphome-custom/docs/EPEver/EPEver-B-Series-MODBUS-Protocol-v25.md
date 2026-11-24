# EPEver B-Series MODBUS Protocol v25 - Register Map

Source: `MODBUS-Protocol-v25.pdf` (document title: `B-Series MODBUS Specification`)

Applicable series named by the source: LS-B, VS-B, Tracer-B, Tracer-A, iTracer, and eTracer.

## Notes

- Protocol: Modbus-RTU.
- Default controller ID: `1`.
- Serial parameters: `115200 bps`, `8 data bits`, `1 stop bit`, no flow control.
- Register addresses are hexadecimal; the source's decimal-looking coil addresses are normalized to four-digit hexadecimal (for example, source address `13` is `0x0013`).
- Function code `02` is represented as `discrete_input`; function code `04` as `read`; function codes `03`/`10` as `holding`; and function code `05` as `coil`.
- The source's **Times** value is converted to a read filter: `100` becomes `multiply: 0.01`. A blank Times value or `1` produces no scaling filter.
- 32-bit values use two consecutive 16-bit registers. The low-word row uses the combined type (`U_DWORD_R` or `S_DWORD_R`); the high-word row is retained for documentation and marked `disabled_by_default`.
- Status and packed time registers are expanded into individual bit-field rows in the same style as the reference EPEver TEP Markdown.
- `Data Type`, `Access`, and `disabled_by_default` are implementation-oriented mappings added to match the reference Markdown. The source itself specifies addresses, function codes, descriptions, units, and scaling, but does not explicitly define ESPHome entity types.
- Source warning: choose the load control mode (`0x903D`) before setting its related parameters. Timer-2 behavior depends on the time-choice setting (`0x9069`).
- Source warning: battery voltage settings have ordering constraints, and writable battery parameters vary by battery type and charging mode. Review the protocol's battery-parameter warnings before writing values.

## Register Map

| No. | Modbus Address | Register Name | Unit | Function / Method | Parameter Description | Data Type | Access | Filters | Other Details | disabled_by_default |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| A1 | `0x2000` | Overtemperature Inside the Device |  | `discrete_input` | `1` controller temperature is above the protection point; `0` normal | `bool` | `binary_sensor` |  |  |  |
| A2 | `0x200C` | Day/Night |  | `discrete_input` | `1` night; `0` day | `bool` | `binary_sensor` |  |  |  |
| A3 | `0x3100` | PV Array Input Voltage | `V` | `read` | Solar charge controller PV array voltage | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A4 | `0x3101` | PV Array Input Current | `A` | `read` | Solar charge controller PV array current | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A5 | `0x3102` | PV Array Input Power (L) | `W` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A6 | `0x3103` | PV Array Input Power (H) |  |  | High word |  |  |  |  | `true` |
| A7 | `0x310C` | Load Voltage | `V` | `read` | Load voltage | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A8 | `0x310D` | Load Current | `A` | `read` | Load current | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A9 | `0x310E` | Load Power (L) | `W` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A10 | `0x310F` | Load Power (H) |  |  | High word |  |  |  |  | `true` |
| A11 | `0x3110` | Battery Temperature | `°C` | `read` | Battery temperature | `S_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A12 | `0x3111` | Device Temperature | `°C` | `read` | Device temperature | `S_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A13 | `0x311A` | Battery SOC | `%` | `read` | Battery remaining-capacity percentage | `U_WORD` | `sensor` |  |  |  |
| A14 | `0x311D` | Battery's Real Rated Voltage | `V` | `read` | `1200`, `2400`, `3600`, and `4800` represent 12 V, 24 V, 36 V, and 48 V | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A15.1 | `0x3200` | Battery Status - Rated Voltage Identification |  | `read` | `1` wrong rated-voltage identification | `U_WORD` | `text_sensor` |  | `D15` |  |
| A15.2 | `0x3200` | Battery Status - Internal Resistance |  | `read` | `1` abnormal; `0` normal | `U_WORD` | `text_sensor` |  | `D8` |  |
| A15.3 | `0x3200` | Battery Status - Temperature |  | `read` | `0x0` normal; `0x1` overtemperature; `0x2` low temperature | `U_WORD` | `text_sensor` |  | `D7-D4` |  |
| A15.4 | `0x3200` | Battery Status - Voltage |  | `read` | `0x0` normal; `0x1` overvoltage; `0x2` undervoltage; `0x3` overdischarge; `0x4` fault | `U_WORD` | `text_sensor` |  | `D3-D0` |  |
| A16.1 | `0x3201` | Charging Equipment Status - Input Voltage |  | `read` | `0x0` normal; `0x1` no input power connected; `0x2` high input voltage; `0x3` input-voltage error | `U_WORD` | `text_sensor` |  | `D15-D14` |  |
| A16.2 | `0x3201` | Charging Equipment Status - Charging MOSFET Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D13` |  |
| A16.3 | `0x3201` | Charging Equipment Status - Charging/Anti-Reverse MOSFET Open Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D12` |  |
| A16.4 | `0x3201` | Charging Equipment Status - Anti-Reverse MOSFET Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D11` |  |
| A16.5 | `0x3201` | Charging Equipment Status - Input Overcurrent |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D10` |  |
| A16.6 | `0x3201` | Charging Equipment Status - Load Overcurrent |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D9` |  |
| A16.7 | `0x3201` | Charging Equipment Status - Load Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D8` |  |
| A16.8 | `0x3201` | Charging Equipment Status - Load MOSFET Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D7` |  |
| A16.9 | `0x3201` | Charging Equipment Status - Three-Circuit Disequilibrium |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D6` |  |
| A16.10 | `0x3201` | Charging Equipment Status - PV Input Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D4` |  |
| A16.11 | `0x3201` | Charging Equipment Status - Charging State |  | `read` | `0x0` not charging; `0x1` float; `0x2` boost; `0x3` equalization | `U_WORD` | `text_sensor` |  | `D3-D2` |  |
| A16.12 | `0x3201` | Charging Equipment Status - Fault |  | `read` | `0` normal; `1` fault | `U_WORD` | `text_sensor` |  | `D1` |  |
| A16.13 | `0x3201` | Charging Equipment Status - Run State |  | `read` | `1` running; `0` standby | `U_WORD` | `text_sensor` |  | `D0` |  |
| A17.1 | `0x3202` | Discharging Equipment Status - Input Voltage |  | `read` | `0x0` normal; `0x1` low; `0x2` high; `0x3` no access | `U_WORD` | `text_sensor` |  | `D15-D14` |  |
| A17.2 | `0x3202` | Discharging Equipment Status - Output Power |  | `read` | `0x0` light load; `0x1` moderate; `0x2` rated; `0x3` overload | `U_WORD` | `text_sensor` |  | `D13-D12` |  |
| A17.3 | `0x3202` | Discharging Equipment Status - Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D11` |  |
| A17.4 | `0x3202` | Discharging Equipment Status - Unable to Discharge |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D10` |  |
| A17.5 | `0x3202` | Discharging Equipment Status - Unable to Stop Discharging |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D9` |  |
| A17.6 | `0x3202` | Discharging Equipment Status - Output Voltage Abnormal |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D8` |  |
| A17.7 | `0x3202` | Discharging Equipment Status - Input Overvoltage |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D7` |  |
| A17.8 | `0x3202` | Discharging Equipment Status - High-Voltage-Side Short Circuit |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D6` |  |
| A17.9 | `0x3202` | Discharging Equipment Status - Boost Overvoltage |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D5` |  |
| A17.10 | `0x3202` | Discharging Equipment Status - Output Overvoltage |  | `read` | `1` fault | `U_WORD` | `text_sensor` |  | `D4` |  |
| A17.11 | `0x3202` | Discharging Equipment Status - Fault |  | `read` | `0` normal; `1` fault | `U_WORD` | `text_sensor` |  | `D1` |  |
| A17.12 | `0x3202` | Discharging Equipment Status - Run State |  | `read` | `1` running; `0` standby | `U_WORD` | `text_sensor` |  | `D0` |  |
| A18 | `0x3302` | Maximum Battery Voltage Today | `V` | `read` | Refreshed daily at 00:00 | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A19 | `0x3303` | Minimum Battery Voltage Today | `V` | `read` | Refreshed daily at 00:00 | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A20 | `0x3304` | Consumed Energy Today (L) | `kWh` | `read` | Low word; cleared daily at 00:00 | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A21 | `0x3305` | Consumed Energy Today (H) |  |  | High word |  |  |  |  | `true` |
| A22 | `0x3306` | Consumed Energy This Month (L) | `kWh` | `read` | Low word; cleared at 00:00 on the first day of the month | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A23 | `0x3307` | Consumed Energy This Month (H) |  |  | High word |  |  |  |  | `true` |
| A24 | `0x3308` | Consumed Energy This Year (L) | `kWh` | `read` | Low word; cleared at 00:00 on January 1 | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A25 | `0x3309` | Consumed Energy This Year (H) |  |  | High word |  |  |  |  | `true` |
| A26 | `0x330A` | Total Consumed Energy (L) | `kWh` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A27 | `0x330B` | Total Consumed Energy (H) |  |  | High word |  |  |  |  | `true` |
| A28 | `0x330C` | Generated Energy Today (L) | `kWh` | `read` | Low word; cleared daily at 00:00 | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A29 | `0x330D` | Generated Energy Today (H) |  |  | High word |  |  |  |  | `true` |
| A30 | `0x330E` | Generated Energy This Month (L) | `kWh` | `read` | Low word; cleared at 00:00 on the first day of the month | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A31 | `0x330F` | Generated Energy This Month (H) |  |  | High word |  |  |  |  | `true` |
| A32 | `0x3310` | Generated Energy This Year (L) | `kWh` | `read` | Low word; cleared at 00:00 on January 1 | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A33 | `0x3311` | Generated Energy This Year (H) |  |  | High word |  |  |  |  | `true` |
| A34 | `0x3312` | Total Generated Energy (L) | `kWh` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A35 | `0x3313` | Total Generated Energy (H) |  |  | High word |  |  |  |  | `true` |
| A36 | `0x331A` | Battery Voltage | `V` | `read` | Battery voltage | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| A37 | `0x331B` | Battery Current (L) | `A` | `read` | Low word | `S_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| A38 | `0x331C` | Battery Current (H) |  |  | High word |  |  |  | Signedness is not explicitly stated in the source table. | `true` |
| B1 | `0x3005` | Rated Charging Current | `A` | `read` | Rated current to battery | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| B2 | `0x300E` | Rated Load Current | `A` | `read` | Rated current to load | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| B3 | `0x311D` | Battery's Real Rated Voltage | `V` | `read` | `1200`, `2400`, `3600`, and `4800` represent 12 V, 24 V, 36 V, and 48 V | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| B4 | `0x9000` | Battery Type |  | `holding` | `0x0000` user-defined; `0x0001` sealed; `0x0002` GEL; `0x0003` flooded | `U_WORD` | `number` |  |  | `true` |
| B5 | `0x9001` | Battery Capacity | `Ah` | `holding` | Rated battery capacity | `U_WORD` | `number / sensor` |  |  | `true` |
| B6 | `0x9002` | Temperature Compensation Coefficient | `mV/°C/2V` | `holding` | Source range: `0`-`9` engineering units | `S_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B7 | `0x9003` | Overvoltage Disconnect Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B8 | `0x9004` | Charging Limit Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B9 | `0x9005` | Overvoltage Reconnect Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B10 | `0x9006` | Equalize Charging Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B11 | `0x9007` | Boost Charging Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B12 | `0x9008` | Float Charging Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B13 | `0x9009` | Boost Reconnect Charging Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B14 | `0x900A` | Low Voltage Reconnect Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B15 | `0x900B` | Undervoltage Warning Recovery Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B16 | `0x900C` | Undervoltage Warning Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B17 | `0x900D` | Low Voltage Disconnect Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B18 | `0x900E` | Discharging Limit Voltage | `V` | `holding` |  | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B19 | `0x9067` | Battery Rated Voltage Level |  | `holding` | `0` auto-recognize; `1` 12 V; `2` 24 V; `3` 36 V; `4` 48 V; `5` 60 V; `6` 110 V; `7` 120 V; `8` 220 V; `9` 240 V | `U_WORD` | `number` |  |  | `true` |
| B20 | `0x906A` | Default Load On/Off in Manual Mode |  | `holding` | `0` off; `1` on | `U_WORD` | `number / switch` |  |  | `true` |
| B21 | `0x906B` | Equalize Duration | `min` | `holding` | Usually 60-120 minutes | `U_WORD` | `number` |  |  | `true` |
| B22 | `0x906C` | Boost Duration | `min` | `holding` | Usually 60-120 minutes | `U_WORD` | `number` |  |  | `true` |
| B23 | `0x906D` | Battery Discharge | `%` | `holding` | Usually 20%-80%; remaining capacity at which charging stops in SOC mode | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B24 | `0x906E` | Battery Charge | `%` | `holding` | Depth of charge; 100% | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| B25 | `0x9070` | Charging Mode |  | `holding` | `0` voltage compensation; `1` SOC | `U_WORD` | `number` |  |  | `true` |
| C1 | `0x0002` | Manual Control the Load |  | `coil` | When load control is manual: `1` on; `0` off | `bool` | `switch` |  |  | `true` |
| C2 | `0x901E` | Night-Time Threshold Voltage (NTTV) | `V` | `holding` | PV voltage below this value is treated as sundown | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| C3 | `0x901F` | Light-Signal Startup (Night) Delay | `min` | `holding` | Night is detected after PV voltage stays below NTTV for this delay | `U_WORD` | `number` |  |  | `true` |
| C4 | `0x9020` | Day-Time Threshold Voltage (DTTV) | `V` | `holding` | PV voltage above this value is treated as sunrise | `U_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| C5 | `0x9021` | Light-Signal Close (Day) Delay | `min` | `holding` | Day is detected after PV voltage stays above DTTV for this delay | `U_WORD` | `number` |  |  | `true` |
| C6 | `0x903D` | Load Control Mode |  | `holding` | `0x0000` manual; `0x0001` light ON/OFF; `0x0002` light ON + timer; `0x0003` timing control | `U_WORD` | `number` |  |  | `true` |
| C7.1 | `0x903E` | Light ON + Time (Timer 1) - Hour |  | `holding` | Timer 1 duration hour | `U_WORD` | `number` |  | `D15-D8` | `true` |
| C7.2 | `0x903E` | Light ON + Time (Timer 1) - Minute |  | `holding` | Timer 1 duration minute | `U_WORD` | `number` |  | `D7-D0` | `true` |
| C8.1 | `0x903F` | Light ON + Time (Timer 2) - Hour |  | `holding` | Timer 2 duration hour | `U_WORD` | `number` |  | `D15-D8` | `true` |
| C8.2 | `0x903F` | Light ON + Time (Timer 2) - Minute |  | `holding` | Timer 2 duration minute | `U_WORD` | `number` |  | `D7-D0` | `true` |
| C9 | `0x9042` | Timing Control - Turn ON Time 1 Seconds | `s` | `holding` | Turn on/off time of load output | `U_WORD` | `number` |  |  | `true` |
| C10 | `0x9043` | Timing Control - Turn ON Time 1 Minutes | `min` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C11 | `0x9044` | Timing Control - Turn ON Time 1 Hours | `h` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C12 | `0x9045` | Timing Control - Turn OFF Time 1 Seconds | `s` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C13 | `0x9046` | Timing Control - Turn OFF Time 1 Minutes | `min` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C14 | `0x9047` | Timing Control - Turn OFF Time 1 Hours | `h` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C15 | `0x9048` | Timing Control - Turn ON Time 2 Seconds | `s` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C16 | `0x9049` | Timing Control - Turn ON Time 2 Minutes | `min` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C17 | `0x904A` | Timing Control - Turn ON Time 2 Hours | `h` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C18 | `0x904B` | Timing Control - Turn OFF Time 2 Seconds | `s` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C19 | `0x904C` | Timing Control - Turn OFF Time 2 Minutes | `min` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C20 | `0x904D` | Timing Control - Turn OFF Time 2 Hours | `h` | `holding` |  | `U_WORD` | `number` |  |  | `true` |
| C21.1 | `0x9065` | Night-Time Length - Hour |  | `holding` | Default whole-night length hour | `U_WORD` | `number` |  | `D15-D8` | `true` |
| C21.2 | `0x9065` | Night-Time Length - Minute |  | `holding` | Default whole-night length minute | `U_WORD` | `number` |  | `D7-D0` | `true` |
| C22 | `0x9069` | Timing Control - Time Choice |  | `holding` | `0` use one time; `1` use two times; and so on | `U_WORD` | `number` |  |  | `true` |
| C23 | `0x906A` | Default Load On/Off in Manual Mode |  | `holding` | `0` off; `1` on | `U_WORD` | `number / switch` |  |  | `true` |
| D1.1 | `0x9013` | Real-Time Clock - Minute |  | `holding` | Write year, month, day, hour, minute, and second simultaneously | `U_WORD` | `number` |  | `D15-D8` | `true` |
| D1.2 | `0x9013` | Real-Time Clock - Second |  | `holding` | Write year, month, day, hour, minute, and second simultaneously | `U_WORD` | `number` |  | `D7-D0` | `true` |
| D2.1 | `0x9014` | Real-Time Clock - Day |  | `holding` |  | `U_WORD` | `number` |  | `D15-D8` | `true` |
| D2.2 | `0x9014` | Real-Time Clock - Hour |  | `holding` |  | `U_WORD` | `number` |  | `D7-D0` | `true` |
| D3.1 | `0x9015` | Real-Time Clock - Year |  | `holding` |  | `U_WORD` | `number` |  | `D15-D8` | `true` |
| D3.2 | `0x9015` | Real-Time Clock - Month |  | `holding` |  | `U_WORD` | `number` |  | `D7-D0` | `true` |
| E1 | `0x9017` | Battery Upper Temperature Limit | `°C` | `holding` |  | `S_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| E2 | `0x9018` | Battery Lower Temperature Limit | `°C` | `holding` |  | `S_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| E3 | `0x9019` | Device Overtemperature Limit | `°C` | `holding` |  | `S_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| E4 | `0x901A` | Device Recovery Temperature | `°C` | `holding` |  | `S_WORD` | `number / sensor` | `multiply: 0.01` |  | `true` |
| E5 | `0x9063` | Backlight Time | `s` | `holding` | Seconds before the LCD backlight closes | `U_WORD` | `number` |  |  | `true` |
| F1 | `0x3000` | Array Rated Voltage | `V` | `read` | PV array rated voltage | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F2 | `0x3001` | Array Rated Current | `A` | `read` | PV array rated current | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F3 | `0x3002` | Array Rated Power (L) | `W` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| F4 | `0x3003` | Array Rated Power (H) |  |  | High word |  |  |  |  | `true` |
| F5 | `0x3004` | Battery Rated Voltage | `V` | `read` | Rated voltage to battery | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F6 | `0x3005` | Battery Rated Current | `A` | `read` | Rated current to battery | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F7 | `0x3006` | Battery Rated Power (L) | `W` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| F8 | `0x3007` | Battery Rated Power (H) |  |  | High word |  |  |  |  | `true` |
| F9 | `0x300D` | Rated Load Voltage | `V` | `read` | Rated voltage to load | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F10 | `0x300E` | Rated Load Current | `A` | `read` | Rated current to load | `U_WORD` | `sensor` | `multiply: 0.01` |  |  |
| F11 | `0x300F` | Rated Load Power (L) | `W` | `read` | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` |  |  |
| F12 | `0x3010` | Rated Load Power (H) |  |  | High word |  |  |  |  | `true` |
| G1 | `0x0000` | Charging Device On/Off |  | `coil` | `1` charging device on; `0` charging device off | `bool` | `switch` |  |  | `true` |
| G2 | `0x0001` | Output Control Mode Manual/Automatic |  | `coil` | `1` manual; `0` automatic | `bool` | `switch` |  |  | `true` |
| G3 | `0x0002` | Manual Control the Load |  | `coil` | When load control is manual: `1` on; `0` off | `bool` | `switch` |  |  | `true` |
| G4 | `0x0003` | Default Control the Load |  | `coil` | When load control is default: `1` on; `0` off | `bool` | `switch` |  |  | `true` |
| G5 | `0x0005` | Enable Load Test Mode |  | `coil` | `1` enable; `0` disable (normal) | `bool` | `switch` |  |  | `true` |
| G6 | `0x0006` | Force the Load On/Off |  | `coil` | `1` on; `0` off; intended for temporary load testing | `bool` | `switch` |  |  | `true` |
| G7 | `0x0013` | Restore System Defaults |  | `coil` | `1` yes; `0` no | `bool` | `switch` |  |  | `true` |
| G8 | `0x0014` | Clear Generating-Electricity Statistics |  | `coil` | `1` clear; root privileges required | `bool` | `switch` |  |  | `true` |
