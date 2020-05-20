#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;

class nazwisko{
	ifstream plik1;
	ofstream plik2;
	public:
	nazwisko();
	~nazwisko();
	
	void check();
		
};

	nazwisko::nazwisko(){
		plik1.open("c:\\od.txt");
		plik2.open("c:\\do.json");
	}
	
	void nazwisko::check(){
		bool first = true;
		regex regular("[A-Z][a-z]+-[A-Z][a-z]+");
		string input;
		plik2<<"["<<endl;
		while(!plik1.eof()){
			plik1>>input;
			if(regex_match(input, regular)){
				cout<<input<<endl;
				if(first){
					plik2<<"{\"nazwisko_podwojne\":\""<<input<<"}";
					first = false;
				} else {
					plik2<<","<<endl;
					plik2<<"{\"nazwisko_podwojne\":\""<<input<<"}";
				}
				
			}
		}
		plik2<<endl<<"]";
	}
	
	nazwisko::~nazwisko(){
		plik1.close();
		plik2.close();
	}


int main(int argc, char** argv) {
	
	nazwisko n1;
	n1.check();
	return 0;
}
