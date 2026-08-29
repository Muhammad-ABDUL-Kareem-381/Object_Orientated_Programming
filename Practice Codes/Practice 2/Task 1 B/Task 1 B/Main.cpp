#include<iostream>
using namespace std;
struct WeatherInfo
{
	char city[50];
	char country[50];
	double totalRainfall;
	double highTemperature;
	double lowTemperature;
	double averageTemperature;
};
void inputName(char* tempArr);
void inputWeatherInfo(WeatherInfo& a);
double gretAverageTemp(double temp1,double temp2);
void printWeatherInfo(WeatherInfo& a);
int main()
{
	WeatherInfo info;
	inputWeatherInfo(info);
	printWeatherInfo(info);
	return 0;
}
void inputWeatherInfo(WeatherInfo& a)
{
	cout << "Enter the city name : ";
	inputName(a.city);
	cout << "Enter the country name : ";
	inputName(a.country);
	cout << "Enter the total rainfall : ";
	cin >> a.totalRainfall;
	cout << "Enter the high temperature : ";
	cin >> a.highTemperature;
	cout << "Enter the low temperature : ";
	cin >> a.lowTemperature;
	a.averageTemperature = gretAverageTemp(a.highTemperature, a.lowTemperature);
}
void inputName(char* tempArr)
{
	cin.getline(tempArr, 50);
}
void printWeatherInfo(WeatherInfo& a)
{
	cout << "\n";
	cout << "City is = " << a.city << "\n";
	cout << "Country is = " << a.country << "\n";
	cout << "The amount of totalRainfall is = " << a.totalRainfall << "\n";
	cout << "The highTemperature is = " << a.highTemperature << "\n";
	cout << "The lowTemperature is = " << a.lowTemperature << "\n";
	cout << "The average of temperature is = " << a.averageTemperature << "\n";
}
double gretAverageTemp(double temp1, double temp2)
{
	return( (temp1 + temp2) / 2.0);
}