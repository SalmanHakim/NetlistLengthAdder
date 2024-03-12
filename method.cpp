#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct netlist
{
    string name;
    double length;
};



vector<netlist> read_file(string fname) 
{ 
    
    
    // File pointer 
    ifstream fin; 

    //variable declaration
    vector<netlist> net;
    string line;
  
    // Open an existing file 
    fin.open(fname, ios::in); 
    
    if (!fin.is_open()) {
        cerr<<"Error! Cannot open file: "<<fname<<endl;
        return net;
    }

    while (getline(fin, line))
    {
        string n;
        double l;
        stringstream ss(line);

        if (getline(ss, n, ',') && ss >> l) {
            net.push_back({n, l});
        }
        else {
            cerr<<"Error! Unable to read the line: "<<line<<endl;
        }
    }

    return net;
}

int process_data(vector<netlist>& net)
{

    int size = net.size();
    int j = 0;

    netlist temp[size];


    for (size_t i = 0; i < size-1; i++) {
        if (net[i].name == net[i+1].name) {
            net[i+1].length = net[i+1].length + net[i].length;
        }
        
        else if (net[i].name != net[i+1].name) {
            temp[j].name = net[i].name;
            temp[j].length = net[i].length;
            j++;
        }
    }
    temp[j++] = net[size-1];

    for (size_t i = 0; i < j; i++)
    {
        net[i] = temp[i];
    }

    return j;
}
    

void write_file(string fname, const vector<netlist>& net, int n)
{
    ofstream fout;
    fout.open(fname);
    if (!fout.is_open()) {
        cerr<<"Error! Cannot open file: "<<fname<<endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        fout<<net[i].name<<", "<<net[i].length<<"\"\n";
    }
    fout.close();
    cout<<"New file created: "<<fname<<endl;
}

