#pragma once

#include "esphome/components/modbus_controller/modbus_controller.h"
#include "esphome/components/modbus_controller/switch/modbus_switch.h"

#include <vector>

namespace esphome {
namespace R4D3B16 {


      //TODO: Define minimal ModbusDevice
//      class R4D3B16_ModbusDevice : public modbus::ModbusDevice  {
//        public:
//        uint16_t getDeviceAddress(){
//            return this->address_;
//        }
//    };*
        enum class R4D3B16Command : uint8_t {
            READ = 0x00,
            OPEN = 0x01,
            CLOSE = 0x02,
            TOGGLE = 0x03,
            LATCH = 0x04,
            MOMENTARY = 0x05,
            DELAY = 0x06,
            OPEN_ALL = 0x07,
            CLOSE_ALL = 0x08,
          };
    class R4D3B16Component {
        /*private:
        class SensorItemExtended : modbus_controller::ModbusSwitch{
            public:
                modbus_controller::ModbusController get_parent(){
                    return this->parent_;
                }
        };*/
        public:
        uint8_t modbus_address;
        uint16_t register_address;
        
        R4D3B16Component(uint8_t modbus_address, uint16_t register_address){
            this->modbus_address = modbus_address;
            this->register_address = register_address;
            ESP_LOGD("main","R4D3B16(uint8_t, uint16_t): [0x%d,0x%d]", this->modbus_address, this->register_address);
        }
        R4D3B16Component(){
            this->modbus_address = 0x00;
            this->register_address = 0x0000;
        }
        void generateModbusCommand(uint8_t modbus_address, uint16_t register_address, R4D3B16Command command,  std::vector<uint8_t> &payload, uint8_t delay = 0x00){
            ESP_LOGD("main","generateModbusCommand1: Modbus=0x%d Register=0x%d", modbus_address, register_address);
            if ((command == R4D3B16Command::OPEN_ALL || command == R4D3B16Command::CLOSE_ALL) && register_address != 0x0000){
                ESP_LOGD("main","Invalid: R4D3B16Command is ALL and relay not 0");
                return;
            }
            if ((command != R4D3B16Command::OPEN_ALL && command != R4D3B16Command::CLOSE_ALL) && register_address == 0x0000){
                ESP_LOGD("main","Invalid: R4D3B16Command not ALL and relay 0");
                return;
            }
            
            if(command != R4D3B16Command::DELAY && delay != 0x00){
                
                ESP_LOGD("main","Delay not supported by command");
                delay = 0x00;
            }
            
            payload.push_back(modbus_address);
            if(command == R4D3B16Command::READ) {
                payload.push_back(0x03);
            } else { 
                payload.push_back(0x06);
            }
            payload.push_back((register_address >> 8));  // low byte address of the coil
            payload.push_back((register_address & 0xff));  // high byte address of the coil
            payload.push_back((uint8_t)command);
            payload.push_back(delay);
            return;
        }
        
        std::vector<uint8_t> generateModbusCommand(uint8_t modbus_address, uint16_t register_address, R4D3B16Command command, uint8_t delay = 0x00){
            std::vector<uint8_t> payload;
            generateModbusCommand(modbus_address, register_address, command, payload, delay);
            return payload;
        }
        
        void generateModbusCommand(R4D3B16Command command,  std::vector<uint8_t> &payload, uint8_t delay = 0x00){
        
            ESP_LOGD("main","generateModbusCommand(R4D3B16Command, std::vector<uint8_t>&, uint8_t): [0x%d,0x%d]", this->modbus_address, this->register_address);
            generateModbusCommand(this->modbus_address, this->register_address, command, payload, delay);
        }
        
        void logPayloadValues(std::vector<uint8_t> &payload){
            int i = 0;
            for (auto val : payload) {
                ESP_LOGI("","payload[%d]=0x%02X (%d)",i,payload[i],payload[i]);
                i++;
            }
        }
        bool open(std::vector<uint8_t> &payload, bool logPayload = false){
            ESP_LOGD("main","open: [0x%d,0x%d]", this->modbus_address, this->register_address);
            if(register_address == 0x0000){
                this->generateModbusCommand(R4D3B16Command::OPEN_ALL, payload);
            } else {
                this->generateModbusCommand(R4D3B16Command::OPEN, payload);
            }
            if(logPayload){
                logPayloadValues(payload);
            }
            return true;
        }
        
        bool close(std::vector<uint8_t> &payload, bool logPayload = false){
            if(register_address == 0x0000){
                generateModbusCommand(R4D3B16Command::CLOSE_ALL, payload);
            } else {
                generateModbusCommand(R4D3B16Command::CLOSE, payload);
            }
            if(logPayload){
                logPayloadValues(payload);
            }
            return false;
        }
        
    };
}  // namespace modbus_controller
}  // namespace esphome