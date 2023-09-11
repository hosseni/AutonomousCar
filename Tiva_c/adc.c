
#include "Inc/LIB/BIT_MATH.h"
#include "Inc/LIB/STD_TYPES.h"
#include "hw_gpio.h"
#include "Inc/MCAL/ADC/adc.h"

//#define NULL (unsigned int*)0


void ADC_Init(const adc_config_t*const PTR)
{
    if(PTR != NULL)
    {
        /*Determine Base address for the adc module*/
        unsigned int base_add = ADCn_BASE(PTR->ADCn);

        /* disable sequencer during configuration */
        CLR_BIT(base_add , PTR->sequencer );

        //ADC0_EMUX_R = 0xf000;
        ADC0_EMUX_R &= ~0xF000;

        /*Configure channel*/
        if(PTR->sequencer == ADC_sequencer_3)
        {
            //ADC_GEN_REG(base_add , ADCSSMUX3_reg_offset) = PTR->ADC_Channel;
            //HWREG_access(ADC_GEN_REG(base_add , ADCSSMUX3_reg_offset));
            ADC0_SSMUX3_R =  PTR->ADC_Channel;
        }
        else if(PTR->sequencer == ADC_sequencer_2)
        {
            /*Complete*/
        }
        else{}

        /* take one sample at a time, set flag at 1st sample */

        if(PTR->sequencer == ADC_sequencer_3)
        {
//            SET_BIT(ADC_GEN_REG(base_add , ADCSSCTL3_reg_offset) , 1);
//            SET_BIT(ADC_GEN_REG(base_add , ADCSSCTL3_reg_offset) , 2);
            SET_BIT(ADC0_SSCTL3_R , 1);
            SET_BIT(ADC0_SSCTL3_R , 2);
        }
        else if (PTR->sequencer == ADC_sequencer_2)
        {

        }
        else{}


        /* enable ADC sequencer  */
        //SET_BIT(base_add , PTR->sequencer );
        ADC0_ACTSS_R |= (1<<3);
    }
    else
    {
        //do nothing
    }
   
}
unsigned int ADC_Read_Data(const adc_config_t* PTR)
{
    
    unsigned int adc_value;
    if(PTR != NULL)
    {
        /*Determine Base address for the adc module*/
        unsigned int base_add = ADCn_BASE(PTR->ADCn);

        if(PTR->sequencer == ADC_sequencer_3)
        {

            /* disable sequencer during configuration */
            CLR_BIT(base_add , PTR->sequencer );
            //ADC_GEN_REG(base_add , ADCSSMUX3_reg_offset) = PTR->ADC_Channel;
            ADC0_SSMUX3_R =  PTR->ADC_Channel;

            /* enable ADC sequencer  */

            ADC0_ACTSS_R |= (1<<3);
            /* Enable conversion or start sampling data from analog channel */
            //SET_BIT(ADC_GEN_REG(base_add , ADCPSSI_reg_offset) , 3);
            SET_BIT(ADC0_PSSI_R , 3);
            /*Poll until conversion ends*/
            //while (GET_BIT(ADC_GEN_REG(base_add , ADCRIS_reg_offset) , 3) == 0);
            while (GET_BIT(ADC0_RIS_R , 3) == 0);

            /*Read number of levels*/
            //adc_value = ADC_GEN_REG(base_add , ADCSSFIFO3_reg_offset);
            adc_value = ADC0_SSFIFO3_R;

            /*clear end of conversion flag*/
            //CLR_BIT(ADC_GEN_REG(base_add , ADCISC_reg_offset) , 3);
            SET_BIT(ADC0_ISC_R , 3);
            
        }
    }
    else
    {
        //do nothing
    }
    return adc_value;
}
