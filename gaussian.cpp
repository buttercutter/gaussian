#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

static bool hasSpare = false;

double generateGaussianNoise(const double& mean, const double &stdDev)
{
  	static double spare;
  
	//cout << "hasSpare = " << hasSpare << "\n" ;

  	if(hasSpare)
  	{
		//cout << "hasSpare\n" ;
  		hasSpare = false;
  		return mean + stdDev * spare;
 	}
 
 	hasSpare = true;

	//cout << "hasSpare2 = " << hasSpare << "\n" ;

 	static double u, v, s;
 	do
 	{
 		u = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
 		v = (rand() / ((double) RAND_MAX)) * 2.0 - 1.0;
 		s = u * u + v * v;
 	}
 	while( (s >= 1.0) || (s == 0.0) );//|| (v * s > 4) || (v * s < -4) || (u * s > 4) || (u * s < -4));

 	s = sqrt(-2.0 * log(s) / s);
 	spare = v * s;
 	return mean + stdDev * u * s;
}


int main(int argc, char *argv[])
{
    int n = 0;
    ofstream outfile;
    outfile.open("results.txt");

    while (n < 10000000)
    {
     	double AWGN = generateGaussianNoise(0,1);
    	n++;
    	//cout << AWGN << "\n" ;
	outfile << AWGN << endl;
    }
    return 0;
}


/*Octave Code
>> x = dlmread('results.txt');
>> hist(x,100,1);
>> dB = fft(x);
>> plot(abs(dB));
>> plot(20*log10(abs(dB).^2));
//http://www.ni.com/white-paper/4278/en/
*/
