#ifndef _CONSTANTS_HEXAPOD_H
#define _CONSTANTS_HEXAPOD_H

// Endereçamento dos PCA
#define PCA9685_ADDRESS_1 0x40
#define PCA9685_ADDRESS_2 0x41

// Especificações do PWM
const int FREQUENCY = 50;
const int MIN_PULSE_WIDTH = 220;
const int MAX_PULSE_WIDTH = 470;
const unsigned long INTERVAL = 100;

// Controle de velocidade e distância máxima
const int DELAY_TIME = 15;
const int MAX_ANGLE = 180;

// Especificações dos membros do hexapod
const double COXA = 45; // sem uso por enquanto
const double FEMUR = 75;
const double TIBIA = 160;
const double J3_offsetting = 10;
const double Y_REST = 160;
const double Z_REST = -100;

const double MIN_SAFE_ANGLE = 45;
const double MAX_SAFE_ANGLE = 35;

#endif