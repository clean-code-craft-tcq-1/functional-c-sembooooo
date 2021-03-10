/**
 * This file is the configuration file for the entire code base 
 * What can be a part of config:
 *  - thresholds  <for now >
 *  - <in future we can add>
 **/
#include "Parameter_configElements.h"


#define BMS_TEMPARATURE_LOWER_RANGE             0.0f
#define BMS_TEMPARATURE_HIGHER_RANGE            45.0f
/**
 * The warning tolerances should be entered in percentages.
*/
#define BMS_TEMPARATURE_WARNING_TOLERANCE       0.05f
#define BMS_TEMPARATURE_LOWER_WARNING_RANGE    \
                (BMS_TEMPARATURE_LOWER_RANGE + (BMS_TEMPARATURE_HIGHER_RANGE * BMS_TEMPARATURE_WARNING_TOLERANCE))

#define BMS_TEMPARATURE_HIGHER_WARNING_RANGE    \
                (BMS_TEMPARATURE_HIGHER_RANGE - (BMS_TEMPARATURE_HIGHER_RANGE * BMS_TEMPARATURE_WARNING_TOLERANCE))



#define BMS_STATEOFCHARGE_LOWER_RANGE           20.0f
#define BMS_STATEOFCHARGE_HIGHER_RANGE          80.0f
/**
 * The warning tolerances should be entered in percentages
*/
#define BMS_STATEOFCHARGE_WARNING_TOLERANCE     0.05  
#define BMS_STATEOFCHARGE_LOWER_WARNING_RANGE    \
                (BMS_STATEOFCHARGE_LOWER_RANGE + (BMS_STATEOFCHARGE_HIGHER_RANGE * BMS_STATEOFCHARGE_WARNING_TOLERANCE))

#define BMS_STATEOFCHARGE_HIGHER_WARNING_RANGE    \
                (BMS_STATEOFCHARGE_HIGHER_RANGE - (BMS_STATEOFCHARGE_HIGHER_RANGE * BMS_STATEOFCHARGE_WARNING_TOLERANCE))

/**
 * The warning tolerances should be entered in percentages
*/
#define BMS_CHARGERATE_WARNING_TOLERANCE        0.05f
#define BMS_CHARGERATE_HIGHER_RANGE              0.8f
#define  BMS_CHARGERATE_HIGHER_WARNING_RANGE    \
                (BMS_CHARGERATE_HIGHER_RANGE + (BMS_CHARGERATE_HIGHER_RANGE * BMS_CHARGERATE_WARNING_TOLERANCE))


#define BMS_ALERT_LANGUAGE  BMS_ALERT_LANGUAGE_ENGLISH