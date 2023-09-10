/***************************************************/
/******** Author      : Hosseni            *********/
/******** Date        : 13/8/2023          *********/
/******** version     : 1.0 V              *********/
/******** Description : RCC                *********/
/***************************************************/



#ifndef INC_MCAL_SCB_SCB_PRIVATE_H_
#define INC_MCAL_SCB_SCB_PRIVATE_H_

#define ACCESS_ADR(x)                           (*(( volatile uint32* )(x)))

#define SYSCTRL_BASE            0x400FE000lu


#define RCC                     ACCESS_ADR(SYSCTRL_BASE+0x060u)
#define RCC2                    ACCESS_ADR(SYSCTRL_BASE+0x070u)
#define RCC                     ACCESS_ADR(SYSCTRL_BASE+0x060u)
#define GPIOHBCTL               ACCESS_ADR(SYSCTRL_BASE+0x06Cu)
#define RCGCGPIO                ACCESS_ADR(SYSCTRL_BASE+0x608u)
#define RCGCTIMER               ACCESS_ADR(SYSCTRL_BASE+0x604u)
#define RCGCWTIMER              ACCESS_ADR(SYSCTRL_BASE+0x65Cu)


//typedef struct sSCB_t
//{
//
//}sSCB_t;
//
//#define SCB (volatile *sSCB_t)0x400FE000)

#endif /* INC_MCAL_SCB_SCB_PRIVATE_H_ */
