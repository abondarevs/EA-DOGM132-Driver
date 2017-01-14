/****************************************************************
 *  Source File: EA_DOGM132_driver.h
 *  Description: Driver for EA DOGM132 series displays
 *  Author: Andrejs Bondarevs
 *  E-mail: info@beastdevices.com
 *  Created: 2016-12-21
 ****************************************************************/


#define EA_DOGM132_CMD_ON                          0b10101111
#define EA_DOGM132_CMD_OFF                         0b10101110

#define EA_DOGM132_CMD_START_LINE_SET              0b01000000
#define EA_DOGM132_CMD_PAGE_ADDR_SET               0b10110000

#define EA_DOGM132_CMD_COLUMN_SET_MSB              0b00010000
#define EA_DOGM132_CMD_COLUMN_SET_LSB              0b00000000

#define EA_DOGM132_CMD_ADC_SELECT_NORMAL           0b10100000
#define EA_DOGM132_CMD_ADC_SELECT_REVERSE          0b10100001

#define EA_DOGM132_CMD_DISPLAY_NORMAL              0b10100110
#define EA_DOGM132_CMD_DISPLAY_REVERSE             0b10100111

#define EA_DOGM132_CMD_ALL_PIXELS_OFF              0b10100100
#define EA_DOGM132_CMD_ALL_PIXELS_ON               0b10100101

#define EA_DOGM132_CMD_LCD_BIAS_1_9                0b10100010
#define EA_DOGM132_CMD_LCD_BIAS_1_7                0b10100011

#define EA_DOGM132_CMD_RESET                       0b11100010

#define EA_DOGM132_CMD_COM_MODE_NORMAL             0b11000000
#define EA_DOGM132_CMD_COM_MODE_REVERSE            0b11001000

#define EA_DOGM132_CMD_VOLTAGE_RESISTOR_RATIO      0b00100000
#define EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MIN      0b00000000
#define EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MAX      0b00000111

#define EA_DOGM132_CMD_ELECT_VOL_MODE_SET          0b10000001
#define EA_DOGM132_CMD_ELECT_VOL_VAL_SET           0b00000000
#define EA_DOGM132_ELECT_VOL_VAL_MIN               0b00000000
#define EA_DOGM132_ELECT_VOL_VAL_MAX               0b00111111

#define EA_DOGM132_CMD_STATIC_INDIC_OFF            0b10101100
#define EA_DOGM132_CMD_STATIC_INDIC_ON             0b10101101
#define EA_DOGM132_CMD_STATIC_INDIC_VALUE_OFF      0b00000000
#define EA_DOGM132_CMD_STATIC_INDIC_VALUE_1_SEC    0b00000001
#define EA_DOGM132_CMD_STATIC_INDIC_VALUE_HALF_SEC 0b00000010
#define EA_DOGM132_CMD_STATIC_INDIC_VALUE_CONST_ON 0b00000011

#define EA_DOGM132_CMD_BOOSTER_RATIO_SET           0b11111000
#define EA_DOGM132_CMD_BOOSTER_RATIO_SET_2X_3X_4X  0b00000000
#define EA_DOGM132_CMD_BOOSTER_RATIO_SET_5X        0b00000001
#define EA_DOGM132_CMD_BOOSTER_RATIO_SET_6X        0b00000011

#define EA_DOGM132_CMD_POWER_CONTROL                        0b00101000
#define EA_DOGM132_CMD_POWER_CONTROL_BOOSTER_ON             0b00000100
#define EA_DOGM132_CMD_POWER_CONTROL_BOOSTER_OFF            0b00000000
#define EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_REGULATOR_ON   0b00000010
#define EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_REGULATOR_OFF  0b00000000
#define EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_FOLLOWER_ON    0b00000001
#define EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_FOLLOWER_OFF   0b00000000

#define EA_DOGM132_PAR_LINES    32
#define EA_DOGM132_PAR_COL      132
#define EA_DOGM132_PAR_PAGES    4

/****************************************************************
 *  Type definitions
 ****************************************************************/

typedef enum _EA_DOGM132_Conf_Power
{
    EA_DOGM132_CONF_POWER_ON,
    EA_DOGM132_CONF_POWER_OFF
} _EA_DOGM132_Conf_Power;

typedef enum _EA_DOGM132_Conf_Segment_Driver_Direction
{
    EA_DOGM132_CONF_ADC_SEG_NORMAL,
    EA_DOGM132_CONF_ADC_SEG_REVERSE
} _EA_DOGM132_Conf_Segment_Driver_Direction;

typedef enum _EA_DOGM132_Conf_Invert
{
    EA_DOGM132_CONF_INVERT_NORMAL,
    EA_DOGM132_CONF_INVERT_REVERSE
} _EA_DOGM132_Conf_Invert;

typedef enum _EA_DOGM132_Conf_LCD_Bias
{
    EA_DOGM132_CONF_BIAS_1_9,
    EA_DOGM132_CONF_BIAS_1_7
} _EA_DOGM132_Conf_LCD_Bias;

typedef enum _EA_DOGM132_Conf_COM_Mode
{
    EA_DOGM132_CONF_COM_NORMAL,
    EA_DOGM132_CONF_COM_REVERSE
} _EA_DOGM132_Conf_COM_Mode;

typedef enum _EA_DOGM132_Conf_Booster_Ratio
{
    EA_DOGM132_CONF_BOOST_2X_3X_4X,
    EA_DOGM132_CONF_BOOST_5X,
    EA_DOGM132_CONF_BOOST_6X
} _EA_DOGM132_Conf_Booster_Ratio;

