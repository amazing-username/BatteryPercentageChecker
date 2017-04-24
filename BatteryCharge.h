#ifndef BATTERYCHARGE_H
#define BATTERYCHARGE_H

template<typename Bat>
class BatteryCharge
{
public:
	BatteryCharge();

	Bat getCurrentPercentage() const;
private:	
	void setCapacity();
	void setPercentage();

	Bat batteryCapacity;	
	Bat batteryPercentage;	
};

#endif

#include<fstream>
#include<ios>

template<typename Bat>
BatteryCharge<Bat>::BatteryCharge()
{
	setCapacity();
	setPercentage();
}

template<typename Bat>
Bat BatteryCharge<Bat>::getCurrentPercentage() const
{
	auto percentage = batteryPercentage / batteryCapacity;
	percentage *= 100;
	return percentage;
}

template<typename Bat>
void BatteryCharge<Bat>::setCapacity()
{
	std::fstream capacity{};
	capacity.open("/sys/class/power_supply/BAT0/charge_full", std::ios::in);
	capacity >> batteryCapacity;	
	capacity.close();
}

template<typename Bat>
void BatteryCharge<Bat>::setPercentage()
{
	std::fstream currentBatteryPercentage{};	
	currentBatteryPercentage.open("/sys/class/power_supply/BAT0/charge_now", std::ios::in);
	currentBatteryPercentage >> batteryPercentage;
	currentBatteryPercentage.close();
}
