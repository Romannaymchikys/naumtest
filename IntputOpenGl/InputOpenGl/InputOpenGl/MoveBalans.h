#pragma once
#include <iostream>
#include <math.h>
#include <vector>
class MoveBalans
{
	// coordinats.first = x;
	// coordinats.second = y;
	// ������� ���� angleBag_1 = 60;

	// ��������� ���������� ������
	std::pair<double, double>   couplCoordinats;
	// ���������� ��������
	std::pair<double, double> subjectCoordinats;
	// ��������� ���� �������
	double angleStart;
	// ����������� �������� ��������
	// ���� - true 
	// ����� - false
	bool narrative;
	// ������
	double radius;
	// �������� � ������������ ���������
	size_t counter;
	// ������ � ��������� ��������
	std::vector<std::pair<int, int>> vecIndex;
	// ���� ����������
	const double powerGravity = 0.001;
	// ��������
	double speed;
	// ��� �������� ��� ���������
	double plusSpeed;
	// ���� ��������
	double angleSpeed;
	// ���� ���������;
	double angleGravity;
	// ���� ��������� ��� ����������;
	double angleAccel_1;

public:
	// 

	MoveBalans(double newAngleStart, double newRadius,
		double coulX,
		double coulY,
		bool newNarrative = true, size_t newcounter = 1, double newSpeed = 0) :
		                                             angleStart(newAngleStart),
	                                                 radius(newRadius),
		                                             couplCoordinats(coulX, coulY),
		                                             narrative(newNarrative),
		                                             counter(newcounter),
													 speed(newSpeed){

		vecIndex.push_back(std::pair <int, int>(1, 1));
		vecIndex.push_back(std::pair <int, int>(1, -1));
		vecIndex.push_back(std::pair <int, int>(-1,-1));
		vecIndex.push_back(std::pair <int, int>(-1, 1));
	};
	std::pair<double, double>  setCouplCoordinats()const { return couplCoordinats; }
	std::pair<double, double>  setsubjectCoordinats()const { return couplCoordinats; }

	double  getCouplPOS_X()const { return couplCoordinats.first; }
	double  getCouplPOS_Y()const { return couplCoordinats.second; }

	double  getSubjectPOS_X()const { return subjectCoordinats.first; }
	double  getSubjectPOS_Y()const { return subjectCoordinats.second; }

	size_t  getAngleStart()const { return angleStart; }
	double  getRadius()const { return radius; }
	bool    getNarrative()const { return narrative; }

	std::vector<std::pair<int, int>> getVecIndex()const { return vecIndex; }
	//________________________________________________________________________________


	void setCouplPOS_X(double newCouplPOS_X) { 
		couplCoordinats.first  = newCouplPOS_X; }
	void  setCouplPOS_Y(double newCouplPOS_Y) {
		couplCoordinats.second = newCouplPOS_Y; }

	void  setSubjectPOS_X(double newSubjectPOS_X) {
		subjectCoordinats.first = newSubjectPOS_X;}
	void  setSubjectPOS_Y(double newSubjectPOS_Y) {
		subjectCoordinats.second = newSubjectPOS_Y;}

	void  setAngleStart(size_t newAngleStart) { angleStart = newAngleStart; }
	void  setRadius(double newRadius) { radius = newRadius; }
	void  setNarrative(double newNarrative) { narrative = newNarrative; }
	
	//  ���������� ����������
	void calcCoordinat(std::pair<int, int>, double&, double&);
	// 1 ���������� ������ ����������
	void calcFirstCoordinat();
	// 2 ���������� ����
	void calculationAngleBag();
	// ���������� ���� ���������
	double  calculationAngleGravity(const double, const double, const size_t);
	// ���������� ������ ������
	double CalculationlengthSide(const double, const double);
	// �������� ������� ��� �������� ���� ������
	void countingDataToMove(const short);
	// �������� ���� �� ���������
	void transition();

	
	~MoveBalans() {};
};
/*std::pair<double, double> subjectCoordinats,
		const std::pair<double, double>  couplCoordinats,
		const double radius,
		const size_t angleStart*/
