/****************************************************************
 *  Source File: EA_DOGM132_driver.c
 *  Description: Driver for EA DOGM132 series displays
 *  Author: Andrejs Bondarevs
 *  E-mail: info@beastdevices.com
 *  Created: 2016-12-21
 ****************************************************************/

#include "stdint.h"
#include "EA_DOGM132_driver.h"

void EA_DOGM132_Send_Byte(_EA_DOGM132_Display  * display, uint8_t byte)
{
    _EA_DOGM132_Data data;
    data.data = &byte;
    data.length = 1;
    display->SendData(&data);
}

void EA_DOGM132_Power(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Power mode)
{
    display->Pull_A0_Low();
    if (mode == EA_DOGM132_CONF_POWER_ON)
    {
        EA_DOGM132_Send_Byte(display, EA_DOGM132_CMD_ON);
    }
    else if (mode == EA_DOGM132_CONF_POWER_OFF)
    {
        EA_DOGM132_Send_Byte(display, EA_DOGM132_CMD_OFF);
    }
}

void EA_DOGM132_Fill_Display(_EA_DOGM132_Display  * display)
{
    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, EA_DOGM132_CMD_ALL_PIXELS_ON);
}

void EA_DOGM132_Clear_Display(_EA_DOGM132_Display  * display)
{
    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, EA_DOGM132_CMD_ALL_PIXELS_OFF);
}

void EA_DOGM132_Internal_Reset(_EA_DOGM132_Display  * display)
{
    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, EA_DOGM132_CMD_RESET);
}

