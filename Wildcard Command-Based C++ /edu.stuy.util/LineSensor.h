/*
 * LineSensor.h
 */

#ifndef EDU_STUY_UTIL_LINESENSOR_H_
#define EDU_STUY_UTIL_LINESENSOR_H_

#include <AnalogInput.h>

class LineSensor {
private:
	constexpr double DRIVETRAIN_LINE_SENSOR_INITIALIZE_TIME = 3;
    constexpr double DRIVETRAIN_LINE_SENSOR_THRESHOLD = -1.0;

    int framesExisted;
	int ambientLight;
    bool isChangedBefore;
    int max;
    int rawValue;
    bool setupDone;
    AnalogInput * mySensor;
public:
	LineSensor(int port);
	double GetRawData();
	void InitialLoop();
	void MainLoop();
	void ResetAmbient();
	bool BasicFind();
	virtual ~LineSensor();
};

#endif /* EDU_STUY_UTIL_LINESENSOR_H_ */
