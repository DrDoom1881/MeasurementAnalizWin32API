#include "Measurement.h"
std::vector<double> numBuff;
double sda;
double average;
double coefSt;
double relError;
double sysError;
double absError;

//SysError(double statError) {
//	this.sysError = statError;
//}
//void AbsError() {
//	this.absError = 
//}

double aver(char* buffer, int count)
{
	if (count == 0) return 0;
	numBuff.clear();
	double sum = 0;
	int j = 0;
	for (int i = 0; i < count+1; ++i)
	{
		if (buffer[i] == '\r' || (i+1)>count)
		{
			char* str = new char[i-j];
			for (int k = j; k < i; ++k)
			{
				str[k-j] = buffer[k];
			}

			numBuff.push_back(std::stod(str));
			sum += std::stod(str);
			delete[] str;
			i++;
			j = i+1;
		}

	}

	return sum/numBuff.size();
}

double standartDevAvear(double average)
{
	double sumSquare = 0;
	double temp = 0;
	for (int i = 0; i < numBuff.size(); i++) 
	{
		temp = average - numBuff[i];
		temp = pow(temp, 2);
		sumSquare += temp;
	}
	return sqrt(sumSquare / (numBuff.size() * (numBuff.size() - 1)));

}

double coeffOfStud()
{
	if (numBuff.size() - 1 <= 0) return -1;
	switch (numBuff.size() - 1)
	{
	case 1: return 12.71;
	case 2: return 4.3;
	case 3: return 3.18;
	case 4: return 2.78;
	case 5: return 2.57;
	case 6: return 2.45;
	case 7: return 2.36;
	case 8: return 2.31;
	case 9: return 2.26;
	case 10: return 2.23;
	case 11: return 2.20;
	case 12: return 2.17;
	case 13: return 2.16;
	case 14: return 2.15;
	case 15: return 2.13;
	case 16: return 2.12;
	case 17: return 2.11;
	case 18: return 2.10;
	case 19: return 2.09;
	case 20: return 2.09;
	case 21: return 2.08;
	case 22: return 2.07;
	case 23: return 2.07;
	case 24: return 2.06;
	case 25: return 2.06;
	case 26: return 2.06;
	case 27: return 2.05;
	case 28: return 2.05;
	case 29: return 2.05;
	case 30: return 2.04;
	case 40: return 2.02;
	case 60: return 2.00;
	case 120: return 1.98;
	default: return 1.96;
	}
	return 0;
}

double relativeError()
{
	return 0;
}


void RandMeasurementError(char* buffer, int count)
{


}
LPCSTR output(char* buffer, int count)
{
	sysError = 0;
	average = aver(buffer, count);
	sda = standartDevAvear( average);
	coefSt = coeffOfStud();
	relError = sda * coefSt;
	absError = sqrt(pow(sysError, 2) + pow(relError, 2));
	std::string* str = new std::string
	{ 
				"Середнє: " + std::to_string(aver(buffer, count)) + "\r\n" +
				"Cер.кв.відхил.від середнього: " + std::to_string(sda) + "\r\n" +
				"К-єнт ст`юдента: " + std::to_string(coefSt) + "\r\n" +
				"dA(випадкове): " + std::to_string(relError) + "\r\n" +
				"dA(систематична): " + std::to_string(sysError) + "\r\n" +
				"A +- dA(абсолютна): " + std::to_string(average) + " +- " + std::to_string(absError) + "\r\n" +
				"E= " + std::to_string(relativeError() / average) + "\r\n"
	};
	return  str->c_str();
}