void EA_DOGM132_Configure_SegmentDriverDirection(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Segment_Driver_Direction SegmentDriverDirection)
{
    uint8_t cmd;

    if (SegmentDriverDirection == EA_DOGM132_CONF_ADC_SEG_NORMAL)
        cmd = EA_DOGM132_CMD_ADC_SELECT_NORMAL;
    else if (SegmentDriverDirection == EA_DOGM132_CONF_ADC_SEG_REVERSE)
        cmd = EA_DOGM132_CMD_ADC_SELECT_REVERSE;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_COMMode(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_COM_Mode COMMode)
{
    uint8_t cmd;
    if (COMMode == EA_DOGM132_CONF_COM_NORMAL)
        cmd = EA_DOGM132_CMD_COM_MODE_NORMAL;
    else if (COMMode == EA_DOGM132_CONF_COM_REVERSE)
        cmd = EA_DOGM132_CMD_COM_MODE_REVERSE;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_Invert(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Invert Invert)
{
    uint8_t cmd;
    if (Invert == EA_DOGM132_CONF_INVERT_NORMAL)
        cmd = EA_DOGM132_CMD_DISPLAY_NORMAL;
    else if (Invert == EA_DOGM132_CONF_INVERT_REVERSE)
        cmd = EA_DOGM132_CMD_DISPLAY_REVERSE;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_LCDBias(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_LCD_Bias LCDBias)
{
    uint8_t cmd;
    if (LCDBias == EA_DOGM132_CONF_BIAS_1_7)
        cmd= EA_DOGM132_CMD_LCD_BIAS_1_7;
    else if (LCDBias == EA_DOGM132_CONF_BIAS_1_9)
        cmd = EA_DOGM132_CMD_LCD_BIAS_1_9;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_PowerControl(_EA_DOGM132_Display  * display,
                                       _EA_DOGM132_Conf_Booster_Circuit BoosterCircuit,
                                       _EA_DOGM132_Conf_Voltage_Regulator_Circuit VoltageRegulatorCircuit,
                                       _EA_DOGM132_Conf_Voltage_Follower_Curcuit VoltageFollowerCircuit)
{
    uint8_t cmd = EA_DOGM132_CMD_POWER_CONTROL;
    if (BoosterCircuit == EA_DOGM132_CONF_BOOSTER_CIRCUIT_ON)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_BOOSTER_ON;
    else if (BoosterCircuit == EA_DOGM132_CONF_BOOSTER_CIRCUIT_OFF)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_BOOSTER_OFF;

    if (VoltageRegulatorCircuit == EA_DOGM132_CONF_VOLTAGE_REGULATOR_CIRCUIT_ON)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_REGULATOR_ON;
    else if (VoltageRegulatorCircuit == EA_DOGM132_CONF_VOLTAGE_REGULATOR_CIRCUIT_OFF)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_REGULATOR_OFF;

    if (VoltageFollowerCircuit == EA_DOGM132_CONF_VOLTAGE_FOLLOWER_CIRCUIT_ON)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_FOLLOWER_ON;
    else if (VoltageFollowerCircuit == EA_DOGM132_CONF_VOLTAGE_FOLLOWER_CIRCUIT_OFF)
        cmd = cmd | EA_DOGM132_CMD_POWER_CONTROL_VOLTAGE_FOLLOWER_OFF;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_BoosterRatio(_EA_DOGM132_Display  * display, _EA_DOGM132_Conf_Booster_Ratio BoosterRatio)
{
    uint8_t cmd[2];
    _EA_DOGM132_Data data;

    cmd[0] = EA_DOGM132_CMD_BOOSTER_RATIO_SET;
    if (BoosterRatio == EA_DOGM132_CONF_BOOST_2X_3X_4X)
        cmd[1] = EA_DOGM132_CMD_BOOSTER_RATIO_SET_2X_3X_4X;
    else if (BoosterRatio == EA_DOGM132_CONF_BOOST_5X)
        cmd[1] = EA_DOGM132_CMD_BOOSTER_RATIO_SET_5X;
    else if (BoosterRatio == EA_DOGM132_CONF_BOOST_6X)
        cmd[1] = EA_DOGM132_CMD_BOOSTER_RATIO_SET_6X;

    data.length = 2;
    data.data = &cmd;

    display->Pull_A0_Low();
    display->SendData(&data);
}

void EA_DOGM132_Configure_VoltageResistorRatio(_EA_DOGM132_Display  * display,  uint8_t ResistorRatio)
{
    uint8_t cmd;
    if (ResistorRatio > EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MAX) ResistorRatio = EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MAX;
    if (ResistorRatio < EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MIN) ResistorRatio = EA_DOGM132_VOLTAGE_RESISTOR_RATIO_MIN;

    cmd = EA_DOGM132_CMD_VOLTAGE_RESISTOR_RATIO | ResistorRatio;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Configure_ElectronicVolume(_EA_DOGM132_Display * display, uint8_t ElectronicVolume)
{
    uint8_t cmd[2];
    _EA_DOGM132_Data data;

    cmd[0] = EA_DOGM132_CMD_ELECT_VOL_MODE_SET;

    if (ElectronicVolume > EA_DOGM132_ELECT_VOL_VAL_MAX) ElectronicVolume = EA_DOGM132_ELECT_VOL_VAL_MAX;
    if (ElectronicVolume < EA_DOGM132_ELECT_VOL_VAL_MIN) ElectronicVolume = EA_DOGM132_ELECT_VOL_VAL_MIN;

    cmd[1] = EA_DOGM132_CMD_ELECT_VOL_VAL_SET | ElectronicVolume;

    data.length = 2;
    data.data = &cmd;

    display->Pull_A0_Low();
    display->SendData(&data);
}

void EA_DOGM132_Configure_StaticIndicator(_EA_DOGM132_Display * display, _EA_DOGM132_Conf_Static_Indicator StaticIndicatorMode, uint8_t StaticIndicator)
{
    uint8_t cmd[2];
    _EA_DOGM132_Data data;

    if (StaticIndicatorMode == EA_DOGM132_CONF_STATIC_INDICATOR_ON)
    {
        cmd[0] = EA_DOGM132_CMD_STATIC_INDIC_ON;
        if (StaticIndicator == _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_OFF)
            cmd[1] = EA_DOGM132_CMD_STATIC_INDIC_VALUE_OFF;
        else if (StaticIndicator == _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_1_SECOND)
            cmd[1] = EA_DOGM132_CMD_STATIC_INDIC_VALUE_1_SEC;
        else if (StaticIndicator == _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_HALF_SECOND)
            cmd[1] = EA_DOGM132_CMD_STATIC_INDIC_VALUE_HALF_SEC;
        else if (StaticIndicator == _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_ON_CONSTANTLY)
            cmd[1] = EA_DOGM132_CMD_STATIC_INDIC_VALUE_CONST_ON;
    }
    else if (StaticIndicatorMode == EA_DOGM132_CONF_STATIC_INDICATOR_OFF)
    {
        cmd[0] = EA_DOGM132_CMD_STATIC_INDIC_OFF;
        cmd[1] = 0;
    }

    data.data = &cmd;
    data.length = 2;

    display->Pull_A0_Low();
    display->SendData(&data);
}

void EA_DOGM132_Display_Start_Line_Set(_EA_DOGM132_Display * display, uint8_t line_number)
{
    uint8_t cmd;
    if (line_number > EA_DOGM132_PAR_LINES) line_number = EA_DOGM132_PAR_LINES;
    cmd = EA_DOGM132_CMD_START_LINE_SET | line_number;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Page_Address_Set(_EA_DOGM132_Display * display, uint16_t page_number)
{
    uint8_t cmd;
    if (page_number > EA_DOGM132_PAR_PAGES) page_number = EA_DOGM132_PAR_PAGES;
    cmd = EA_DOGM132_CMD_PAGE_ADDR_SET | page_number;

    display->Pull_A0_Low();
    EA_DOGM132_Send_Byte(display, cmd);
}

void EA_DOGM132_Column_Address_Set(_EA_DOGM132_Display * display, uint16_t column_number)
{
    uint8_t cmd[2];
    _EA_DOGM132_Data data;
    if (column_number > EA_DOGM132_PAR_COL) column_number = EA_DOGM132_PAR_COL;
    cmd[0] = EA_DOGM132_CMD_COLUMN_SET_MSB | (column_number >> 4);
    cmd[1] = EA_DOGM132_CMD_COLUMN_SET_LSB | (column_number & 0b00001111);

    data.length = 2;
    data.data = &cmd;

    display->Pull_A0_Low();
    display->SendData(&data);
}

void EA_DOGM132_Hardware_Reset(_EA_DOGM132_Display * display)
{
    display->Pull_Reset_Low();
    display->Wait_mS(1);
    display->Pull_Reset_High();
    display->Wait_mS(1);
}

void EA_DOGM132_WriteDisplayData(_EA_DOGM132_Display * display, _EA_DOGM132_Data * Data)
{
    display->Pull_A0_High();
    display->SendData(Data);
    display->Pull_A0_Low();
}


void EA_DOGM132_UpdateScreen(_EA_DOGM132_Display * display, uint8_t * Image){
    _EA_DOGM132_Data data;

    for (int i = 0; i < EA_DOGM132_PAR_PAGES; i++){
        EA_DOGM132_Page_Address_Set(display, i);
        EA_DOGM132_Column_Address_Set(display, 0);
        data.data = Image + i*EA_DOGM132_PAR_COL;
        data.length = EA_DOGM132_PAR_COL;
        EA_DOGM132_WriteDisplayData(display, &data);
    }
}

void EA_DOGM132_Init(_EA_DOGM132_Display * display)
{
    EA_DOGM132_Display_Start_Line_Set(display, 0);

    EA_DOGM132_Configure_SegmentDriverDirection(display, display->Configuration.SegmentDriverDirection);

    EA_DOGM132_Configure_COMMode(display, display->Configuration.COMMode);

    EA_DOGM132_Configure_Invert(display, display->Configuration.Invert);

    EA_DOGM132_Configure_LCDBias(display, display->Configuration.LCDBias);

    EA_DOGM132_Configure_PowerControl(display, display->Configuration.BoosterCircuit, display->Configuration.VoltageRegulatorCircuit, display->Configuration.VoltageFollowerCircuit);

    EA_DOGM132_Configure_BoosterRatio(display, display->Configuration.BoosterRatio);

    EA_DOGM132_Configure_VoltageResistorRatio(display, display->Configuration.VOUTRegulator);

    EA_DOGM132_Configure_ElectronicVolume(display, display->Configuration.ElectronicVolume);

    EA_DOGM132_Configure_StaticIndicator(display, display->Configuration.StaticIndicator, display->Configuration.StaticIndicatorRegister);
}

