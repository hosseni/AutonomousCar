/***************************************************/
/******** Author      : Hosseni            *********/
/******** Date        : 13/8/2023          *********/
/******** version     : 1.0 V              *********/
/******** Description : STD_TYPES          *********/
/***************************************************/

#ifndef INC_LIB_STD_TYPES_H_
#define INC_LIB_STD_TYPES_H_

typedef unsigned char        uint8 ;
typedef unsigned short int   uint16;
typedef unsigned  int        uint32;
typedef float                float32;

typedef signed char          sint8 ;
typedef signed short int     sint16;
typedef signed long  int     sint32;

#define DISABLE 0
#define ENABLE  1

typedef enum
{
    OK = 1 ,
    N_OK = 0
}Err_check_t;


typedef uint8 Std_ReturnType;
#define OK          0u
#define NOT_OK      1u

#define  NULL  ((void *)0)

typedef enum
{
    HIGH = 1 ,
    LOW = 0
}state_t;

#define GET_REG(BaseAddr,RegOffset)                              *((volatile uint32*)(BaseAddr+RegOffset))
#define BASE_ADDRESS_PRE                              0x40000000
#define BASE_ADDRESS_PRE_ALIAS                        0x42000000

#define ACCESS_ADR(x)                           (*((volatile uint32* )(x)))
#define ACCESS_BITBAND_ADR(adr, bit, base)      ACCESS_ADR((32u*adr)+base+(4u*bit))


#define GET_RegisterOffset(RegisterAddr)              ((RegisterAddr - BASE_ADDRESS_PRE)/4)
#define GET_BitOffset(RegisterAddr,BitPos)            ((GET_RegisterOffset(RegisterAddr)*32) + BitPos)
#define GET_BBAlIAS_PRE_REG(RegisterAddr, BitPos)     (*(volatile uint32*)((GET_BitOffset(RegisterAddr,BitPos)*4) + BASE_ADDRESS_PRE_ALIAS))

#define SET_BIT(Reg, bitnum)       (Reg |=(1<<bitnum))
#define CLR_BIT(Reg, bitnum)       (Reg &=~(1<<bitnum))
#define TOGGLE_BIT(Reg, bitnum)    (Reg ^=(1<<bitnum))
#define GET_BIT(Reg, bitnum)       ((Reg>>bitnum)& 0x01)
#define SET_BYTE(Reg,value)              ( Reg = value )


#define WORD_LENGTH_BITS      32u
#define WORD_LENGTH_BYTES     4u
#define MSB_FIRST             0u    /* big endian bit ordering */
#define LSB_FIRST        1u    /* little endian bit ordering */

#endif /* INC_LIB_STD_TYPES_H_ */
