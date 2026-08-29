#include<iostream>
using namespace std;
void copyCharArray(const char* src, char* tar);
class WeatherStatistics
{
private:
	char city[50];
	char country[50];
	float totalRainfall;
	float highTemperature;
	float lowTemperature;
	float averageTemperature;
	void setFactoryVersion()
	{
		copyCharArray("Lhr", city);
		copyCharArray("Pk", country);
		totalRainfall = 1;
		highTemperature = 7;
		lowTemperature = 1;
		averageTemperature = 3;
	}
public:
	WeatherStatistics()
	{
		setFactoryVersion();
	}
	WeatherStatistics(const char* c, const char* coun, float rFall, float hTemp, float lTemp, float avgTemp):WeatherStatistics()
	{
		if (c && coun && (rFall >= 0) )
		{
			copyCharArray(c, city);
			copyCharArray(coun, country);
			totalRainfall = rFall;
			highTemperature = hTemp;
			lowTemperature = lTemp;
			averageTemperature = avgTemp;
		}
	}
	void inputWeatherStatistics()
	{
		cout << "Enter city:";
		cin.getline(city, 50);
		cin.ignore();
		cout << "Enter country:";
		cin.getline(country, 50);
		do
		{
			cout << "Enter total rainfall:";
			cin >> totalRainfall;
		} 
		while (totalRainfall < 0);
		cout << "Enter high temperature:";
		cin >> highTemperature;
		cout << "Enter low temperature:";
		cin >> lowTemperature;
		cout << "Enter average temperature:";
		cin >> averageTemperature;
	}
	void displayWeatherStatistics()
	{
		cout << "City:" << city << '\n';
		cout << "Country:" <<country << '\n';
		cout << "total rainfall:" << totalRainfall << '\n';
		cout << "High temperature:" << highTemperature << '\n';
		cout << "Low temperature:" << lowTemperature << '\n';
		cout << "Average temperature:" << averageTemperature << '\n';
	}
	void setCity(const char* c)
	{
		if (c)
		{
			copyCharArray(c, city);
		}
	}
	void setCountry(const char* c)
	{
		if (c)
		{
			copyCharArray(c, country);
		}
	}
	void settotalRainFall(float rFall)
	{
		if()
	}
};
int main()
{
	WeatherStatistics weather;
	weather.inputWeatherStatistics();
	weather.displayWeatherStatistics();
	return 0;
}
void copyCharArray(const char* src, char* tar)
{
	int i = 0;
	while (src[i] != '\0')
	{
		tar[i] = src[i];
		i++;
	}
	tar[i] = '\0';
}