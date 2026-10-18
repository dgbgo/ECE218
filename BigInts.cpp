#include "/home/diego/Education/ECE218/Libs/BigInts.h"

std::ostream& BigInt::print(std::ostream& out){
	char printSign = (this->sign)? '-' : '+';
	out<<printSign;
	for(int i=1; i<=this->size; i++){
		out<<this->data[MAXSIZE-size-1+i];
	}
	out<<'\n';
	return out;
}

void BigInt::calcSize(){
	for(int i=0; i<MAXSIZE; i++){
		if (this->data[i] != 0){
			this->size = MAXSIZE-i;
		}
	}
}

bool BigInt::compare(BigInt& b){
	if(b.sign == this->sign){
			if(this->size>b.size){ 
				std::cout<<"bigger";
				return 1;

			}
			else if(this->size<b.size){
				std::cout<<"smaller\n";
				return 0;
			}
			else{
				std::cout<<"same size";
				int i=0;
				while(this->data[MAXSIZE-b.size+i-1] == b.data[MAXSIZE-b.size+i-1]){
					i++;
				}
				return (this->data[MAXSIZE-b.size+i-1] > b.data[MAXSIZE-b.size]); 
			}
	}
	else if(b.sign != this->sign){
		if(this->sign == 1){
			std::cout<<"neg val\n";
			return 0;
		}
		if(this->sign == 0){
			std::cout<<"pos val\n";
			return 1;
		}
	}
	std::cerr<<"comparison failed\n";
	return 0;
}

bool BigInt::addTo(BigInt& b){
	int carry = 0;
	if(this->sign == b.sign){
		int biggest_size = (this->size > b.size)? this->size : b.size;
		b.size = biggest_size;
		for(int i=1; i<=biggest_size; i++){
			b.data[MAXSIZE - i] = this->data[MAXSIZE - i] + b.data[MAXSIZE - i] + carry;
			if(b.data[MAXSIZE - i]>9){
				b.data[MAXSIZE - i] = b.data[MAXSIZE - i]%10;
				carry = 1;
				if((i==MAXSIZE) && (carry==1)){
					return false;
				}
			}
			else if(b.data[MAXSIZE - i]<10){
				carry = 0;
			}
		}
		if(carry==1){
			b.size++;
			b.data[MAXSIZE-b.size] = 1;
		}
		if(b.size<=MAXSIZE) return true;
		else return false;
	}
  	else{
                int j = 1;
                int* changeSize = &b.size;
                int* subtracted = b.data;
                int* subtractor = this->data;
                BigInt ans(*this);
                int k;
                if(compare(b)){
                        std::cout<<"myInt is bigger\n";        
                        changeSize = &ans.size;
                        subtracted = ans.data;
                        subtractor = b.data;
                        b.sign != b.sign;
                }
                for(int i=1; i<=(*changeSize); i++){
                        std::cout<<*(subtracted+MAXSIZE-i)<<"|--";
                        if((*subtracted+MAXSIZE-i) < *(subtractor+MAXSIZE-i)){
                                std::cout<<"diff found";
                                while(carry==0 && i+j-1<MAXSIZE){
                                        if(*((subtracted+MAXSIZE-i-j)) > 0){
                                                (*(subtracted+MAXSIZE-i-j))--;
                                                carry=1;
                                        }
                                }
                        carry=0;
                        }
                        std::cout<<*(subtractor+MAXSIZE-i)<<"|";
                        std::cout<<*(subtracted+MAXSIZE-i)<<"|";
                        b.data[MAXSIZE-i] =  (*(subtracted+MAXSIZE-i)) - (*(subtractor+MAXSIZE-i));
                        std::cout<<b.data[MAXSIZE-i]<<'\n';
                }
                if(b.size <= MAXSIZE)return true;
                else return false;
        }

}

bool BigInt::subtractFrom(BigInt& b){
        int carry = 0;
	if(this->sign == b.sign){
		int j = 1;
		int* changeSize = &b.size;
		int* subtracted = b.data;
		int* subtractor = this->data;
		BigInt ans(*this);
		int k;
		if(compare(b)){
			std::cout<<"intTwo is bigger\n";	
			changeSize = &ans.size;
			subtracted = ans.data;
			subtractor = b.data;
			b.sign != b.sign;
		}
		for(int i=1; i<=(*changeSize); i++){
			std::cout<<*(subtracted+MAXSIZE-i)<<"|--";
			if((*subtracted+MAXSIZE-i) < *(subtractor+MAXSIZE-i)){
				std::cout<<"diff found";
				while(carry==0 && i+j-1<MAXSIZE){
					if(*((subtracted+MAXSIZE-i-j)) > 0){
						(*(subtracted+MAXSIZE-i-j))--;;
						carry=1;
					}
				}
			carry=0;
			}
			std::cout<<*(subtractor+MAXSIZE-i)<<"|";
			std::cout<<*(subtracted+MAXSIZE-i)<<"|";
			b.data[MAXSIZE-i] =  (*(subtracted+MAXSIZE-i)) - (*(subtractor+MAXSIZE-i));
			std::cout<<b.data[MAXSIZE-i]<<'\n';
		}
		if(b.size <= MAXSIZE)return true;
		else return false;
	}
	else{
		int biggest_size = (this->size > b.size)? this->size : b.size;
		b.size = biggest_size;

                for(int i=1; i<=biggest_size; i++){
                         b.data[MAXSIZE - i] = this->data[MAXSIZE - i] + b.data[MAXSIZE - i] + carry;
                         if(b.data[MAXSIZE - i]>9){
                                 b.data[MAXSIZE - i] = b.data[MAXSIZE - i]%10;
                                 carry = 1;
                                 if((i==MAXSIZE) && (carry==1)){
                                         return false;
                                 }
                         }
                         else if(b.data[MAXSIZE - i]<10){
                                 carry = 0;
                         }
                 }
                 if(carry==1){
                         b.size++;
                         b.data[MAXSIZE-b.size] = 1;
                 }
                 if(b.size<=MAXSIZE) return true;
                 else return false;
        }
	return false;
}

