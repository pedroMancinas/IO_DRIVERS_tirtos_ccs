/*******************************************************************************************
 * FileName:        GPIO_MSP432.h
 * Dependencies:    system.h
 * Processor:       MSP432
 * Board:           MSP432P401R
 * Program version: CCS V10.4 TI
 * Company:         TecNM /IT Chihuahua
 * Description:     Definici�n de funciones del m�dulo GPIO para entradas y salidas.
 * Authors:         ALFREDO CHACON
 * Created on:      18 Nov. 2021
 * Updated:
 */
/************************************************************************************************
 * * Copyright (C) 2021 by Alfredo Chacon - TecNM /IT Chihuahua
 *
 * Se permite la redistribucion, modificacion o uso de este software en formato fuente o binario
 * siempre que los archivos mantengan estos derechos de autor.
 * Los usuarios pueden modificar esto y usarlo para aprender sobre el campo de software embebido.
 * Alfredo Chacon y el TecNM /IT Chihuahua no son responsables del mal uso de este material.
 *************************************************************************************************/
#ifndef GPIO_MSP432_H_
#define GPIO_MSP432_H_
#include <ti/devices/msp432p4xx/inc/msp432p401r.h>
#include "system.h"
/* Definiciones para el m�dulo GPIO. */
#define GPIO_HIGH_TO_LOW_TRANSITION                                      (0x01)
#define GPIO_LOW_TO_HIGH_TRANSITION                                      (0x00)

#define GPIO_INPUT_PIN_HIGH                                              (0x01)
#define GPIO_INPUT_PIN_LOW                                               (0x00)

#define GPIO_PRIMARY_MODULE_FUNCTION                                     (0x01)
#define GPIO_SECONDARY_MODULE_FUNCTION                                   (0x02)
#define GPIO_TERTIARY_MODULE_FUNCTION                                    (0x03)

// Bits.
#define B0    0
#define B1    1
#define B2    2
#define B3    3
#define B4    4
#define B5    5
#define B6    6
#define B7    7

// Definiciones I/O.
#define SET_OUTPUT  1
#define SET_INPUT   0
#define PULLUP_EN   1
#define PULLUP_DIS  0
#define HIGH        1
#define LOW         0
#define INT_EN      1
#define INT_DIS     0
//Definiciones de Puertos
#define GPIO_PORT_P1    1
#define GPIO_PORT_P2    2
#define GPIO_PORT_P3    2
#define GPIO_PORT_P4    4
#define GPIO_PORT_P5    5
//Definiciones de pines para las funciones
#define GPIO_PIN0    (0x0001)
#define GPIO_PIN1    (0x0002)
#define GPIO_PIN2    (0x0004)
#define GPIO_PIN3    (0x0008)
#define GPIO_PIN4    (0x0010)
#define GPIO_PIN5    (0x0020)
#define GPIO_PIN6    (0x0040)
#define GPIO_PIN7    (0x0080)
//Calculos de los offsets de cada uno de los registros para puertos Pares y nones, segun las estructuras definidas en msp432p401r.h
#define OFS_LIB_PAIN    ((uint32_t)&P1->IN - (uint32_t)P1)
#define OFS_LIB_PAOUT   ((uint32_t)&P1->OUT - (uint32_t)P1)
#define OFS_LIB_PADIR   ((uint32_t)&P1->DIR - (uint32_t)P1)
#define OFS_LIB_PAREN   ((uint32_t)&P1->REN - (uint32_t)P1)
#define OFS_LIB_PADS    ((uint32_t)&P1->DS - (uint32_t)P1)
#define OFS_LIB_PASEL0  ((uint32_t)&P1->SEL0 - (uint32_t)P1)
#define OFS_LIB_PASEL1  ((uint32_t)&P1->SEL1 - (uint32_t)P1)
#define OFS_LIB_PAIE    ((uint32_t)&P1->IE - (uint32_t)P1)
#define OFS_LIB_PAIES   ((uint32_t)&P1->IES - (uint32_t)P1)
#define OFS_LIB_PAIFG   ((uint32_t)&P1->IFG - (uint32_t)P1)
#define OFS_LIB_P1IE    ((uint32_t)&P1->IE - (uint32_t)P1)
#define OFS_LIB_P2IE    OFS_LIB_P1IE

//Ejercicio 7
#define PUERTO1    1
#define PUERTO2    2
#define PUERTO3    2
#define PUERTO4    4
#define PUERTO5    5

#define LEDROJO     (0x0001)
#define LEDVERDE    (0x0002)
#define LEDAZUL     (0x0004)

#define BOTON2    0x10
#define BOTON1   0x02
#define BOTON3   (0x0008)



 /*****************************************************************************************
                                      PROTOTIPOS DE FUNCION DE NUESTRO DRIVER
 ******************************************************************************************/
extern uint8_t Gpio_Pin_in( uint_fast16_t pin_);
 extern uint8_t Gpio_Pin2_in( uint_fast16_t pin_);
 extern void  Gpio_init2021( void );//ejercicio 9

extern void GPIO_setPinSalida(uint_fast8_t selectedPort,                      uint_fast16_t selectedPins);
extern void GPIO_setPinAlto(uint_fast8_t selectedPort,                  uint_fast16_t selectedPins);
extern void GPIO_setPinBajo(uint_fast8_t selectedPort,                   uint_fast16_t selectedPins);
extern void GPIO_setPinEntradaconPullUp(uint_fast8_t selectedPort,     uint_fast16_t selectedPins);
extern uint8_t GPIO_getPinValor(uint_fast8_t selectedPort,                 uint_fast16_t selectedPins);

/*
 DECLARACI�N DE MACROS Para la funcion Gpio_init_board.

 Configurar un pin como entrada o salida.
#define GPIO_set_output_bit(P,B)        (BITBAND_PERI(P->DIR, B) = SET_OUTPUT)
#define GPIO_set_input_bit(P,B)         (BITBAND_PERI(P->DIR, B) = SET_INPUT)

 Habilitar o deshabilitar resistencias de pullup en un pin de un puerto en espec�fico.
#define GPIO_enable_bit_pullup(P,B)     (BITBAND_PERI(P->REN, B) = PULLUP_EN)
#define GPIO_disable_bit_pullup(P,B)    (BITBAND_PERI(P->REN, B) = PULLUP_DIS)

 Cambiar estado de un pin de salida.
#define GPIO_write_bit_high(P,B)        (BITBAND_PERI(P->OUT, B) = HIGH)
#define GPIO_write_bit_low(P,B)         (BITBAND_PERI(P->OUT, B) = LOW)

 Lectura de un pin.
#define GPIO_read_bit(P,B)              (BITBAND_PERI(P->IN, B))

 Habilitar o deshabilitar interrupci�n en un pin.
#define GPIO_enable_bit_interrupt(P,B)  (BITBAND_PERI(P->IE, B) = INT_EN)
#define GPIO_disable_bit_interrupt(P,B) (BITBAND_PERI(P->IE, B) = INT_DIS)

 Limpiar una bandera de interrupci�n.
#define GPIO_clear_interrupt_flag(P,B)  (BITBAND_PERI(P->IFG, B) = LOW)
*/

#endif /* GPIO_MSP432_H_ */
