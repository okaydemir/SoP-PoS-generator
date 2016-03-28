#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[]){

    if(!(argc>=2)){
        printf("Usage: ./possop infile outfile(optional)\n");
        return 0;
    }

    int N,K;
    vector<string> s;
    string x;
    vector<vector <bool> > table;
    bool sop;
    string sop_f="";
    string pos_f="";

    int y;
ifstream myfile (argv[1]);
    if (myfile.is_open())
    {
    	myfile >> N;
    	for(int i=0;i<N;i++){
    		myfile >> x;
    		s.push_back(x);
    	}
    	myfile >> K;

    	
    	for(int i=0;i<K;i++){
    		  vector <bool> temp;
    		for(int i=0;i<N+1;i++){
    		myfile >> y;
    		//cout << y << " ";
    		temp.push_back(y);

    	}
    	//cout << endl;

    	table.push_back(temp);

    	}

    }
    else cout << "Unable to open file\n";
//cout << table[0][N];

   for(size_t i=0;i<table.size();i++){

    	if(table[i][N]){
    		sop=true;
    	}else{sop=false;}

if(sop){

    	
    		for(size_t j=0;j<N;j++){

    			if (table[i][j])
    			sop_f+= s[j];
    		else
    			sop_f+= s[j] + "'";
    		}
    		sop_f+= "+";
    		}else{
pos_f+="(";
for(size_t j=0;j<N;j++){

    			if (table[i][j])
    			pos_f+= s[j] + "'" + "+";
    		else
    			pos_f+= s[j] + "+";

    	}
pos_f.erase(pos_f.end()-1);
pos_f+=")";


}

    }


sop_f.erase(sop_f.end()-1);

cout << "Product of sums: " << endl << pos_f << endl << "Sum of products: " << endl << sop_f << endl;
    if(argc==3){

    ofstream ofile;//start file stream
      ofile.open (argv[2]);
      ofile  << "Product of sums: " << endl << pos_f << endl << "Sum of products: " << endl << sop_f ;//write to file
      ofile.close();
}

}