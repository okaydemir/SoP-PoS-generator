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

    int N,K; // N = number of variables, K=number of rows of truth table
    vector<string> s; // variable names vector    
    vector<vector <bool> > table; // truth table
    string sop_f="";
    string pos_f="";


ifstream myfile (argv[1]);
    if (myfile.is_open())
    {


        //reading first line that has #ofvar,varnames,#of rows of truth table
    	myfile >> N;
    	for(int i=0;i<N;i++){
            string temp;
    		myfile >> temp;
    		s.push_back(temp);
    	}
    	myfile >> K;

    	

        //reading truth table and storing it
    	for(int i=0;i<K;i++){
    		  vector <bool> temp;
    		for(int i=0;i<N+1;i++){
                bool intemp;
    		myfile >> intemp;
    		temp.push_back(intemp);

    	}

    	table.push_back(temp);

    	}

    }
    else cout << "Unable to open file\n";


    bool sop; //is current row related with SoP

   for(size_t i=0;i<table.size();i++){

    	if(table[i][N]){ //for each row if output is 1
    		sop=true; // we shall use that row for SoP
    	}else{sop=false;} // else for PoS

if(sop){

    	
    		for(size_t j=0;j<N;j++){

    			if (table[i][j])
    			sop_f+= s[j]; // if variable's value is 1 add it to outstring directly
    		else
    			sop_f+= s[j] + "'"; // if 0 add complement
    		}
    		sop_f+= "+"; // put plus sign after a column is processed and a single product is added to the SoP string
    		}else{ // if PoS
pos_f+="("; // Product of Sums therefore parentheses
for(size_t j=0;j<N;j++){

    			if (table[i][j])
    			pos_f+= s[j] + "'" + "+"; //reverse situation of SoP
    		else
    			pos_f+= s[j] + "+";

    	}
pos_f.erase(pos_f.end()-1); // remove the plus sign after last element
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