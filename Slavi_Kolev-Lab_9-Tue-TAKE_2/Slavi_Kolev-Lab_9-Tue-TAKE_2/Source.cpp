#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int max_num_coord = 40;
//int num_coord = 0; //global var okay? // http://stackoverflow.com/questions/3749660/how-to-resize-array-in-c
										// Array size is static; use std::vector instead
struct state{
	string code;
	int lati[max_num_coord];
	int longi[max_num_coord];
};



state get_single_state(string query_code){
	state current_code;
	state result;
	
	ifstream fin("map.txt");
	
	if (fin.fail()){
		cerr << "File Open Error \n";
		exit(1);
	}
	
	while (true){
		fin >> current_code.code;
		if (current_code.code == query_code){
			result.code = query_code;
			for (int coord = 0; coord <= max_num_coord; coord++){
				fin >> result.longi[coord] >> result.lati[coord];
				if (result.longi[coord] == -1 || result.lati[coord] == -1){ //leave as is, add --> if (coord is -1) don't draw point
					for (int coord_unused = coord + 1; coord_unused < max_num_coord; coord_unused++){
						result.longi[coord_unused] = 0;
						result.lati[coord_unused] = 0;
					}
					fin.close(); //careful
					break;
				}
			}
			break;
		}
		if (fin.fail()){
			//incorrect code handler
			break;
		}
	}

	return result;
}

void convert_single_state(){

}

void draw_star(){
	//copy from lab 2 or 3
}

void draw_single_capital(){

}

void draw_single_state(){

}

void draw_by_code(){
	//ALL support
	//incorrect name handling
}

void report_nearest_capital(){

}

void geo_quiz(){

}

void debug(int n){ //function testing
	state test_state = get_single_state("FL");
	cout << test_state.code << " cmon now" << "\n";
	cout << "Longi Lati" << "\n";
	cout << "----------" << "\n";
	for (int coord = 0; coord < max_num_coord; coord++){
		cout << test_state.longi[coord] << " " << test_state.lati[coord] << "\n";
	}
	if (n > 1)
		debug(n - 1);
}

int main(){
	debug(1);
}