typedef enum _EA_DOGM132_Conf_Static_Indicator
{
    EA_DOGM132_CONF_STATIC_INDICATOR_ON,
    EA_DOGM132_CONF_STATIC_INDICATOR_OFF
} _EA_DOGM132_Conf_Static_Indicator;

typedef enum _EA_DOGM132_Conf_Booster_Circuit
{
    EA_DOGM132_CONF_BOOSTER_CIRCUIT_ON,
    EA_DOGM132_CONF_BOOSTER_CIRCUIT_OFF
} _EA_DOGM132_Conf_Booster_Circuit;

typedef enum _EA_DOGM132_Conf_Voltage_Regulator_Circuit
{
    EA_DOGM132_CONF_VOLTAGE_REGULATOR_CIRCUIT_ON,
    EA_DOGM132_CONF_VOLTAGE_REGULATOR_CIRCUIT_OFF
} _EA_DOGM132_Conf_Voltage_Regulator_Circuit;

typedef enum _EA_DOGM132_Conf_Voltage_Follower_Curcuit
{
    EA_DOGM132_CONF_VOLTAGE_FOLLOWER_CIRCUIT_ON,
    EA_DOGM132_CONF_VOLTAGE_FOLLOWER_CIRCUIT_OFF
} _EA_DOGM132_Conf_Voltage_Follower_Curcuit;

typedef enum _EA_DOGM132_Conf_Static_Indicator_Value
{
    _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_OFF,
    _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_1_SECOND,
    _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_HALF_SECOND,
    _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_CONSTANTLY
} _EA_DOGM132_Conf_Static_Indicator_Value;

typedef struct
{
    uint8_t * data;
    uint16_t length;
} _EA_DOGM132_Data;

typedef struct
{
    _EA_DOGM132_Conf_Segment_Driver_Direction       SegmentDriverDirection;
    _EA_DOGM132_Conf_COM_Mode                       COMMode;
    _EA_DOGM132_Conf_Invert                         Invert;
    _EA_DOGM132_Conf_LCD_Bias                       LCDBias;
    _EA_DOGM132_Conf_Booster_Circuit                BoosterCircuit;
    _EA_DOGM132_Conf_Voltage_Regulator_Circuit      VoltageRegulatorCircuit;
    _EA_DOGM132_Conf_Voltage_Follower_Curcuit       VoltageFollowerCircuit;
    _EA_DOGM132_Conf_Booster_Ratio                  BoosterRatio;
    uint8_t                                         VOUTRegulator;
    uint8_t                                         ElectronicVolume;
    _EA_DOGM132_Conf_Static_Indicator               StaticIndicator;
    _EA_DOGM132_Conf_Static_Indicator_Value         StaticIndicatorRegister;
} _EA_DOGM132_Configuration;

typedef struct
{
  _EA_DOGM132_Configuration Configuration;
  void (*SendData)(_EA_DOGM132_Data*);
  void (*Pull_Reset_Low)();
  void (*Pull_Reset_High)();
  void (*Pull_A0_Low)();
  void (*Pull_A0_High)();
  void (*Wait_mS)(uint32_t);
} _EA_DOGM132_Display;


/****************************************************************
 *  Functions
 ****************************************************************/

void EA_DOGM132_Send_Byte(_EA_DOGM132_Display  * display, uint8_t byte);
void EA_DOGM132_Power(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Power mode);
void EA_DOGM132_Fill_Display(_EA_DOGM132_Display  * display);
void EA_DOGM132_Clear_Display(_EA_DOGM132_Display  * display);
void EA_DOGM132_Internal_Reset(_EA_DOGM132_Display  * display);
void EA_DOGM132_Configure_SegmentDriverDirection(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Segment_Driver_Direction SegmentDriverDirection);
void EA_DOGM132_Configure_COMMode(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_COM_Mode COMMode);
void EA_DOGM132_Configure_Invert(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Invert Invert);
void EA_DOGM132_Configure_LCDBias(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_LCD_Bias LCDBias);
void EA_DOGM132_Configure_PowerControl(_EA_DOGM132_Display  * display,
                                       _EA_DOGM132_Conf_Booster_Circuit BoosterCircuit,
                                       _EA_DOGM132_Conf_Voltage_Regulator_Circuit VoltageRegulatorCircuit,
                                       _EA_DOGM132_Conf_Voltage_Follower_Curcuit VoltageFollowerCircuit);
void EA_DOGM132_Configure_BoosterRatio(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Booster_Ratio BoosterRatio);
void EA_DOGM132_Configure_VoltageResistorRatio(_EA_DOGM132_Display  * display,  uint8_t ResistorRatio);
void EA_DOGM132_Configure_ElectronicVolume(_EA_DOGM132_Display * display, uint8_t ElectronicVolume);
void EA_DOGM132_Configure_StaticIndicator(_EA_DOGM132_Display * display, _EA_DOGM132_Conf_Static_Indicator StaticIndicatorMode, uint8_t StaticIndicator);
void EA_DOGM132_Display_Start_Line_Set(_EA_DOGM132_Display * display, uint8_t line_number);
void EA_DOGM132_Page_Address_Set(_EA_DOGM132_Display * display, uint16_t page_number);
void EA_DOGM132_Column_Address_Set(_EA_DOGM132_Display * display, uint16_t column_number);
void EA_DOGM132_Hardware_Reset(_EA_DOGM132_Display * display);
void EA_DOGM132_WriteDisplayData(_EA_DOGM132_Display * display, _EA_DOGM132_Data * Data);
void EA_DOGM132_UpdateScreen(_EA_DOGM132_Display * display, uint8_t * Image);
void EA_DOGM132_Init(_EA_DOGM132_Display * display);
