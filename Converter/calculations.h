#ifndef CALCULATIONS_H
#define CALCULATIONS_H

#include <QObject>
#include <math.h>

class calculations : public QObject
{
    Q_OBJECT
public:
    explicit calculations(QObject *parent = nullptr);

    const char *lengthUnits[2][3]={{"Centimeter","Meter","Kilometer"},{"cm","m","km"}};
    const char *temperatureUnits[2][3]={{"Celsius","Fahrenheit","Kelvin"},{"°C","°F","K"}};
    const char *massUnits[2][3]={{"Milligram","Gram","Kilogram"},{"mg","g","kg"}};
    const char *timeUnits[2][3]={{"Second","Minute","Hour"},{"s","min","h"}};
    const char *angleUnits[2][3]={{"Degree","Radian","Gradian"},{"°","rad","grad"}};

public slots:

    // Length Conversions
    double metersToCentimeters(double value);
    double kilometersToCentimeters(double value);
    double centimetersToMeters(double value);
    double kilometersToMeters(double value);
    double centimetersToKilometers(double value);
    double metersToKilometers(double value);

    // Temperature Conversions
    double kelvinToCelsius(double value);
    double fahrenheitToCelsius(double value);
    double kelvinToFahrenheit(double value);
    double celsiusToFahrenheit(double value);
    double celsiusToKelvin(double value);
    double fahrenheitToKelvin(double value);

    // Mass Conversions
    double gramsToMilligrams(double value);
    double kilogramsToMilligrams(double value);
    double milligramsToGrams(double value);
    double kilogramsToGrams(double value);
    double milligramsToKilograms(double value);
    double gramsToKilograms(double value);

    // Time Conversions
    double minutesToSeconds(double value);
    double hoursToSeconds(double value);
    double secondsToMinutes(double value);
    double hoursToMinutes(double value);
    double secondsToHours(double value);
    double minutesToHours(double value);

    // Plane Angle Conversions
    double radiansToDegrees(double value);
    double gradiansToDegrees(double value);
    double degreesToRadians(double value);
    double gradiansToRadians(double value);
    double degreesToGradians(double value);
    double radiansToGradians(double value);

signals:

};

#endif // CALCULATIONS_H
