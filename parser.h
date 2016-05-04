#ifndef _DEFINE_PARSER_
#define _DEFINE_PARSER_

#include <fstream>
#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <assert.h>

#define output_1
//#define mergesort
//#define selectionsort

using namespace std;

struct sortint
{
    bool operator() (const int & i1 , const int& i2)
    {
        return i1 < i2 ;
    }
};


class AlgString
{
public:
    string m_string;
    int m_line_number;
    int m_word_number;
    int m_appearance_count;
    //If not repeat = false
    //If repeat = true
    bool m_repeat;

    AlgString(void);
    AlgString( const string& set_string, const int& set_line_number, const int& set_word_number );
    void print_repeat_word_order();

    vector <int> repeat_word_order;

private:

};

class AlgParser
{
public:
    AlgParser(void);
    // Specify the parsing file name and then parse the file
    void Parse( const string& input_file_name );
    // Return the total number of strings in the file
    int QueryTotalStringCount(void);
    // Return the ith string in the file
    string QueryString(const int& ith);
    // Return the line number of the ith string in the file
    int QueryLineNumber(const int& ith);
    // Return the word order of the ith string in the corresponding line
    int QueryWordOrder( const int& ith );
//TODO::
    void initialize_str_sortorder();
#ifdef output_1
    void output_sort_file(const char* output_file_name, int type  );
#endif // output_1
    void output_sort_file(const char* output_file_name, int* A  );

    void my_insertionsort();
    vector <int> str_sortorder;
    bool repeat(int i);
    void print_sortorder();




    void my_mergesort( int p , int r , int type);

    void my_merge ( int p , int q , int r , int type );

//quicksort
    void my_quicksort(int p, int r, int type);
    int my_partition( int p, int r, int type);


//quicksort end

#ifdef selectionsort
void my_selectionsort();


#endif

//heapsort
    void build_max_heap( int heap_size , int type);
    void max_heapify( int i, int heap_size, int type);
    void heap_sort( int heap_size, int type);
//heapsort end

    void calculate_repeat_word();
    void calculate_repeat_word_heap( int*A,int heap_size );
    void selectionsort_word_appearance();
    vector <int> sort_word_appearance;

    void combine_repeat_word();


    void print_repeat_word_order(int i);

private:
    int stringcmp(int a, int b);
    int appearance_cmp( int a , int b);

};

class AlgTimer
{
public:
    long begin_clock;
    AlgTimer(void);
    // Strat the timer
    void Begin(void);
    // Return the accumulated time in seconds
    double End(void);

};

#endif
