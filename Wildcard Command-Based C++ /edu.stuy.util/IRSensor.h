/*
 * IRSensor.h
 */

#ifndef EDU_STUY_UTIL_IRSENSOR_H_
#define EDU_STUY_UTIL_IRSENSOR_H_

#include <AnalogInput.h>

class IRSensor {
private:
	constexpr int IR_SENSOR_PORT = -1;
    constexpr double IR_SENSOR_THRESHOLD = 1.0;
    constexpr double IR_TIME_IN_MECHANISM_THRESHOLD = 1.0;

    constexpr double EQUATION_FACTOR = 12.23368994;
    constexpr double EQUATION_EXPONENT = -0.9779601588;
    constexpr double CONVERSION_FACTOR_CM_TO_INCHES = 0.393701;

    static AnalogInput * cubeSensor;

public:
	IRSensor();
	virtual ~IRSensor();
	static double getSensorVoltage();
	static bool isCubeDetected();
};

#endif /* EDU_STUY_UTIL_IRSENSOR_H_ */
