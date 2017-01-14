# EA-DOGM132-Driver
Driver for EA DOGM132 display series, written in C. Tested with EA DOGM132W-5 display and STM32F072RBT6 microcontroller.

## Example on how to use the library.

```c
_EA_DOGM132_Display LCD;

void Init_LCD(){
    uint8_t * data[536]; //varibale for the image buffer 132 columns * 4 pages;
    LCD.Configuration.SegmentDriverDirection = EA_DOGM132_CONF_ADC_SEG_REVERSE;
    LCD.Configuration.COMMode = EA_DOGM132_CONF_COM_NORMAL;
    LCD.Configuration.LCDBias = EA_DOGM132_CONF_BIAS_1_9;
    LCD.Configuration.BoosterCircuit = EA_DOGM132_CONF_BOOSTER_CIRCUIT_ON;
    LCD.Configuration.VoltageRegulatorCircuit = EA_DOGM132_CONF_VOLTAGE_REGULATOR_CIRCUIT_ON;
    LCD.Configuration.VoltageFollowerCircuit = EA_DOGM132_CONF_VOLTAGE_FOLLOWER_CIRCUIT_ON;
    LCD.Configuration.BoosterRatio = EA_DOGM132_CONF_BOOST_2X_3X_4X;
    LCD.Configuration.VOUTRegulator = 0b11;
    LCD.Configuration.ElectronicVolume = 0b00011111;
    LCD.Configuration.StaticIndicator = EA_DOGM132_CONF_STATIC_INDICATOR_OFF;
    LCD.Configuration.StaticIndicatorRegister = _EA_DOGM132_CONF_STATIC_INDICATOR_VALUE_OFF;
    LCD.Configuration.Invert = EA_DOGM132_CONF_INVERT_NORMAL;

    // Provide the pointers to the functions that allow to 
    // pull up and down pins A0 and RESET and send data trough SPI.
    LCD.Pull_A0_High = &LCD_Pull_A0_High; 
    LCD.Pull_A0_Low = &LCD_Pull_A0_Low;
    LCD.Pull_Reset_High = &LCD_Pull_Reset_High;
    LCD.Pull_Reset_Low = &LCD_Pull_Reset_Low;
    LCD.Wait_mS = &Wait_mS;
    LCD.SendData = &SPI_Send_Bytes;

    EA_DOGM132_Hardware_Reset(&LCD);
    EA_DOGM132_Init(&LCD);
    EA_DOGM132_Power(&LCD, EA_DOGM132_CONF_POWER_ON);
    

}

int main(void)
{
    Init_LCD();
    
    //Updates screen with the data from variable data. Data is going to be random.
    EA_DOGM132_UpdateScreen(&LCD, &data);
    
    while(1){}
}
```
