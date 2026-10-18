#ifndef BIGINTS_H
#define BIGINTS_H
#include <iostream>
#include <string>
#define MAXSIZE 100

class BigInt {
	public:
		int* data;
		int size;
		bool sign;

		std::ostream& print(std::ostream& out);
		void calcSize();
		bool set(std::string s);
		bool addTo(BigInt& b);
		bool subtractFrom(BigInt& b);
		bool multiplyBy(BigInt& a, BigInt& b);
		bool compare(BigInt& b);

		BigInt(int* arr, int arrSize, bool arrSign){
			size = arrSize;
			sign = arrSign;
			data = new int[MAXSIZE];
			for(int i=1; i<=MAXSIZE; i++){
				if(i<=size){
					data[MAXSIZE-size-1+i] = arr[i-1];
				}
				else{
					data[MAXSIZE-i] = 0;
				}
			}
		}

		BigInt(const BigInt& a){
			size = a.size;
			sign = a.sign;
			data = new int[MAXSIZE]{};
			for(int i=0; i<MAXSIZE; i++){
				std::cout<<a.data[i]<<'\n';
				data[i] = a.data[i];
			}
		}

		~BigInt(){
			delete data;
		}
};

#endif

