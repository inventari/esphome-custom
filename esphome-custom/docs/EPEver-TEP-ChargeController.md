# TEP & TEP-A Series Solar Charge Controller Communication Protocol V1.01 - Register Map

Source: `TEP&TEP-ASeries Solar Charge Controller Communication Protocol-V1.01-EN.pdf`

## Notes

- Protocol: Modbus-RTU.
- Default controller ID: `1`.
- Serial parameters: `115200 bps`, `8 data bits`, `1 stop bit`, no flow control.
- 32-bit values use two 16-bit registers: low word `(L)` and high word `(H)`. ESP Home would use 
  - If the actual charging input power is `3000` and the data multiplier is `0.01`, the
value of this variable register `0x3002` (L) = `0x93E0` (37856) and the value of register `0x3003` (H) = `0x0004` (4) this should be evaludated as `0x000493E0` (300000).

## Register Map

| No. | Modbus Address | Register Name | Unit | Function / Method | Parameter Description | Data Type | Access | Filters | Other Details |
| ---: | --- | --- | --- | --- | --- | --- | --- | ---: | --- |
| 1  | `0x3100` | PV1 Input Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 2  | `0x3101` | PV1 Input Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 3  | `0x3102` | PV1 Input Power (L) | `W` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 4  | `0x3103` | PV1 Input Power (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 5  | `0x3104` | PV1 Output Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 6  | `0x3105` | PV1 Output Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 7  | `0x3106` | PV1 Output Power (L) | `W` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 8  | `0x3107` | PV1 Output Power (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 9  | `0x3108` | PV2 Input Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 10  | `0x3109` | PV2 Input Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 11  | `0x310A` | PV2 Input Power (L) | `W` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 12  | `0x310B` | PV2 Input Power (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 13  | `0x310C` | PV2 Output Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 14  | `0x310D` | PV2 Output Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 15  | `0x310E` | PV2 Output Power (L) | `W` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 16  | `0x310F` | PV2 Output Power (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 17  | `0x3114` | Battery Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 18  | `0x3115` | Battery Total Charging Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 19  | `0x3116` | Battery Total Discharging Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 20  | `0x3117` | Battery Total Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 21  | `0x3118` | Remote Battery Temperature | `°C` | `read` / `holding`? |  | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 22  | `0x3119` | Battery SOC | `%` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 23  | `0x311A` | Equipment Temperature | `°C` | `read` / `holding`? |  | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 24  | `0x311D` | Current System Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 25  | `0x311E` | The Higher PV Voltage Between Two Inputs | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 26  | `0x311F` | PV Total Charging Current | `A` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 27  | `0x3120` | PV Total Charging Power (L) | `W` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 28  | `0x3121` | PV Total Charging Power (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 29  | `0x3002` | PV Maximum Input Voltage | `V` | `read` / `holding`? | Rated voltage of PV | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 30  | `0x3003` | PV Maximum Input Current | `A` | `read` / `holding`? | Rated current of PV | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 31  | `0x3004` | PV Input Rated Power (L) | `W` | `read` / `holding`? | Rated power of PV, low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 32  | `0x3005` | PV Input Rated Power (H) |  | `read` / `holding`? | Rated power of PV, high word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 33  | `0x3006` | Battery Rated Voltage | `V` | `read` / `holding`? | Rated voltage of DC output terminal | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 34  | `0x3007` | Battery Rated Charging Current | `A` | `read` / `holding`? | Rated current for charging battery | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 35  | `0x3008` | Battery Rated Charging Power (L) | `W` | `read` / `holding`? | Rated power of PV, low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 36  | `0x3009` | Battery Rated Charging Power (H) |  | `read` / `holding`? | Rated power of PV, high word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 37  | `0x3200` | Battery Status |  | `read` / `holding`? | D3-D0: 01 Overvoltage, 00 Normal, 02 Undervoltage, 03 Overdischarge. D7-D4: 00 Normal, 01 Overtemperature. D9: Lithium battery charging protection. D10: Lithium battery discharging protection. | `U_WORD` | `sensor` |  | 1-bit |
| 38  | `0x3202` | Equipment Charging Status 1 |  | `read` / `holding`? | D15-D14 PV1 voltage input status; D13-D10 charging MOSFET short circuits; D5 equipment overtemperature; D4 PV1 or battery reversed; D3-D2 charging status; D1 day/night; D0 PV1 status. | `U_WORD` | `sensor` |  | 1-bit |
| 39  | `0x3203` | Equipment Charging Status 2 |  | `read` / `holding`? | D15-D14 PV2 voltage input status; D11/D10 PV mode alarms; D9 PPL low battery; D8 dry contact; D7/D6 relay errors; D5 MPPT status; D4 PV2 or battery reversed; D0 PV2 status. | `U_WORD` | `sensor` |  | |
| 40  | `0x3205` | Equipment Status |  | `read` / `holding`? | D15 Parallel ID repetition; D14 DSP communication fault; D13 SOC full charge; D12 SOC too low; D11-D2 BMS/cell protections and faults; D1 low SOC alarm; D0 BMS online/offline. | `U_WORD` | `sensor` |  | |
| 41  | `0x3300` | Today PV Highest Input Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 42  | `0x3301` | Today Highest Battery Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 43  | `0x3302` | Today Lowest Battery Voltage | `V` | `read` / `holding`? |  | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 44  | `0x330B` | Today Total Generation (L) | `kWh` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 45  | `0x330C` | Today Total Generation (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 46  | `0x330D` | This Month Total Generation (L) | `kWh` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 47  | `0x330E` | This Month Total Generation (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 48  | `0x330F` | This Year Total Generation (L) | `kWh` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 49  | `0x3310` | This Year Total Generation (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 50  | `0x3311` | Total Generation (L) | `kWh` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 51  | `0x3312` | Total Generation (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 52  | `0x3313` | Learned Battery Capacity (L) | `Ah` | `read` / `holding`? | Low word | `U_DWORD_R` | `sensor` |  |  |
| 53  | `0x3314` | Learned Battery Capacity (H) |  | `read` / `holding`? | High word | `U_DWORD_R` | `sensor` |  |  |
| 54  | `0x3400` | Cells | Pcs | `read` / `holding`? | Cell quantity of battery pack | `U_WORD` | `sensor` |  |  |
| 55  | `0x3401` | Battery Pack Voltage | `V` | `read` / `holding`? | Lithium battery voltage | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 56  | `0x3402` | Battery Pack Main Circuit Current | `A` | `read` / `holding`? | Lithium battery total current, positive charging, negative discharging | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 57  | `0x3403` | Battery Pack Power (L) | `W` | `read` / `holding`? | Battery pack power low word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 58  | `0x3404` | Battery Pack Power (H) |  | `read` / `holding`? | Battery pack power high word | `U_DWORD_R` | `sensor` | `multiply: 0.01` | |
| 59  | `0x3405` | Battery Pack Full Charge Capacity | `Ah` | `read` / `holding`? | Capacity when battery is fully charged | `U_WORD` | `sensor` |  |  |
| 60  | `0x3406` | Battery Pack Remaining Capacity Percentage | `%` | `read` / `holding`? | Battery pack remaining capacity percentage | `U_WORD` | `sensor` |  |  |
| 61  | `0x3407` | Battery Pack Remaining Operating Duration | `min` | `read` / `holding`? | Remaining operating duration, minutes | `U_WORD` | `sensor` |  |  |
| 62  | `0x3408` | Maximum Cell Temperature of Battery Pack | `°C` | `read` / `holding`? | Highest cell temperature of battery pack | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 63  | `0x3409` | Minimum Cell Temperature of Battery Pack | `°C` | `read` / `holding`? | Lowest cell temperature of battery pack | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 64  | `0x340A` | Equalization Charging Temperature | `°C` | `read` / `holding`? | Battery pack equalization temperature | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 65  | `0x340B` | Ambient Temperature | `°C` | `read` / `holding`? | Battery pack ambient temperature | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 66  | `0x340C` | MOSFET Temperature | `°C` | `read` / `holding`? | Battery pack MOSFET temperature | `S_WORD` | `sensor` | `multiply: 0.01` | |
| 67  | `0x340D` | Cycles |  | `read` / `holding`? | Current charged/discharged cycles of battery pack | `U_WORD` | `sensor` |  |  |
| 68  | `0x340E` | Equalization Charging Status |  | `read` / `holding`? | `0` Equalization OFF; `1` Equalization ON | `U_WORD` | `sensor` |  |  |
| 69  | `0x340F` | Battery Pack Voltage Status |  | `read` / `holding`? | `0` Normal; `1` undervoltage alarm; `2` overvoltage alarm; `0xF1` undervoltage protection; 0xF2 overvoltage protection | `U_WORD` | `sensor` |  |  |
| 70  | `0x3410` | Current Status |  | `read` / `holding`? | `0` Normal; `1` overdischarge alarm; `2` overcharge alarm; `0xF1` overdischarge protection; `0xF2` overcharge protection | `U_WORD` | `sensor` |  |  |
| 71  | `0x3411` | MOSFET Status |  | `read` / `holding`? | `D0` Charging MOSFET; `D1` Discharging MOSFET | `U_WORD` | `sensor` |  | 1-bit  |
| 72  | `0x3412` | Cells Temperature Status |  | `read` / `holding`? | `0` Normal; `1` low temperature alarm; `2` high temperature alarm; `0xF0` NTC fault; `0xF1` low temperature protection; `0xF2` high temperature protection | `U_WORD` | `sensor` |  |  |
| 73  | `0x3413` | Equalization Charging Temperature Status |  | `read` / `holding`? |  | `U_WORD` | `sensor` |  |  |
| 74  | `0x3414` | Ambient Temperature Status |  | `read` / `holding`? |  | `U_WORD` | `sensor` |  |  |
| 75  | `0x3415` | MOSFET Temperature Status |  | `read` / `holding`? |  | `U_WORD` | `sensor` |  |  |
| 76  | `0x3416` | Cell Status |  | `read` / `holding`? | `0` cell normal; `1` undervoltage alarm; `2` overvoltage alarm; `0xF0` cell test; `0xF1` undervoltage protection; `0xF2` overvoltage protection | `U_WORD` | `sensor` |  |  |
| 77  | `0x3417` | Battery Protocol |  | `read` / `holding`? | Refer to BMS protocol sheet of lithium battery manufacturer | `U_WORD` | `sensor` |  |  |
| 78  | `0x3418` | Battery Status |  | `read` / `holding`? | `D0` charging protection; `D1` discharging protection; `D3` other protections; `D4` charging overtemperature; `D5` discharging overtemperature; `D12` full charge request; `D13` forced charging; `D14` discharging enable/disable; `D15` charging enable/disable | `U_WORD` | `sensor` |  | 1-bit  |
| 79  | `0x3419` | Pack Status |  | `read` / `holding`? | `0` Standard protocol; `1` High current protocol | `U_WORD` | `sensor` |  |  |
| 80  | `0x341A` | Pack Voltage | `V` | `read` / `holding`? | Batteries voltage, valid range `0`-`6500` V | `U_WORD` | `sensor` | `multiply: 0.1` |  |
| 81  | `0x341B` | Pack Current | `A` | `read` / `holding`? | Lithium battery total current, positive charging, negative discharging, range `-3276` A to `+3276` A | `S_WORD` | `sensor` | `multiply: 0.1` | |
| 82  | `0x341C` | Pack Undervoltage Protection | `V` | `read` / `holding`? | Controller disconnects load output when terminal voltage drops to set value | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 83  | `0x341D` | Pack Overvoltage Alarm | `V` | `read` / `holding`? | Highest full charge voltage; controller uses charging limit voltage as highest target charging voltage | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 84  | `0x341E` | Charging Current Limit | `A` | `read` / `holding`? | Battery pack adjusts maximum charging current limit in real time | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 85  | `0x341F` | Discharging Current Limit | `A` | `read` / `holding`? | Battery pack adjusts maximum discharging current limit in real time | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 86  | `0x3420` | Batteries Undervoltage Protection | `V` | `read` / `holding`? | Controller disconnects load output when battery terminal voltage drops to set value | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 87  | `0x3421` | Batteries Overvoltage Alarm | `V` | `read` / `holding`? | Highest full charge voltage; used as highest target charging voltage | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 88  | `0x3422` | Batteries Charging Current Protection | `A` | `read` / `holding`? | Battery pack adjusts maximum charging current limit in real time | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 89  | `0x3423` | Batteries Discharging Current Protection | `A` | `read` / `holding`? | Battery pack adjusts maximum discharging current limit in real time | `U_WORD` | `sensor` | `multiply: 0.01` | |
| 90  | `0x9000` | Battery Type |  | `holding` | `0x0001` AGM; `0x0002` GEL; `0x0003` FLD; `0x0004` LFP4S; `0x0005` LFP8S; `0x0006` LFP15S; `0x0007` LFP16S; `0x0008` LNCM3S; `0x0009` LNCM6S; `0x000A` LNCM7S; `0x000B` LNCM13S; `0x000C` LNCM14S; `0x0000` User | `U_WORD` | `number` |  | User-defined range `0`-`12`, default `1` |
| 91  | `0x9001` | Battery Capacity | `Ah` | `holding` | Nominal capacity of battery/batteries | `U_WORD` | `number` |  | Range `1`-`4000`, default `100` |
| 92  | `0x9002` | Temperature Compensation Coefficient | mV/deg C/2V | `holding` | Calculation parameter for charging and low voltage disconnect voltage | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `0`-`900`, default 300 |
| 93  | `0x9003` | Temperature Unit | C/F | `holding` | `1` - C; `0` - F; | `U_WORD` | `number` |  | Default `1` |
| 94  | `0x9004` | Screen Backlight Time | `sec` | `holding` | LCD backlight off delay; 0 always off, 100 always on | `U_WORD` | `number` |  | Range `0`-`100`, default 0 |
| 95  | `0x9005` | Screen Cycle Time | `sec` | `holding` | Display parameter automatic page turning cycle; `0 `fixed display | `U_WORD` | `number` |  | Range `0`-`100`, default `0` |
| 96  | `0x9006` | Rated Voltage Level |  | `holding` | `0` Auto; `1` 12V; `2` 24V; `3` 36V; `4` 48V; | `S_WORD` | `number` |  | Range `0`-`4`, default `0` |
| 97  | `0x9007` | Overvoltage Disconnect Voltage | `V` | `holding` | Charging shuts down if measured battery voltage exceeds this value | `U_WORD` | `number` / `sensor` |  `multiply: 0.01`| Range `900`-`1700` |
| 98  | `0x9008` | Charging Limit Voltage | `V` | `holding` | Highest full charge voltage target limit | `U_WORD` | `number`/ `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 99  | `0x9009` | Overvoltage Recovery Voltage | `V` | `holding` | System resumes discharging and charging when actual battery voltage is lower | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 100 | `0x900A` | Equalization Charging Voltage | `V` | `holding` | Charging target voltage in equalization mode | `S_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 101  | `0x900B` | Bulk Charging Voltage | `V` | `holding` | Bulk charging constant-voltage/current-limiting target | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 102  | `0x900C` | Float Charging Voltage | `V` | `holding` | Float charging maintained target voltage | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 103  | `0x900D` | Bulk Recovery Voltage | `V` | `holding` | Switches to bulk charging after voltage below threshold for at least 1 minute | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` |  |
| 104  | `0x900E` | Low Voltage Recovery Voltage | `V` | `holding` | Clears low voltage disconnection and resumes load output | `S_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 105  | `0x900F` | Undervoltage Alarm Recovery Voltage | `V` | `holding` | Clears undervoltage alarm | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 106  | `0x9010` | Undervoltage Alarm Voltage | `V` | `holding` | Indicates battery level is low and close to low voltage disconnect voltage | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 107  | `0x9011` | Low Voltage Disconnect Voltage | `V` | `holding` | Disconnects load output to prevent overdischarge | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 108  | `0x9012` | Discharging Limit Voltage | `V` | `holding` | Lowest discharging voltage under any circumstances | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `900`-`1700` |
| 109  | `0x9013` | Maximum Charging Current | `A` | `holding` | Charging current limit value | `U_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `100`-`10000`; default model-specific |
| 110  | `0x9014` | Equalization Charging Time | `min`| `holding` | Cumulative minutes maintained above equalization voltage | `U_WORD` | `number` |  | Range `0`-`120`, default `120` |
| 111  | `0x9015` | Bulk Charging Time | `min`| `holding` | Cumulative minutes maintained above bulk voltage | `U_WORD` | `number` |  | Range `0`-`120`, default `120` |
| 112  | `0x9016` | Lithium Battery Protection |  | `holding` | `3` enable lithium battery temperature protection; `4` disable | `U_WORD` | `number` |  | Local setting restrictions for lithium/user battery type |
| 113  | `0x9017` | Low Temperature Charging Limit | `°C` | `holding` | Charging off/disabled when measured temperature below this parameter | `S_WORD` | `number` / `sensor` |  `multiply: 0.01` | Range `-2500` to `1000` |
| 114  | `0x9019` | Real-time Clock |  | `holding` | `D7`-`D0` second; `D15`-`D8` minute | `U_WORD` | `number` |  |  |
| 115  | `0x901A` | Real-time Clock |  | `holding` | `D7`-`D0` hour; `D15`-`D8` day | `U_WORD` | `number` |  |  |
| 116  | `0x901B` | Real-time Clock |  | `holding` | `D7`-`D0` month; `D15`-`D8` year | `U_WORD` | `number` |  |  |
| 117  | `0x901C` | Battery Maximum Temperature Limit | `°C` | `holding` | Alarm, charging/discharging stopped if battery surface temperature is higher | `U_WORD` | `number` |  `multiply: 0.01` | Range `4000`-`10000`, default `6500` |
| 118  | `0x901D` | Battery Minimum Temperature Limit | `°C` | `holding` | Alarm if battery surface temperature is lower | `S_WORD` | `number` |  `multiply: 0.01` | Range `0` to `-6000` |
| 119  | `0x901E` | Equipment Maximum Temperature Limit | `°C` | `holding` | Alarm and charging/discharging stopped when internal temperature is higher | `U_WORD` | `number` |  `multiply: 0.01` | Range `6500`-`10000` |
| 120  | `0x901F` | Equipment Maximum Temperature Limit Recovery | `°C` | `holding` | Equipment resumes normal operation below this recovery temperature | `U_WORD` | `number` |  `multiply: 0.01` | Range `5500`-`10000` |
| 121  | `0x9020` | Power Module Maximum Temperature Limit | `°C` | `holding` | Alarm and charging/discharging stopped when power module surface temperature is higher | `U_WORD` | `number` |  `multiply: 0.01` | Range `6500`-`10000` |
| 122  | `0x9021` | Power Module Maximum Temperature Limit Recovery | `°C` | `holding` | Power module resumes normal operation below this recovery temperature | `U_WORD` | `number` |  `multiply: 0.01` | Range `5500`-`10000` |
| 123  | `0x9038` | Charging and Discharging Mode |  | `holding` | `0`-`1` | `U_WORD` | `number` |  | Default `0` |
| 124  | `0x9039` | Full Charge Protection SOC | `%` | `holding` | Full charge protection SOC | `U_WORD` | `number` |  | Range `1`-`100`, default `99` |
| 125  | `0x903A` | Full Charge Protection Recovery SOC | `%` | `holding` | Full charge protection recovery SOC | `U_WORD` | `number` |  | Range `1`-`100`, default `95` |
| 126  | `0x903C` | Low Battery Alarm Recovery SOC | `%` | `holding` | Low battery alarm recovery SOC | `U_WORD` | `number` |  | Range `1`-`100`, default `10` |
| 127  | `0x903D` | Low Battery Alarm SOC | `%` | `holding` | Low battery alarm SOC | `U_WORD` | `number` |  | Range `1`-`100`, default `8` |
| 128  | `0x903F` | Data Record Period | `min`| `holding` | Record interval of operating status | `U_WORD` | `number` |  | Range `10`-`120`, default `10` |
| 129  | `0x9040` | BMS Protocol |  | `holding` | Lithium battery BMS manufacturer protocol number | `U_WORD` | `number` |  | Range `1`-`230` |
| 130  | `0x9041` | Use BMS Settings |  | `holding` | `0`Disable; `1` Enable. Uses valid BMS parameters for charging/discharging control | `U_WORD` | `number` |  |  |
| 131  | `0x9042` | PV Connection Mode |  | `holding` | `0` Independent; `1` Centralize | `U_WORD` | `number` |  |  |
| 132  | `0x9043` | Simulate BMS Mode |  | `holding` | `1` enable simulated BMS terminal current limiting; `0` disable | `U_WORD` | `number` |  | MAP table queried only after enabled |
| 133  | `0x9045` | Address |  | `holding` | Device address | `U_WORD` | `number` |  | Range `1`-`100`, default `1` |
| 134  | `0x9046` | Baudrate |  | `holding` | `1152`, `96`, `24` | `U_WORD` | `number` / `sensor` |  `multiply: 100` | Default `1152`; restart required |
| 135  | `0x9047` | Parallel Battery Maximum Charging Current | `A` | `holding` | Parallel battery max charging current | `U_WORD` | `number` |  | Range `100`-`1200` |
| 136  | `0x9049` | PV Restart Charging Period | `min`| `holding` | PV restart charging period | `U_WORD` | `number` |  | Range `0`-`60`, default 10 |
| 137  | `0x904A` | Com Port Enable |  | `holding` | `1` Normal; `0` OFF | `U_WORD` | `number` |  | External communication off when no charging/discharging; default `1` |
| 138  | `0x904B` | Manual Equalization Charging |  | `holding` | `0` Normal; `1` trigger equalization charging once | `U_WORD` | `number` / `switch` |  | Default `0` |
| 139  | `0x0000` | Charging Switch |  | `coil` | `1` Charging ON; `0` Charging OFF | bool | `number` / `switch` |  |  |
| 140  | `0x0007` | Factory Reset |  | `coil` | `1` restore factory defaults; `0` no | bool | `number` / `switch` |  |  |
| 141  | `0x0008` | Reset Energy Statistics |  | `coil` | `1` clear statistics in equipment | bool | `number` / `switch`|  | Root permission required |
| 142  | `0x0009` | Clear Fault |  | `coil` | `1` clear equipment internal fault | bool | `number`/ `switch` |  |  |
