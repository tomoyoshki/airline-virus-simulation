#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;
using std::ifstream;
using std::stringstream;

std::string file_to_string(const std::string & filename) {
	std::ifstream text(filename);
	
	std::stringstream strStream;
	if (text.is_open()) {
		strStream << text.rdbuf();
	}

	return strStream.str();
}

std::vector<std::string> file_to_vector(const std::string & filename) {
	std::ifstream text(filename);
	std::vector<std::string> out;

	if (text.is_open()) {
		std::istream_iterator<std::string> iter(text);
		while (!text.eof()) {
			out.push_back(*iter);
			++iter;
		}
	}

	return out;
} 

vector<string> manipulate_string(string s) {
    vector<string>result;
    string token = "\n";
    while(s.size()){
        size_t index = s.find(token);
        if(index!=string::npos){
            result.push_back(s.substr(0,index));
            s = s.substr(index+token.size());
        }else{
            if(s == "") {

            } else {
                result.push_back(s);
            }
            s = "";
        }
    }
    return result;
}

vector<string> manipulate_string(string s, string token) {
    vector<string>result;
    while(s.size()){
        size_t index = s.find(token);
        if(index!=string::npos){
            result.push_back(s.substr(0,index));
            s = s.substr(index+token.size());
            if(s.size()==0)result.push_back(s);
        }else{
            result.push_back(s);
            s = "";
        }
    }

    // Delete time zone to source data that we do not need
    result.assign(result.begin(), result.begin()+8);

    // Delete Country, IATA, ICAO
    for(int i = 5; i >= 3; i--) {
      result.erase(result.begin()+i);
    }
    
    return result;
}

vector<string> manipulate_route(string s, string token) {
    vector<string>result;
    while(s.size()){
        size_t index = s.find(token);
        if(index!=string::npos){
            result.push_back(s.substr(0,index));
            s = s.substr(index+token.size());
            if(s.size()==0)result.push_back(s);
        }else{
            result.push_back(s);
            s = "";
        }
    }

    // Delete info after destination airport id
    result.assign(result.begin(), result.begin()+6);

    
    return result;
}
