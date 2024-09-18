#pragma once
struct Car {
private:  //modifier
	float fuel{ 0 };
	float speed{ 0 };
	int passengers{ 0 };
	int arr[5] = { 1,2,3 };
	char *p{};
public:
	Car(); // default constructor
	Car(float amount);
	void FillFuel(float amount);
	void Accelerate();
	void Brake();
	void AddPassengers(int count); 
	void Dashboard();
	~Car();
};
