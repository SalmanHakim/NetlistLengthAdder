#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "method.cpp"

using namespace std;

int main()
{
    string ifname, ofname;
    cout<<"Enter the input file name: ";
    cin>>ifname;

    cout<<"Enter the output file name: ";
    cin>>ofname;

    vector<netlist> net = read_file(ifname);

    int n = process_data(net);

    write_file(ofname, net, n);
}