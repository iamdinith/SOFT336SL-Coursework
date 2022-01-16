#include "calculations.h"

calculations::calculations(QObject *parent) : QObject(parent)
{

}

// Length Conversions
double calculations::metersToCentimeters(double value)
{
    return value*100;
}
double calculations::kilometersToCentimeters(double value)
{
    return value*100000;
}
double calculations::centimetersToMeters(double value)
{
    return value/100;
}
double calculations::kilometersToMeters(double value)
{
    return value*1000;
}
double calculations::centimetersToKilometers(double value)
{
    return value/100000;
}
double calculations::metersToKilometers(double value)
{
    return value/1000;
}


// Temperature Conversions
double calculations::kelvinToCelsius(double value)
{
    return value-273.15;
}
double calculations::fahrenheitToCelsius(double value)
{
    return (value-32)*5/9;
}
double calculations::kelvinToFahrenheit(double value)
{
    return (value-273.15)*9/5+32;
}
double calculations::celsiusToFahrenheit(double value)
{
    return (value*9/5)+32;
}
double calculations::fahrenheitToKelvin(double value)
{
    return (value-32)*5/9+273.15;
}
double calculations::celsiusToKelvin(double value)
{
    return value+273.15;
}


// Mass Conversions
double calculations::gramsToMilligrams(double value)
{
    return value*1000;
}
double calculations::kilogramsToMilligrams(double value)
{
    return value*1000000;
}
double calculations::milligramsToGrams(double value)
{
    return value/1000;
}
double calculations::kilogramsToGrams(double value)
{
    return value*1000;
}
double calculations::milligramsToKilograms(double value)
{
    return value/1000000;
}
double calculations::gramsToKilograms(double value)
{
    return value/1000;
}


// Time Conversions
double calculations::minutesToSeconds(double value)
{
    return value*60;
}
double calculations::hoursToSeconds(double value)
{
    return value*3600;
}
double calculations::secondsToMinutes(double value)
{
    return value/60;
}
double calculations::hoursToMinutes(double value)
{
    return value*60;
}
double calculations::secondsToHours(double value)
{
    return value/3600;
}
double calculations::minutesToHours(double value)
{
    return value/60;
}


// Plane Angle Conversions
double calculations::radiansToDegrees(double value)
{
    return value*180/M_PI;
}
double calculations::gradiansToDegrees(double value)
{
    return value*180/200;
}
double calculations::degreesToRadians(double value)
{
    return value*M_PI/180;
}
double calculations::gradiansToRadians(double value)
{
    return value*M_PI/200;
}
double calculations::degreesToGradians(double value)
{
    return value*200/180;
}
double calculations::radiansToGradians(double value)
{
    return value*200/M_PI;
}
