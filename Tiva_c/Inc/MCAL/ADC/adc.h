#ifndef ADC_H
#define ADC_H
#include "Inc/LIB/BIT_MATH.h"
#include "Inc/LIB/STD_TYPES.h"

#define ADC_BASE 0x40038000

#define ADC_BASE_deref  (*((volatile uint32 *)  0x40038000  ))

#define ADCn_BASE(ADCNUM)                  ((ADCNUM<<(uint16)12)+(0x40038000))

//#define ADC_GEN_REG(ADCNUM,OFFSET)         *((unsigned int *)(ADCn_BASE(ADCNUM) + OFFSET))
#define ADC_GEN_REG(ADCNUM,OFFSET)           (ADCn_BASE(ADCNUM)+ OFFSET)

#define HWREG_access(REG_ADD)   (*(volatile uint32*)(REG_ADD))

#define ADCACTSS_reg_offset     0x000
#define ADCRIS_reg_offset       0x004
#define ADCIM_reg_offset        0x008
#define ADCISC_reg_offset       0x00C
#define ADCOSTAT_reg_offset     0x010
#define ADCEMUX_reg_offset      0x014
#define ADCUSTAT_reg_offset     0x018
#define ADCTSSEL_reg_offset     0x01C
#define ADCSSPRI_reg_offset     0x020
#define ADCSSMUX0_reg_offset    0x040
#define ADCSSMUX1_reg_offset    0x060
#define ADCSSMUX2_reg_offset    0x080
#define ADCSSMUX3_reg_offset    0x0A0
#define ADCSSCTL0_reg_offset    0x044
#define ADCSSCTL1_reg_offset    0x064
#define ADCSSCTL2_reg_offset    0x084
#define ADCSSCTL3_reg_offset    0x0A4
#define ADCPSSI_reg_offset      0x028
#define ADCSSFIFO0_reg_offset   0x048
#define ADCSSFIFO1_reg_offset   0x068
#define ADCSSFIFO2_reg_offset   0x088
#define ADCSSFIFO3_reg_offset   0x0A8
#define ADCPSSI_reg_offset      0x028








//*****************************************************************************
//
// Values that can be passed to ADCSequenceConfigure as the ui32Trigger
// parameter.
//
//*****************************************************************************
#define ADC_TRIGGER_PROCESSOR   0x00000000  // Processor event
#define ADC_TRIGGER_COMP0       0x00000001  // Analog comparator 0 event
#define ADC_TRIGGER_COMP1       0x00000002  // Analog comparator 1 event
#define ADC_TRIGGER_COMP2       0x00000003  // Analog comparator 2 event
#define ADC_TRIGGER_EXTERNAL    0x00000004  // External event
#define ADC_TRIGGER_TIMER       0x00000005  // Timer event
#define ADC_TRIGGER_PWM0        0x00000006  // PWM0 event
#define ADC_TRIGGER_PWM1        0x00000007  // PWM1 event
#define ADC_TRIGGER_PWM2        0x00000008  // PWM2 event
#define ADC_TRIGGER_PWM3        0x00000009  // PWM3 event


//*****************************************************************************
//
// Values that can be passed to ADCSequenceStepConfigure as the ui32Config
// parameter.
//
//*****************************************************************************
#define ADC_CTL_TS              0x00000080  // Temperature sensor select
#define ADC_CTL_IE              0x00000040  // Interrupt enable
#define ADC_CTL_END             0x00000020  // Sequence end select
#define ADC_CTL_D               0x00000010  // Differential select
#define ADC_CTL_CH0             0x00000000  // Input channel 0
#define ADC_CTL_CH1             0x00000001  // Input channel 1
#define ADC_CTL_CH2             0x00000002  // Input channel 2
#define ADC_CTL_CH3             0x00000003  // Input channel 3
#define ADC_CTL_CH4             0x00000004  // Input channel 4
#define ADC_CTL_CH5             0x00000005  // Input channel 5
#define ADC_CTL_CH6             0x00000006  // Input channel 6
#define ADC_CTL_CH7             0x00000007  // Input channel 7
#define ADC_CTL_CH8             0x00000008  // Input channel 8
#define ADC_CTL_CH9             0x00000009  // Input channel 9
#define ADC_CTL_CH10            0x0000000A  // Input channel 10
#define ADC_CTL_CH11            0x0000000B  // Input channel 11
#define ADC_CTL_CH12            0x0000000C  // Input channel 12
#define ADC_CTL_CH13            0x0000000D  // Input channel 13
#define ADC_CTL_CH14            0x0000000E  // Input channel 14
#define ADC_CTL_CH15            0x0000000F  // Input channel 15
#define ADC_CTL_CH16            0x00000100  // Input channel 16
#define ADC_CTL_CH17            0x00000101  // Input channel 17
#define ADC_CTL_CH18            0x00000102  // Input channel 18
#define ADC_CTL_CH19            0x00000103  // Input channel 19
#define ADC_CTL_CH20            0x00000104  // Input channel 20
#define ADC_CTL_CH21            0x00000105  // Input channel 21
#define ADC_CTL_CH22            0x00000106  // Input channel 22
#define ADC_CTL_CH23            0x00000107  // Input channel 23

#define ADC_sequencer_0     0x00
#define ADC_sequencer_1     0x01
#define ADC_sequencer_2     0x02
#define ADC_sequencer_3     0x03

#define ADC0 0x00
#define ADC1 0x01

typedef struct adc
{
    unsigned char ADCn : 1;
    unsigned char ADC_TRIGGER;
    unsigned short ADC_Channel;
    unsigned char sequencer : 2;

}adc_config_t;



void ADC_Init(const adc_config_t*const PTR);
unsigned int ADC_Read_Data(const adc_config_t* PTR);

#endif //ADC_H
