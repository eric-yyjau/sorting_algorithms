#include <cstdio>
#include <iostream>
#include <fstream>

#include "parser.h"

//#define mergesort
//#define insertionsort
//#define selectionsort

#ifndef NDEBUG

#endif // NDEBUG

void print_string( AlgParser& p );
void do_insertionsort( AlgParser& p);
void print_insertionsort( AlgParser& p);
void print_sort_string( AlgParser& p);
void print_sort_appearance_vector (AlgParser& p);

int main( int argc, char** argv )
{
  if( argc == 3){
        // Declare the functional objects
        AlgParser p;
        AlgTimer t;
        // Pass the arguement 1 as the input file name
        p.Parse( argv[1] );
        cout<<"YES~"<<endl;

        // Start timer
        t.Begin();
        //print the result
        //print without repeat + word order

#ifdef insertionsort
        //insertion sort
        p.initialize_str_sortorder();
        p.my_insertionsort();
        p.output_sort_file( argv[2], 0 );
#endif // insertionsort

        //print_string(p);

#ifdef mergesort
        //print_string(  p );
        p.initialize_str_sortorder();
        cout<<"YES2~"<<endl;
        p.my_mergesort(0, p.QueryTotalStringCount() -1 , 1);
        cout<<"YES3~"<<endl;
        p.calculate_repeat_word();
        //print_string(p);
        //print_string(  p );
        cout<<"YES4~"<<endl;
        p.my_mergesort(0, p.sort_word_appearance.size() -1 , 2);
        p.output_sort_file( argv[2] , 2);
        //print_sort_string(p);
#endif


#ifdef selectionsort
        p.initialize_str_sortorder();
        p.my_selectionsort();
        // p.combine_repeat_word();
        p.calculate_repeat_word();
        p.selectionsort_word_appearance();//unstable
        p.output_sort_file( argv[2] , 2 );
        //p.print_sortorder();
#endif

#ifdef quicksort
        p.initialize_str_sortorder();
        p.my_quicksort(0, p.QueryTotalStringCount(), 1);
        p.calculate_repeat_word();
        //print_sort_appearance_vector(p);
        //print_string(p);
        p.my_quicksort(0, p.sort_word_appearance.size() , 2);
        p.output_sort_file( argv[2] , 2 );
#endif // quicksort

#ifdef heapsort
        //initialize the array
        /*
        int* temp;
        str_heapsort = new int[p.QueryTotalStringCount() ];//
        for ( int i=0; i<p.QueryTotalStringCount() ; i++){
            str_heapsort[i]=i;
            //cout<<str_heapsort[i]<<endl;
        }
        */
        p.initialize_str_sortorder();
        //cout<<str_heapsort[0]<<endl;
        p.heap_sort( p.QueryTotalStringCount() , 1 );
        p.calculate_repeat_word();
        p.heap_sort( p.sort_word_appearance.size() , 2 );
        p.output_sort_file( argv[2] , 3 );

        //print_sort_string(p);



#endif // heapsort


    //Display the accumulated time
    cout << "The execution spends " << t.End() << " seconds" << endl;
    return 1;
  }
  else
  {
    cout << "Usage XXXXXsort <input_file_name> <output_file_name>"<<endl;
  }





}

void print_sort_appearance_vector (AlgParser& p){
    for( int i=0 ; i<p.sort_word_appearance.size() ; i++){
        cout<<i<<"= "<<p.sort_word_appearance[i]<<endl;
    }
}


void print_string( AlgParser& p ){
   // Display all strings and line numbers

    for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
    {
        cout << p.QueryString(i) << " " << p.QueryLineNumber(i) << " " << p.QueryWordOrder(i)<< endl;
    }

}

void do_insertionsort( AlgParser& p){
    p.initialize_str_sortorder();
    p.my_insertionsort();
}

void print_insertionsort( AlgParser& p){
    for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
    {
        // cout<<"get"<<endl;
        int temp = p.str_sortorder[i];
        if( p.repeat( temp ) == false)
        {
            cout << p.QueryString(temp)  << " ";
            p.print_repeat_word_order( temp );
            cout << endl;
        }

    }
}

void print_sort_string( AlgParser& p){
        for( int i = 0 ; i < p.QueryTotalStringCount() ; i++ )
        {
            // cout<<"get"<<endl;
            int temp = p.str_sortorder[i];
            cout << p.QueryString(temp)  << " " << p.QueryLineNumber(temp)
                <<  " " << p.QueryWordOrder(temp) << endl;
        }
}

