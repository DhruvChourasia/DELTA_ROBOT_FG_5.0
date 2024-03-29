#ifndef DELTAROBOT_H
#define DELTAROBOT_H

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/

//Link lengths (mm)
#define L1 100
#define L2 150
#define L3 48

#define END_EFFECTOR_Z_OFFSET 0
#define SERVO_OFFSET_X 75
#define SERVO_OFFSET_Y 0
#define SERVO_OFFSET_Z (41.231 + END_EFFECTOR_Z_OFFSET)
#define SERVO_OFFSET_Z_INVERTED -293

#define SERVO_ANGLE_MIN 0.78539816339744830961566084581988f //45 degrees
#define SERVO_ANGLE_MAX 3.9269908169872415480783042290994f //225 degrees

#define MIN 'm'
#define MAX 'M'

//Pins the servos are connected to
#define SERVO_1_PIN 9
#define SERVO_2_PIN 10
#define SERVO_3_PIN 11
#define SERVO_4_PIN 6

//Analog input to read the battery voltage from
#define BATTERY_PIN A0

//Servo microsecond pulse limits
#define SERVO_1_MIN 520//TODO: pulse limits will need to be calibrated for your specific servos
#define SERVO_1_MAX 2480
#define SERVO_2_MIN 560
#define SERVO_2_MAX 2520
#define SERVO_3_MIN 560
#define SERVO_3_MAX 2500
#define SERVO_4_MIN 540
#define SERVO_4_MAX 2400

#define MAX_STRING_LENGTH 8 //Maxium number of chars that can be received with a command

//Byte commands
#define COMMAND_CARTESIAN 1
#define COMMAND_ABSOLUTE_CARTESIAN 2
#define COMMAND_GRIPPER 3
#define COMMAND_ABSOLUTE_CARTESIAN_LINEAR 4
#define COMMAND_SET_PROGRAM_ARRAY 5
#define COMMAND_REQUEST_READY_FLAG 6

//String commands
#define COMMAND_JOG_X 'x'
#define COMMAND_JOG_Y 'y'
#define COMMAND_JOG_Z 'z'
#define COMMAND_GRIPPER_ASCII 'g'
#define COMMAND_STATUS 's' 
#define COMMAND_REPORT_COMMANDS 'r'
#define COMMAND_ADD_POSITION 'p'
#define COMMAND_SET_STEP_DELAY 'd'
#define COMMAND_SET_STEP_INCREMENT 'i'
#define COMMAND_CLEAR_ARRAY 'c'
#define COMMAND_EXECUTE 'e'
#define COMMAND_EXECUTE_JOINT 'j'
#define COMMAND_EXECUTE_TIME 't'
#define COMMAND_SET_US_INCREMENT_LINEAR 'u'
#define COMMAND_SET_US_INCREMENT_JOINT 'U'
#define COMMAND_STEP_FORWARD '>'
#define COMMAND_STEP_BACKWARD '<'
#define COMMAND_JUMP_TO_START '['
#define COMMAND_JUMP_TO_END ']'
#define COMMAND_EDIT_ARRAY 'P'
#define COMMAND_ADD_DELAY 'D'
#define COMMAND_MOVE_HOME 'h'
#define COMMAND_PRINT_FILE 'f'
#define COMMAND_PING_PONG 'o'
#define COMMAND_SERVO_CALIBRATION 'C'
#define COMMAND_SET_SERVO 'S'

//EEPROM commands
#define COMMAND_SET_LINK_2 'L'
#define COMMAND_SET_END_EFFECTOR_TYPE 'E'
#define COMMAND_SET_AXIS_DIRECTION 'A'
#define COMMAND_SET_HOME_X 'X'
#define COMMAND_SET_HOME_Y 'Y'
#define COMMAND_SET_HOME_Z 'Z'
#define COMMAND_SET_HOME_GRIPPER 'G'
#define COMMAND_SET_GRIPPER_MIN_MAX 'M'

//EEPROM addresses for the delta robots configuration
#define EEPROM_ADDRESS_LINK_2 0
#define EEPROM_ADDRESS_END_EFFECTOR_TYPE 1
#define EEPROM_ADDRESS_AXIS_DIRECTION 2
#define EEPROM_ADDRESS_Z_OFFSET 3
#define EEPROM_ADDRESS_HOME_X 7
#define EEPROM_ADDRESS_HOME_Y 11
#define EEPROM_ADDRESS_HOME_Z 15
#define EEPROM_ADDRESS_HOME_GRIPPER 19
#define EEPROM_ADDRESS_GRIPPER_ROTATION_MIN 21
#define EEPROM_ADDRESS_GRIPPER_ROTATION_MAX 23
#define EEPROM_ADDRESS_GRIPPER_CLAW_MIN 25
#define EEPROM_ADDRESS_GRIPPER_CLAW_MAX 27
#define EEPROM_ADDRESS_GRIPPER_VACUUM_MIN 29
#define EEPROM_ADDRESS_GRIPPER_VACUUM_MAX 31

#define NONE 0
#define CONTINUOUS_ROTATION 1
#define CLAW_GRIPPER 2
#define VACUUM_GRIPPER 3
#define ELECTROMAGNET 4

#define INVERTED -1

#define ARRAY_LENGTH 80 //Maximum number of positions to store

#define READY_FLAG F("##")

#define FIRMWARE_VERSION F("2.5.2")

struct Coordinate_f {
    float x;
    float y;
    float z;
};

struct Program_element {
    float x = 0;
    float y = 0;
    float z = 0;
    char gripper = 0;
    int delay_ms = 0;
};

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/

float boundFloat(float, float, float);
void attach_servos(void);
bool inverse_kinematics_1(float, float, float);
bool inverse_kinematics_2(float, float, float);
bool inverse_kinematics_3(float, float, float);
bool inverse_kinematics(float, float, float);
void linear_move(float, float, float, float, int);
void joint_move(float, float, float, int, int);
void move_servos(void);
void gripper_servo(char);
float get_battery_level_percentage(void);
float get_battery_level_voltage(void);
void report_status(void);
void serialFlush(void);
void gripper_open_close(bool);
void report_commands(void);
void detach_servos(void);
int add_position(void);
void clear_array(void);
void execute_moves(int);
void set_step_increment(float);
void set_step_delay_linear(int);
void set_step_delay_joint(int);
int get_gripper_rotation(void);
float get_serial_float(void);
int get_serial_int(void);
void execute_moves_joint(int);
void set_step_pulses(int);
void set_link_2_length(int);
void set_end_effector_type(int);
void set_axis_direction(int);
void set_z_offset(float);
void set_home_x(float);
void set_home_y(float);
void set_home_z(float);
void set_home_gripper(int);
void set_gripper_min_max(char, char, int);
void set_eeprom_values(void);
void print_eeprom(void);
void print_moves_array(void);
void print_moves_array_for_file(void);
void goto_moves_array_index(int);
void edit_moves_array_index(int);
void add_delay(int, int);
int get_moves_array_index(void);
void increment_moves_array_index(void);
void decrement_moves_array_index(void);
void position_gripper_servo(char);
void move_home(void);
void goto_moves_array_start(void);
void goto_moves_array_end(void);
float get_step_increment(void);
float get_step_delay_linear(void);
void ping_pong(void);
void send_ready_flag(void);
int set_program_array(void);
void servo_calibration_test(int);
void set_servos_pulse(int, int);
void execute_moves_time(unsigned long);

/*------------------------------------------------------------------------------------------------------------------------------------------------------*/

#endif
