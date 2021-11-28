#include <bits/stdc++.h>
#include "Treap.h"
#include "SortedArray.h"
#include "SkipList.h"
using namespace std;

int main(int argc, char* argv[]){
    string method = "SkipList" ;
    clock_t insert_begin, insert_end, search_begin, search_end;
    int k = atoi(argv[1]);
    long long a = pow(2,k);
    long long *insert_arr = new long long[a]{0};
    long long *search_arr = new long long[100000]{0};
    float p = atof(argv[3]);
    long long count = 0; // skip_list additional copy
    int level = 0; //skip_list number of list

    //Insert_arr
    for(long long i=0;i<a;i++){
        insert_arr[i] = (rand()%a)+1;
//        cout << arr[i] << " " ;
    }

    //Search_arr
    for(long long i=0;i<100000;i++){
        search_arr[i] = (rand()%a)+1;
    }

    
    if(method == "Treap"){
        Treap treap(NULL);
        //Insert
        insert_begin = clock();
        for(long long i=0;i<a;i++){
            treap.Insert(insert_arr[i]);
        }
        insert_end = clock();

        //Search
        search_begin = clock();
        for(long long i=0;i<100000;i++){
            treap.Search(search_arr[i]);
        }
        search_end = clock();
    }
    else if(method == "SortedArray"){
        SortedArray sorted_array(a);
        //Insert
        insert_begin = clock();
        for(long long i=0;i<a;i++){
            sorted_array.Insert(insert_arr[i]);
        }
        insert_end = clock();

        //Search 
        search_begin = clock();
        for(long long i=0;i<100000;i++){
            int location = sorted_array.binarySearch(search_arr[i], 0, a-1);
        }
        search_end = clock();
    }
    else if(method == "SkipList"){
        SkipList skip_list(200, p);

        //Insert
        insert_begin = clock();
        for(long long i=0;i<a;i++){
            skip_list.Insert(insert_arr[i]);
        }
        insert_end = clock();
        count = skip_list.count;
        level = skip_list.getlevel();
        
        //Search
        search_begin = clock();
        for(long long i=0;i<100000;i++){
            skip_list.Search(search_arr[i]);
        }
        search_end = clock();
    }

    double insert_time = double(insert_end - insert_begin) / double(CLOCKS_PER_SEC);
    double search_time = double(search_end - search_begin) / double(CLOCKS_PER_SEC);
    delete [] insert_arr;
    delete [] search_arr;

    char* filename = new char[20];
    strcpy(filename,argv[2]);
    ofstream file;

    file.open(filename, ios_base::app);
    file << method << ",";
    file << k << ",";
    file << a << ",";
    if(method == "SkipList"){
        file << p << ","; //probability
        file << double(count) / double(a) << ",";//average of additional copy
        file << level << ",";//number of list
    }
    file << insert_time << "," ;
    file << search_time << endl;

    file.close();
    return 0;
}
